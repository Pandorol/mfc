// OnlineSystem1.cpp : implementation file
//

#include "stdafx.h"
#include "1_7FF.h"
#include "1_7FFDoc.h"

#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#include "OnlineSystem1.h"
#include "TCPIPOperate.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COnlineSystem1 dialog


COnlineSystem1::COnlineSystem1(CWnd* pParent /*=NULL*/)
	: CDialog(COnlineSystem1::IDD, pParent)
{
	//{{AFX_DATA_INIT(COnlineSystem1)
	m_Instruction = _T("");
	//}}AFX_DATA_INIT
	
}


void COnlineSystem1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COnlineSystem1)
	DDX_Control(pDX, IDC_ON1_MOVING_CUBE, m_cube);
	DDX_Text(pDX, IDC_EDIT_INSTRUCTION, m_Instruction);
	//}}AFX_DATA_MAP
	
}


BEGIN_MESSAGE_MAP(COnlineSystem1, CDialog)
	//{{AFX_MSG_MAP(COnlineSystem1)
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_WM_DESTROY()
	ON_WM_CLOSE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_UPDATEDATA_ON1, OnMyUpdateData)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COnlineSystem1 message handlers

//DEL void COnlineSystem1::OnBtnConnectAnalysis() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	/*	CTCPIPOperate tcpip;
//DEL 		tcpip.skt = skt;
//DEL 		if(tcpip.Connect())
//DEL 		{
//DEL 			MessageBox("可连接！");
//DEL 			skt=tcpip.skt;
//DEL 		}
//DEL 		else
//DEL 		{
//DEL 			MessageBox("连接失败！");
//DEL 		}
//DEL 		short pBuffer[5];pBuffer[0]=1;pBuffer[1]=89;
//DEL 		pBuffer[2]=133;pBuffer[3]=-31;pBuffer[4]=41;
//DEL 		tcpip.Sendto((char*)pBuffer,10);*/
//DEL }

