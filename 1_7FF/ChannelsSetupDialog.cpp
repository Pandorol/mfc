// ChannelsSetupDialog.cpp : implementation file
//

#include "stdafx.h"
#include "1_7FF.h"
#include "1_7FFDoc.h"
#include "ChannelsSetupDialog.h"
#include "EEGAMP.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChannelsSetupDialog dialog


CChannelsSetupDialog::CChannelsSetupDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CChannelsSetupDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChannelsSetupDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CChannelsSetupDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChannelsSetupDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_COMBOHIGHFRE_Fp1, m_highfre[0]);DDX_Control(pDX, IDC_COMBOHIGHFRE_Fp2, m_highfre[1]);DDX_Control(pDX, IDC_COMBOHIGHFRE_F3, m_highfre[2]);DDX_Control(pDX, IDC_COMBOHIGHFRE_F4, m_highfre[3]);
	DDX_Control(pDX, IDC_COMBOHIGHFRE_C3, m_highfre[4]);DDX_Control(pDX, IDC_COMBOHIGHFRE_C4, m_highfre[5]);DDX_Control(pDX, IDC_COMBOHIGHFRE_P3, m_highfre[6]);DDX_Control(pDX, IDC_COMBOHIGHFRE_P4, m_highfre[7]);
	DDX_Control(pDX, IDC_COMBOHIGHFRE_O1, m_highfre[8]);DDX_Control(pDX, IDC_COMBOHIGHFRE_O2, m_highfre[9]);DDX_Control(pDX, IDC_COMBOHIGHFRE_F7, m_highfre[10]);DDX_Control(pDX, IDC_COMBOHIGHFRE_F8, m_highfre[11]);
	DDX_Control(pDX, IDC_COMBOHIGHFRE_T3, m_highfre[12]);DDX_Control(pDX, IDC_COMBOHIGHFRE_T4, m_highfre[13]);DDX_Control(pDX, IDC_COMBOHIGHFRE_T5, m_highfre[14]);DDX_Control(pDX, IDC_COMBOHIGHFRE_T6, m_highfre[15]);
	DDX_Control(pDX, IDC_COMBOHIGHFRE_Fz, m_highfre[16]);DDX_Control(pDX, IDC_COMBOHIGHFRE_Cz, m_highfre[17]);DDX_Control(pDX, IDC_COMBOHIGHFRE_Pz, m_highfre[18]);DDX_Control(pDX, IDC_COMBOHIGHFRE_Fc3, m_highfre[19]);
	DDX_Control(pDX, IDC_COMBOHIGHFRE_Fc4, m_highfre[20]);DDX_Control(pDX, IDC_COMBOHIGHFRE_Cp3, m_highfre[21]);DDX_Control(pDX, IDC_COMBOHIGHFRE_Cp4, m_highfre[22]);DDX_Control(pDX, IDC_COMBOHIGHFRE_Ft7, m_highfre[23]);
	DDX_Control(pDX, IDC_COMBOHIGHFRE_Ft8, m_highfre[24]);DDX_Control(pDX, IDC_COMBOHIGHFRE_Tp7, m_highfre[25]);DDX_Control(pDX, IDC_COMBOHIGHFRE_Tp8, m_highfre[26]);DDX_Control(pDX, IDC_COMBOHIGHFRE_Fcz, m_highfre[27]);
	DDX_Control(pDX, IDC_COMBOHIGHFRE_Cpz, m_highfre[28]);DDX_Control(pDX, IDC_COMBOHIGHFRE_Oz, m_highfre[29]);DDX_Control(pDX, IDC_COMBOHIGHFRE_Pg1, m_highfre[30]);DDX_Control(pDX, IDC_COMBOHIGHFRE_Pg2, m_highfre[31]);
	DDX_Control(pDX, IDC_COMBOWORKFRE_Fp1, m_workfre[0]);DDX_Control(pDX, IDC_COMBOWORKFRE_Fp2, m_workfre[1]);DDX_Control(pDX, IDC_COMBOWORKFRE_F3, m_workfre[2]);DDX_Control(pDX, IDC_COMBOWORKFRE_F4, m_workfre[3]);
	DDX_Control(pDX, IDC_COMBOWORKFRE_C3, m_workfre[4]);DDX_Control(pDX, IDC_COMBOWORKFRE_C4, m_workfre[5]);DDX_Control(pDX, IDC_COMBOWORKFRE_P3, m_workfre[6]);DDX_Control(pDX, IDC_COMBOWORKFRE_P4, m_workfre[7]);
	DDX_Control(pDX, IDC_COMBOWORKFRE_O1, m_workfre[8]);DDX_Control(pDX, IDC_COMBOWORKFRE_O2, m_workfre[9]);DDX_Control(pDX, IDC_COMBOWORKFRE_F7, m_workfre[10]);DDX_Control(pDX, IDC_COMBOWORKFRE_F8, m_workfre[11]);
	DDX_Control(pDX, IDC_COMBOWORKFRE_T3, m_workfre[12]);DDX_Control(pDX, IDC_COMBOWORKFRE_T4, m_workfre[13]);DDX_Control(pDX, IDC_COMBOWORKFRE_T5, m_workfre[14]);DDX_Control(pDX, IDC_COMBOWORKFRE_T6, m_workfre[15]);
	DDX_Control(pDX, IDC_COMBOWORKFRE_Fz, m_workfre[16]);DDX_Control(pDX, IDC_COMBOWORKFRE_Cz, m_workfre[17]);DDX_Control(pDX, IDC_COMBOWORKFRE_Pz, m_workfre[18]);DDX_Control(pDX, IDC_COMBOWORKFRE_Fc3, m_workfre[19]);
	DDX_Control(pDX, IDC_COMBOWORKFRE_Fc4, m_workfre[20]);DDX_Control(pDX, IDC_COMBOWORKFRE_Cp3, m_workfre[21]);DDX_Control(pDX, IDC_COMBOWORKFRE_Cp4, m_workfre[22]);DDX_Control(pDX, IDC_COMBOWORKFRE_Ft7, m_workfre[23]);
	DDX_Control(pDX, IDC_COMBOWORKFRE_Ft8, m_workfre[24]);DDX_Control(pDX, IDC_COMBOWORKFRE_Tp7, m_workfre[25]);DDX_Control(pDX, IDC_COMBOWORKFRE_Tp8, m_workfre[26]);DDX_Control(pDX, IDC_COMBOWORKFRE_Fcz, m_workfre[27]);
	DDX_Control(pDX, IDC_COMBOWORKFRE_Cpz, m_workfre[28]);DDX_Control(pDX, IDC_COMBOWORKFRE_Oz, m_workfre[29]);DDX_Control(pDX, IDC_COMBOWORKFRE_Pg1, m_workfre[30]);DDX_Control(pDX, IDC_COMBOWORKFRE_Pg2, m_workfre[31]);
	DDX_Control(pDX, IDC_COMBOTIMEC_Fp1, m_timec[0]);DDX_Control(pDX, IDC_COMBOTIMEC_Fp2, m_timec[1]);DDX_Control(pDX, IDC_COMBOTIMEC_F3, m_timec[2]);DDX_Control(pDX, IDC_COMBOTIMEC_F4, m_timec[3]);
	DDX_Control(pDX, IDC_COMBOTIMEC_C3, m_timec[4]);DDX_Control(pDX, IDC_COMBOTIMEC_C4, m_timec[5]);DDX_Control(pDX, IDC_COMBOTIMEC_P3, m_timec[6]);DDX_Control(pDX, IDC_COMBOTIMEC_P4, m_timec[7]);
	DDX_Control(pDX, IDC_COMBOTIMEC_O1, m_timec[8]);DDX_Control(pDX, IDC_COMBOTIMEC_O2, m_timec[9]);DDX_Control(pDX, IDC_COMBOTIMEC_F7, m_timec[10]);DDX_Control(pDX, IDC_COMBOTIMEC_F8, m_timec[11]);
	DDX_Control(pDX, IDC_COMBOTIMEC_T3, m_timec[12]);DDX_Control(pDX, IDC_COMBOTIMEC_T4, m_timec[13]);DDX_Control(pDX, IDC_COMBOTIMEC_T5, m_timec[14]);DDX_Control(pDX, IDC_COMBOTIMEC_T6, m_timec[15]);
	DDX_Control(pDX, IDC_COMBOTIMEC_Fz, m_timec[16]);DDX_Control(pDX, IDC_COMBOTIMEC_Cz, m_timec[17]);DDX_Control(pDX, IDC_COMBOTIMEC_Pz, m_timec[18]);DDX_Control(pDX, IDC_COMBOTIMEC_Fc3, m_timec[19]);
	DDX_Control(pDX, IDC_COMBOTIMEC_Fc4, m_timec[20]);DDX_Control(pDX, IDC_COMBOTIMEC_Cp3, m_timec[21]);DDX_Control(pDX, IDC_COMBOTIMEC_Cp4, m_timec[22]);DDX_Control(pDX, IDC_COMBOTIMEC_Ft7, m_timec[23]);
	DDX_Control(pDX, IDC_COMBOTIMEC_Ft8, m_timec[24]);DDX_Control(pDX, IDC_COMBOTIMEC_Tp7, m_timec[25]);DDX_Control(pDX, IDC_COMBOTIMEC_Tp8, m_timec[26]);DDX_Control(pDX, IDC_COMBOTIMEC_Fcz, m_timec[27]);
	DDX_Control(pDX, IDC_COMBOTIMEC_Cpz, m_timec[28]);DDX_Control(pDX, IDC_COMBOTIMEC_Oz, m_timec[29]);DDX_Control(pDX, IDC_COMBOTIMEC_Pg1, m_timec[30]);DDX_Control(pDX, IDC_COMBOTIMEC_Pg2, m_timec[31]);
	DDX_Control(pDX, IDC_CHECK1,m_check[0]);DDX_Control(pDX, IDC_CHECK2,m_check[1]);DDX_Control(pDX, IDC_CHECK3,m_check[2]);DDX_Control(pDX, IDC_CHECK4,m_check[3]);
	DDX_Control(pDX, IDC_CHECK5,m_check[4]);DDX_Control(pDX, IDC_CHECK6,m_check[5]);DDX_Control(pDX, IDC_CHECK7,m_check[6]);DDX_Control(pDX, IDC_CHECK8,m_check[7]);
	DDX_Control(pDX, IDC_CHECK9,m_check[8]);DDX_Control(pDX, IDC_CHECK10,m_check[9]);DDX_Control(pDX, IDC_CHECK11,m_check[10]);DDX_Control(pDX, IDC_CHECK12,m_check[11]);
	DDX_Control(pDX, IDC_CHECK13,m_check[12]);DDX_Control(pDX, IDC_CHECK14,m_check[13]);DDX_Control(pDX, IDC_CHECK15,m_check[14]);DDX_Control(pDX, IDC_CHECK16,m_check[15]);
	DDX_Control(pDX, IDC_CHECK17,m_check[16]);DDX_Control(pDX, IDC_CHECK18,m_check[17]);DDX_Control(pDX, IDC_CHECK19,m_check[18]);DDX_Control(pDX, IDC_CHECK20,m_check[19]);
	DDX_Control(pDX, IDC_CHECK21,m_check[20]);DDX_Control(pDX, IDC_CHECK22,m_check[21]);DDX_Control(pDX, IDC_CHECK23,m_check[22]);DDX_Control(pDX, IDC_CHECK24,m_check[23]);
	DDX_Control(pDX, IDC_CHECK25,m_check[24]);DDX_Control(pDX, IDC_CHECK26,m_check[25]);DDX_Control(pDX, IDC_CHECK27,m_check[26]);DDX_Control(pDX, IDC_CHECK28,m_check[27]);
	DDX_Control(pDX, IDC_CHECK29,m_check[28]);DDX_Control(pDX, IDC_CHECK30,m_check[29]);DDX_Control(pDX, IDC_CHECK31,m_check[30]);DDX_Control(pDX, IDC_CHECK32,m_check[31]);
}


