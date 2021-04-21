// ImpedanceDetectiveDialog.cpp : implementation file
//

#include "stdafx.h"
#include "1_7FF.h"
#include "1_7FFDoc.h"
#include "EEGAMP.h"
#include "ImpedanceDetectiveDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImpedanceDetectiveDialog dialog


CImpedanceDetectiveDialog::CImpedanceDetectiveDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CImpedanceDetectiveDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImpedanceDetectiveDialog)
	//}}AFX_DATA_INIT
	int i;
	for(i=0;i<32;i++)
	{
		imp[i]=0;
	}
	Doc = (CMy1_7FFDoc*)(((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument());
	DetectiveSwitch = 0;
}


void CImpedanceDetectiveDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImpedanceDetectiveDialog)
	
	//}}AFX_DATA_MAP
	//£¨"Fp1","Fp2","F3","F4","C3","C4","P3","P4","O1","O2","F7","F8",
//"T3","T4","T5","T6","Fz","Cz","Pz","Fc3","Fc4","Cp3","Cp4","Ft7","Ft8",
//"Tp7","Tp8","FCz","CPz","Oz","Pg1","Pg2"£©

	DDX_Text(pDX,IDC_IMP_Fp1,imp[0]);DDX_Text(pDX,IDC_IMP_Fp2,imp[1]);
	DDX_Text(pDX,IDC_IMP_F3,imp[2]);DDX_Text(pDX,IDC_IMP_F4,imp[3]);
	DDX_Text(pDX,IDC_IMP_C3,imp[4]);DDX_Text(pDX,IDC_IMP_C4,imp[5]);
	DDX_Text(pDX,IDC_IMP_P3,imp[6]);DDX_Text(pDX,IDC_IMP_P4,imp[7]);
	DDX_Text(pDX,IDC_IMP_O1,imp[8]);DDX_Text(pDX,IDC_IMP_O2,imp[9]);
	DDX_Text(pDX,IDC_IMP_F7,imp[10]);DDX_Text(pDX,IDC_IMP_F8,imp[11]);
	DDX_Text(pDX,IDC_IMP_T3,imp[12]);DDX_Text(pDX,IDC_IMP_T4,imp[13]);
	DDX_Text(pDX,IDC_IMP_T5,imp[14]);DDX_Text(pDX,IDC_IMP_T6,imp[15]);
	DDX_Text(pDX,IDC_IMP_Fz,imp[16]);DDX_Text(pDX,IDC_IMP_Cz,imp[17]);
	DDX_Text(pDX,IDC_IMP_Pz,imp[18]);DDX_Text(pDX,IDC_IMP_Fc3,imp[19]);
	DDX_Text(pDX,IDC_IMP_Fc4,imp[20]);DDX_Text(pDX,IDC_IMP_Cp3,imp[21]);
	DDX_Text(pDX,IDC_IMP_Cp4,imp[22]);DDX_Text(pDX,IDC_IMP_Ft7,imp[23]);
	DDX_Text(pDX,IDC_IMP_Ft8,imp[24]);DDX_Text(pDX,IDC_IMP_Tp7,imp[25]);
	DDX_Text(pDX,IDC_IMP_Tp8,imp[26]);DDX_Text(pDX,IDC_IMP_Fcz,imp[27]);
	DDX_Text(pDX,IDC_IMP_Cpz,imp[28]);DDX_Text(pDX,IDC_IMP_Oz,imp[29]);
	DDX_Text(pDX,IDC_IMP_Pg1,imp[30]);DDX_Text(pDX,IDC_IMP_Pg2,imp[31]);
}


BEGIN_MESSAGE_MAP(CImpedanceDetectiveDialog, CDialog)
	//{{AFX_MSG_MAP(CImpedanceDetectiveDialog)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_START_DETECTIVE, OnStartDetective)
	ON_BN_CLICKED(IDC_STOP_DETECTIVE, OnStopDetective)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_UPDATEDATA, OnMyUpdateData)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImpedanceDetectiveDialog message handlers
UINT CImpedanceDetectiveDialog::RefreashData(LPVOID lparam)
{
	CImpedanceDetectiveDialog* Cimp = (CImpedanceDetectiveDialog*)lparam;
	short * pBuffer,*copyBuffer;
	pBuffer = (short*)malloc(660);
	copyBuffer = (short*)malloc(660);
	ULONG nCounts;
	short i;
	Cimp->Doc->GetReadDatas(pBuffer,&nCounts);
	memcpy((void*)copyBuffer,(void*)pBuffer,660);
	while(Cimp->DetectiveSwitch)
	{
		Cimp->Doc->GetReadDatas(pBuffer,&nCounts);
		while(memcmp(copyBuffer,pBuffer,660)!=0&&Cimp->DetectiveSwitch)
		{
			memcpy((void*)copyBuffer,(void*)pBuffer,660);
			for(i=0;i<32;i++)
			{
				Cimp->imp[i] = pBuffer[i]*2;
			}
			//Cimp->Refresh();
			//Cimp->SendMessage(WM_UPDATEDATA, FALSE)
			Cimp->SendMessage(WM_UPDATEDATA, false);
			Sleep(10);
		}


		
	}
	free(pBuffer);free(copyBuffer);
	return 0;
}

void CImpedanceDetectiveDialog::OnOk() 
{
	// TODO: Add your control notification handler code here
	OnStopDetective();
	OnOK();
}

BOOL CImpedanceDetectiveDialog::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DestroyWindow();
}

void CImpedanceDetectiveDialog::OnStartDetective() 
{
	// TODO: Add your control notification handler code here
	if(m_pthread == NULL)
	{
		DetectiveSwitch = 1;
		m_pthread = AfxBeginThread(RefreashData,this,THREAD_PRIORITY_NORMAL,0,0);
	}
	
}

void CImpedanceDetectiveDialog::OnStopDetective() 
{
	// TODO: Add your control notification handler code here
	DetectiveSwitch = 0;
	WaitForSingleObject(m_pthread,INFINITE);
}

BOOL CImpedanceDetectiveDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	STRU_PARAM m_param;
	m_param.nSenseDegree = 0;
	m_param.nGateOfJam = 127;m_param.nHightFre = 50;m_param.nHold1 = 0;
	m_param.nHold2 = 0;m_param.nModeOfSign = 2;m_param.nTimeConstant = 30;
	m_param.nWorkFre = 50;
	Doc->SetParam(&m_param);
	m_pthread = NULL;
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
LRESULT CImpedanceDetectiveDialog::OnMyUpdateData(WPARAM wParam, LPARAM lParam)
{
	UpdateData(wParam);
    return 0;
}

void CImpedanceDetectiveDialog::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	OnStopDetective();
	CDialog::OnClose();
}
