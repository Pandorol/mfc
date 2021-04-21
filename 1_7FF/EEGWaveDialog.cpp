// EEGWaveDialog.cpp : implementation file
//

#include "stdafx.h"
#include "1_7FF.h"
#include "1_7FFDoc.h"
#include "DrawPand.h"
#include "EEGWaveDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEEGWaveDialog dialog


CEEGWaveDialog::CEEGWaveDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CEEGWaveDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEEGWaveDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	
}


void CEEGWaveDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEEGWaveDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX,IDC_DRAW0,m_draw[0]);DDX_Control(pDX,IDC_DRAW1,m_draw[1]);DDX_Control(pDX,IDC_DRAW2,m_draw[2]);DDX_Control(pDX,IDC_DRAW3,m_draw[3]);
	DDX_Control(pDX,IDC_DRAW4,m_draw[4]);DDX_Control(pDX,IDC_DRAW5,m_draw[5]);DDX_Control(pDX,IDC_DRAW6,m_draw[6]);DDX_Control(pDX,IDC_DRAW7,m_draw[7]);
	DDX_Control(pDX,IDC_DRAW8,m_draw[8]);DDX_Control(pDX,IDC_DRAW9,m_draw[9]);DDX_Control(pDX,IDC_DRAW10,m_draw[10]);DDX_Control(pDX,IDC_DRAW11,m_draw[11]);
	DDX_Control(pDX,IDC_COMBO1,m_combo_height);DDX_Control(pDX,IDC_COMBO2,m_combo_width);
}


BEGIN_MESSAGE_MAP(CEEGWaveDialog, CDialog)
	//{{AFX_MSG_MAP(CEEGWaveDialog)
	ON_WM_CLOSE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_NEXT_PAGE, OnNextPage)
	ON_BN_CLICKED(IDC_LAST_PAGE, OnLastPage)
	ON_BN_CLICKED(IDC_SWITCHSCALE, OnSwitchscale)
	ON_BN_CLICKED(IDC_COLLECT, OnCollect)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_STOP_COLLECT, OnStopCollect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEEGWaveDialog message handlers

BOOL CEEGWaveDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	ShowWindow(SW_SHOWMAXIMIZED);
	// TODO: Add extra initialization here
	
	d_width = 5000;
	d_height = 400;
	index = 0;
	GetSwitch =1;
	writeSwitch = 0;
	page = 0;
	p_data = (short*)malloc(2*33*7000);
	CString copychannels[]={"Fp1:","Fp2:","F3:","F4:","C3:","C4:","P3:","P4:","O1:","O2:","F7:","F8:",
		"T3:","T4:","T5:","T6:","Fz:","Cz:","Pz:","Fc3:","Fc4;","Cp3:","Cp4:","Ft7:","Ft8:",
		"Tp7:","Tp8;","FCz:","CPz;","Oz:","Pg1;","Pg2;","mark;"};
	int i;
	for(i=0;i<33;i++)
	{
		channelname[i].Format("%s",copychannels[i]);
	}
	for(i=0;i<12;i++)
	{
		m_draw[i].d_height = d_height;
		m_draw[i].d_width = d_width;
	}
	m_combo_height.AddString("50");
	m_combo_height.AddString("100");
	m_combo_height.AddString("200");
	m_combo_height.AddString("300");
	m_combo_height.AddString("500");
	m_combo_height.SetCurSel(0);
	m_combo_width.AddString("3");
	m_combo_width.AddString("5");
	m_combo_width.AddString("7");
	m_combo_width.SetCurSel(1);
	Doc = (CMy1_7FFDoc*)(((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument());
	m_pthread = AfxBeginThread(GetData,this,THREAD_PRIORITY_NORMAL,0,0);
	SetTimer(1,100,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
				  
}

BOOL CEEGWaveDialog::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(p_data)
	{
		free(p_data);
	}
	
	return CDialog::DestroyWindow();
}
UINT CEEGWaveDialog::GetData(LPVOID lparam)
{
	CEEGWaveDialog* CEEG = (CEEGWaveDialog*)lparam;
	short i,j,z,ccounts=0;
	short channels[32];
	for(i=0;i<32;i++)
	{
		if(CEEG->Doc->vchannel[i]==1)
		{
			channels[ccounts++] = i;
		}
	}
	short * pBuffer,*copyBuffer;
	pBuffer = (short*)malloc(660);
	copyBuffer = (short*)malloc(660);
	ULONG nCounts;
	CEEG->Doc->GetReadDatas(pBuffer,&nCounts);
	memcpy((void*)copyBuffer,(void*)pBuffer,660);
	CFile m_file;CString str;CTime cm;
	cm = CTime::GetCurrentTime();
	str = cm.Format("%Y%m%d%H%M%S.txt");
	m_file.Open(str,CFile::modeCreate|CFile::modeWrite);
	LARGE_INTEGER m_liPerfFreq,m_liPerfStart,m_liPerfEnd;
	QueryPerformanceFrequency(&m_liPerfFreq);QueryPerformanceCounter(&m_liPerfStart);
	while(CEEG->GetSwitch)
	{
		CEEG->Doc->GetReadDatas(pBuffer,&nCounts);
		QueryPerformanceCounter(&m_liPerfEnd);
		while(memcmp(copyBuffer,pBuffer,660)!=0&&CEEG->GetSwitch||(((double)(m_liPerfEnd.QuadPart-m_liPerfStart.QuadPart)/(double)m_liPerfFreq.QuadPart)>=0.010&&CEEG->GetSwitch))
		{
			QueryPerformanceCounter(&m_liPerfStart);
			memcpy((void*)copyBuffer,(void*)pBuffer,660);
			for(i=0;i<10;i++)
			{
				z=0;
				for(j=0;j<33;j++)
				{
					CEEG->p_data[CEEG->index*33+j] = pBuffer[i*33+j];
					if(CEEG->writeSwitch)
					{
						if(channels[z] == j)
						{
							str.Format(" %d",pBuffer[i*33+channels[z]]);
							m_file.Write(str,strlen(str));
							z++;
						}
					}
					
				}
				CEEG->index++;
				if(CEEG->index>=CEEG->d_width)
				{CEEG->index%=CEEG->d_width;}
				
				if(CEEG->writeSwitch){m_file.Write("\r\n",strlen("\r\n"));}
				
			}
			
		}
	}
	free(pBuffer);free(copyBuffer);m_file.Close();



	return 0;
}

void CEEGWaveDialog::OnCancel() 
{
	// TODO: Add your control notification handler code here
	StopT();
	OnOK();
}

void CEEGWaveDialog::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	StopT();
	CDialog::OnClose();
}

