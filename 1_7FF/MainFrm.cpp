// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "1_7FF.h"
#include "1_7FFDoc.h"
#include "MainFrm.h"
#include "ConnectDeviceDialog.h"
#include "ConnectionStatusDialog.h"
#include "DeviceInfoDialog.h"
#include "ImpedanceDetectiveDialog.h"
#include "ChannelsSetupDialog.h"
#include "ParadigmSetupDialog.h"
#include "ParadigmShowDialog.h"
#include "DrawPand.h"
#include "EEGWaveDialog.h"
#include "TCPIPSetupDialog.h"
#include "OnlineSystem1.h"
//#include "WaveView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_MENU_CONNECTION_STATUS, OnMenuConnectionStatus)
	ON_COMMAND(ID_MENU_DEVICE_INFO, OnMenuDeviceInfo)
	ON_COMMAND(ID_MENU_EXIT, OnMenuExit)
	ON_COMMAND(ID_MENU_IMPEDANCE_DETECTIVE, OnMenuImpedanceDetective)
	ON_COMMAND(ID_MENU_CHANNELS_SETUP, OnMenuChannelsSetup)
	ON_COMMAND(ID_MENU_PARADIGM_SETUP, OnMenuParadigmSetup)
	ON_COMMAND(ID_MENU_RECWAVE_MONITOR, OnMenuRecwaveMonitor)
	ON_COMMAND(ID_MENU_EEG_MONITOR, OnMenuEegMonitor)
	ON_COMMAND(ID_MENU_START_COLLECT, OnMenuStartCollect)
	ON_COMMAND(ID_MENU_TCPIP_SETUP, OnMenuTcpipSetup)
	ON_COMMAND(ID_MENU_ONLINESYSTEM1, OnMenuOnlinesystem1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnMenuConnectionStatus() 
{
	// TODO: Add your command handler code here
	Doc = (CMy1_7FFDoc*)GetActiveDocument();
	//Doc->ConnectDevice();
	if(!Doc->DeviceOpenStatus())
	{
		CConnectDeviceDialog dialog;
		dialog.DoModal();
	}
	else
	{
		CConnectionStatusDialog dialog;
		dialog.DoModal();
	}
	
}

void CMainFrame::OnMenuDeviceInfo() 
{
	// TODO: Add your command handler code here
	CDeviceInfoDialog dialog;
	dialog.DoModal();
}

void CMainFrame::OnMenuExit() 
{
	// TODO: Add your command handler code here
	exit(0);
}

void CMainFrame::OnMenuImpedanceDetective() 
{
	// TODO: Add your command handler code here
	CImpedanceDetectiveDialog dialog;
	dialog.DoModal();
}

void CMainFrame::OnMenuChannelsSetup() 
{
	// TODO: Add your command handler code here
	CChannelsSetupDialog dialog;
	dialog.DoModal();
}

void CMainFrame::OnMenuParadigmSetup() 
{
	// TODO: Add your command handler code here
	CParadigmSetupDialog dialog;
	dialog.DoModal();
}

void CMainFrame::OnMenuRecwaveMonitor() 
{
	// TODO: Add your command handler code here
	Doc = (CMy1_7FFDoc*)GetActiveDocument();
	Doc->SetRecParam();
	CEEGWaveDialog dialog;
	dialog.DoModal();
}

void CMainFrame::OnMenuEegMonitor() 
{
	// TODO: Add your command handler code here
	CEEGWaveDialog dialog;
	dialog.DoModal();
}

void CMainFrame::OnMenuStartCollect() 
{
	// TODO: Add your command handler code here
	CParadigmShowDialog dialog;
	dialog.DoModal();
}

void CMainFrame::OnMenuTcpipSetup() 
{
	// TODO: Add your command handler code here
	CTCPIPSetupDialog dialog;
	dialog.DoModal();
}

void CMainFrame::OnMenuOnlinesystem1() 
{
	// TODO: Add your command handler code here
	COnlineSystem1 sys1;
	sys1.DoModal();
}
