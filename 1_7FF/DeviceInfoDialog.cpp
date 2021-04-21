// DeviceInfoDialog.cpp : implementation file
//

#include "stdafx.h"
#include "1_7FF.h"
#include "1_7FFDoc.h"
#include "DeviceInfoDialog.h"
#include "EEGAMP.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeviceInfoDialog dialog


CDeviceInfoDialog::CDeviceInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CDeviceInfoDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeviceInfoDialog)
	m_channelsNum = 0;
	m_deviceID = 0;
	m_deviceType = 0;
	m_switchNo = 0;
	//}}AFX_DATA_INIT
}


void CDeviceInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeviceInfoDialog)
	DDX_Text(pDX, IDC_CHANNELS_COUNT, m_channelsNum);
	DDX_Text(pDX, IDC_DEVICE_ID, m_deviceID);
	DDX_Text(pDX, IDC_DEVICE_TYPE, m_deviceType);
	DDX_Text(pDX, IDC_SWITCH_NO, m_switchNo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeviceInfoDialog, CDialog)
	//{{AFX_MSG_MAP(CDeviceInfoDialog)
	ON_BN_CLICKED(IDC_OK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeviceInfoDialog message handlers

void CDeviceInfoDialog::OnOk() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

BOOL CDeviceInfoDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	Doc = (CMy1_7FFDoc*)(((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument());
	STRU_DEVICE_INFO deviceinfo;
	Doc->GetDeviceInfo(&deviceinfo);
	m_channelsNum = deviceinfo.nRouteNum;
	m_deviceID = deviceinfo.nDeviceID;
	m_deviceType = deviceinfo.nType;
	m_switchNo = deviceinfo.nSwitchNo;
	UpdateData(false);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