BEGIN_MESSAGE_MAP(CChannelsSetupDialog, CDialog)
	//{{AFX_MSG_MAP(CChannelsSetupDialog)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_BACKSET, OnBackset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChannelsSetupDialog message handlers

void CChannelsSetupDialog::OnOk() 
{
	// TODO: Add your control notification handler code here
	
	CMy1_7FFDoc* Doc = (CMy1_7FFDoc*)(((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument());
	Doc->ConnectDevice();
	STRU_PARAM m_param;
	m_param.nHold1=0;m_param.nHold2=0;m_param.nGateOfJam = 127;m_param.nModeOfSign = 0;
	short i;short j;CString str;
	for(i=0;i<32;i++)
	{
		m_param.nSenseDegree = i;
		j = m_highfre[i].GetCurSel();
		m_highfre[i].GetLBText(j,str);
		m_param.nHightFre = atoi(str);
		j = m_workfre[i].GetCurSel();
		m_workfre[i].GetLBText(j,str);
		m_param.nWorkFre = atoi(str);
		j = m_timec[i].GetCurSel();
		m_timec[i].GetLBText(j,str);
		m_param.nTimeConstant = atoi(str);
		Doc->SetParam(&m_param);
		Doc->vchannel[i] = m_check[i].GetCheck();

	}
	OnOK();
}

BOOL CChannelsSetupDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	int i;
	for(i=0;i<32;i++)
	{
		m_check[i].SetCheck(1);
		m_highfre[i].AddString("15");
		m_highfre[i].AddString("30");
		m_highfre[i].AddString("45");
		m_highfre[i].AddString("60");
		m_highfre[i].AddString("120");
		m_highfre[i].SetCurSel(2);
		m_workfre[i].AddString("0");
		m_workfre[i].AddString("50");
		m_workfre[i].AddString("60");
		m_workfre[i].SetCurSel(1);
		m_timec[i].AddString("30");
		m_timec[i].AddString("10");
		m_timec[i].AddString("3");
		m_timec[i].SetCurSel(2);

	}
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CChannelsSetupDialog::OnBackset() 
{
	// TODO: Add your control notification handler code here
	int i;
	for(i=0;i<32;i++)
	{
		if(m_check[i].GetCheck()==1)
		{
			m_check[i].SetCheck(0);
		}
		else if(m_check[i].GetCheck()==0)
		{
			m_check[i].SetCheck(1);
		}
	}
}