void CEEGWaveDialog::StopT()
{
	KillTimer(1);
	writeSwitch =0;
	GetSwitch = 0;

	WaitForSingleObject(m_pthread,INFINITE);
}

void CEEGWaveDialog::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	short i,j,ccounts = 0;
	short channels[32];
	for(i=0;i<32;i++)
	{
		if(Doc->vchannel[i]==1)
		{
			channels[ccounts] = i;
			ccounts++;
		}
	}
	int mincounts ;
	if(ccounts>(page+1)*12)
	{
		mincounts = 12;
	}
	else
	{
		mincounts = ccounts- (page)*12;
	}
	for(i=0;i<mincounts;i++)
	{
		for(j=0;j<d_width;j++)
		{
			m_draw[i].title = channelname[channels[page*12+i]];
			m_draw[i].p_data[j] = p_data[33*j+channels[page*12+i]];
			m_draw[i].Invalidate();
		}
		
	}
	CDialog::OnTimer(nIDEvent);
}

void CEEGWaveDialog::OnNextPage() 
{
	// TODO: Add your control notification handler code here
	short i,ccounts = 0;
	for(i=0;i<32;i++)
	{
		if(Doc->vchannel[i]==1)
		{
			ccounts++;
		}
	}
	if(ccounts>(page+1)*12)
	{
		page++;
		//CString str;
		//str.Format("ccounts = %d,page=%d",ccounts,page);
		//MessageBox(str);
	}
}

void CEEGWaveDialog::OnLastPage() 
{
	// TODO: Add your control notification handler code here
	
	if(page>0)
	{
		page--;
	}
}

void CEEGWaveDialog::OnSwitchscale() 
{
	// TODO: Add your control notification handler code here
	CString str;
	short index = m_combo_height.GetCurSel();
	m_combo_height.GetLBText(index,str);
	d_height = atoi(str)*4;
	short i;
	for(i=0;i<12;i++)
	{
		m_draw[i].d_height = d_height;
	}
	index = m_combo_width.GetCurSel();
	m_combo_width.GetLBText(index,str);
	d_width = atoi(str)*1000;
	for(i=0;i<12;i++)
	{
		m_draw[i].d_width = d_width;
	}
}

void CEEGWaveDialog::OnCollect() 
{
	// TODO: Add your control notification handler code here
	writeSwitch =1;
}

void CEEGWaveDialog::OnStopCollect() 
{
	// TODO: Add your control notification handler code here
	writeSwitch =0;
}
