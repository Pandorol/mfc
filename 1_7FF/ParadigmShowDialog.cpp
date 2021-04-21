// ParadigmShowDialog.cpp : implementation file
//

#include "stdafx.h"
#include "1_7FF.h"
#include "CAClistFile.h"
#include "1_7FFDoc.h"
#include "ParadigmShowDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CParadigmShowDialog dialog


CParadigmShowDialog::CParadigmShowDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CParadigmShowDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CParadigmShowDialog)
	//}}AFX_DATA_INIT
}


void CParadigmShowDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CParadigmShowDialog)
	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CParadigmShowDialog, CDialog)
	//{{AFX_MSG_MAP(CParadigmShowDialog)
	ON_WM_PAINT()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParadigmShowDialog message handlers

BOOL CParadigmShowDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	ShowWindow(SW_SHOWMAXIMIZED);
	cfile.Readtols();
	if(cfile.ls.empty())
	{
		OnOK();
	}
	order = 0;
	WriteSwitch = 1;
	Doc = (CMy1_7FFDoc*)(((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument());
	Doc->ConnectDevice();
	m_pthread = AfxBeginThread(WriteData,this,THREAD_PRIORITY_NORMAL,0,0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CParadigmShowDialog::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect rect;
	GetClientRect(rect);
	dc.FillSolidRect(rect,RGB(0,0,0));
	list<pac>::iterator it = cfile.ls.begin();
	advance(it,order);
	CString str;
	str.Format("%s",it->accontext);
	tag = it->tag;
	CFont font;
	font.CreatePointFont(1000,TEXT("Arial"));
	dc.SelectObject(&font);
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(30, 30, 30));
	//dc.TextOut(850, 400, str);
	dc.DrawText(str, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	SetTimer(order,(it->endtime-it->starttime)*1000,NULL);
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}

void CParadigmShowDialog::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(order);
	order++;
	if(order>=cfile.ls.size())
	{
		WriteSwitch = 0;
		WaitForSingleObject(m_pthread,INFINITE);
		OnOK();
	}
	Invalidate();
	CDialog::OnTimer(nIDEvent);
}
UINT CParadigmShowDialog::WriteData(LPVOID lparam)
{
	CParadigmShowDialog* Cps = (CParadigmShowDialog*)lparam;
	short i,j,ccounts = 0;
	short channels[32];
	for(i=0;i<32;i++)
	{
		if(Cps->Doc->vchannel[i]==1)
		{
			channels[ccounts++] = i;
		}
	}
	short * pBuffer;short* copyBuffer;
	pBuffer = (short*)malloc(660);
	copyBuffer = (short*)malloc(660);
	ULONG nCounts;
	CString str;
	CFile m_file;
	CTime cm;
	cm = CTime::GetCurrentTime();
	str = cm.Format("%Y%m%d%H%M%S.txt");
	str.Format("%s",str);
	//str=".\\collection\\"+str;
	m_file.Open(str,CFile::modeCreate|CFile::modeWrite);
	Cps->Doc->GetReadDatas(pBuffer,&nCounts);
	memcpy((void*)copyBuffer,(void*)pBuffer,660);
	LARGE_INTEGER m_liPerfFreq,m_liPerfStart,m_liPerfEnd;
	QueryPerformanceFrequency(&m_liPerfFreq); QueryPerformanceCounter(&m_liPerfStart);
	while(Cps->WriteSwitch)
	{
		Cps->Doc->GetReadDatas(pBuffer,&nCounts);//memcmp(copyBuffer,pBuffer,660)
		QueryPerformanceCounter(&m_liPerfEnd);
		while((memcmp(copyBuffer,pBuffer,660)!=0&&Cps->WriteSwitch)||(((double)(m_liPerfEnd.QuadPart-m_liPerfStart.QuadPart)/(double)m_liPerfFreq.QuadPart)>=0.010&&Cps->WriteSwitch))
		{
			QueryPerformanceCounter(&m_liPerfStart);
			memcpy((void*)copyBuffer,(void*)pBuffer,660);
			
			for(i=0;i<10;i++)
			{
				for(j=0;j<ccounts;j++)
				{
					//pBuffer[i*33+channels[j]];
					str.Format(" %d",pBuffer[i*33+channels[j]]);
					m_file.Write(str,strlen(str));
				}
				str.Format(" %d",Cps->tag);
				m_file.Write(str,strlen(str));
				m_file.Write("\r\n",strlen("\r\n"));
			}
			
		}

	}
	free(pBuffer);free(copyBuffer);m_file.Close();
	return 0;
}