BOOL COnlineSystem1::OnInitDialog() 
{
	
	CDialog::OnInitDialog();
	sendSwitch= false;
	recvSwitch = false;
	o_skt=NULL;
	m_pthread_send = NULL;
	m_pthread_recv = NULL;
	Doc = (CMy1_7FFDoc*)(((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument());
	tcpip = (CTCPIPOperate*)malloc(sizeof(CTCPIPOperate));
	if(tcpip->Connect())
	{
		MessageBox("已连接到数据分析工具");
	}
	else
	{
		MessageBox("未连接到数据分析工具");
	}
	
	GetWindowRect(&m_window_rect);
	m_cube_rect.top= m_window_rect.Height()/2;m_cube_rect.left = m_window_rect.Width()/2-25;
	m_cube_rect.bottom = m_cube_rect.top+50;m_cube_rect.right = m_cube_rect.left+50;
	m_cube_posleft = m_cube_rect.left;
	m_cube.MoveWindow(m_cube_rect);
	SetTimer(1,250,NULL);
	//调试区
	/*
	CRect r,r2;
	GetWindowRect(&r);
	//m_cube.GetWindowRect(&r);
	//SCreenToClient(&r);
	CString s;
	r2.top = r.Height()/2;r2.left = r.Width()/2-25;r2.bottom = r2.top+50;;r2.right = r2.left+50;
	r2.left+=100;r2.right+=100;
	s.Format("%d %d",r.Width(),r.Height());
	MessageBox(s);
	//r.left-=100;
	m_cube.MoveWindow(r2);
	*/
	//调试区
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



UINT COnlineSystem1::SendData(LPVOID lparam)
{
	COnlineSystem1 *On1 = (COnlineSystem1*)lparam;
	/*
	short i;
	short ccounts=0;
	short channels[32];
	for(i=0;i<32;i++)
	{
		if(On1->Doc->vchannel[i]==1)
		{
			channels[ccounts++] = i;
		}
	}*/
	short * pBuffer,*copyBuffer;
	pBuffer = (short*)malloc(660);
	copyBuffer = (short*)malloc(660);
	
	ULONG nCounts;
	On1->Doc->GetReadDatas(pBuffer,&nCounts);
	memcpy((void*)copyBuffer,(void*)pBuffer,660);
	LARGE_INTEGER m_liPerfFreq,m_liPerfStart,m_liPerfEnd;
	QueryPerformanceFrequency(&m_liPerfFreq);
	QueryPerformanceCounter(&m_liPerfStart);

	
	while(On1->sendSwitch)
	{
		On1->Doc->GetReadDatas(pBuffer,&nCounts);
		QueryPerformanceCounter(&m_liPerfEnd);
		while(memcmp(copyBuffer,pBuffer,660)!=0&&On1->sendSwitch||(((double)
			(m_liPerfEnd.QuadPart-m_liPerfStart.QuadPart)/(double)m_liPerfFreq.QuadPart)>=0.010&&On1->sendSwitch))
		{
			QueryPerformanceCounter(&m_liPerfStart);
			memcpy((void*)copyBuffer,(void*)pBuffer,660);
			On1->tcpip->Sendto((char*)pBuffer,660);
		}
		
	}
	/*
	int i=0;
	while(i<100)
	{
		On1->Doc->GetReadDatas(pBuffer,&nCounts);
		QueryPerformanceCounter(&m_liPerfEnd);
		while(memcmp(copyBuffer,pBuffer,660)!=0&&On1->sendSwitch||(((double)
			(m_liPerfEnd.QuadPart-m_liPerfStart.QuadPart)/(double)m_liPerfFreq.QuadPart)>=0.010&&On1->sendSwitch))
		{
			QueryPerformanceCounter(&m_liPerfStart);
			memcpy((void*)copyBuffer,(void*)pBuffer,660);
			On1->tcpip->Sendto((char*)pBuffer,660);
			i++;
		}
	}
	*/

	free(pBuffer);free(copyBuffer);
	return 0;
}
UINT COnlineSystem1::RecvData(LPVOID lparam)
{
	
	COnlineSystem1 *On1 = (COnlineSystem1*)lparam;
	while(On1->recvSwitch)
	{
		On1->tcpip->Recvfrom(On1->m_Instruction);
		On1->SendMessage(WM_UPDATEDATA_ON1, false);
		///*指令m_cube坐标修改区
		int instruc = atoi(On1->m_Instruction);
		if(instruc == 1)
		{
			On1->m_cube_posleft+=1;
			if(On1->m_cube_posleft>=On1->m_window_rect.right)
			{
				On1->m_cube_posleft = 0;
			}
		}
		else if(instruc == 2)
		{
			On1->m_cube_posleft-=1;
			if(On1->m_cube_posleft<=0)
			{
				On1->m_cube_posleft = On1->m_window_rect.right;
			}
		}
		else
		{
				
		}
		//*/
	}
	return 0;
}
void COnlineSystem1::OnButtonStart() 
{
	// TODO: Add your control notification handler code here
	if(m_pthread_send == NULL)
	{
		sendSwitch=true;
		m_pthread_send = AfxBeginThread(SendData,this,THREAD_PRIORITY_NORMAL,0,0);
	}
	if(m_pthread_recv == NULL)
	{
		recvSwitch = true;
		m_pthread_recv  =AfxBeginThread(RecvData,this,THREAD_PRIORITY_NORMAL,0,0);
	}

}
void COnlineSystem1::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

void COnlineSystem1::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	StopTransData();
	CDialog::OnClose();
	/*if(sendSwitch)
	{
		sendSwitch=false;
		WaitForSingleObject(m_pthread,INFINITE);
	}*/
}

void COnlineSystem1::StopTransData()
{
	KillTimer(1);
	if(recvSwitch)
	{
		recvSwitch =false;
		WaitForSingleObject(m_pthread_recv,INFINITE);
	}
	if(sendSwitch)
	{
		sendSwitch=false;
		WaitForSingleObject(m_pthread_send,INFINITE);
	}
	
}

//DEL void COnlineSystem1::OnChangeInstruction() 
//DEL {
//DEL 	// TODO: If this is a RICHEDIT control, the control will not
//DEL 	// send this notification unless you override the CDialog::OnInitDialog()
//DEL 	// function and call CRichEditCtrl().SetEventMask()
//DEL 	// with the ENM_CHANGE flag ORed into the mask.
//DEL 	
//DEL 	// TODO: Add your control notification handler code here
//DEL 	
//DEL }
LRESULT COnlineSystem1::OnMyUpdateData(WPARAM wParam, LPARAM lParam)
{
	UpdateData(wParam);
    return 0;
}

void COnlineSystem1::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_cube_rect.left = m_cube_posleft;
	m_cube_rect.right = m_cube_rect.left+50;
	m_cube.MoveWindow(m_cube_rect,true);
	CDialog::OnTimer(nIDEvent);
}
