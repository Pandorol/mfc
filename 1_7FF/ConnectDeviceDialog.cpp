// ConnectDeviceDialog.cpp : implementation file
//

#include "stdafx.h"
#include "1_7FF.h"
#include "1_7FFDoc.h"
#include "ConnectDeviceDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConnectDeviceDialog dialog


CConnectDeviceDialog::CConnectDeviceDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CConnectDeviceDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConnectDeviceDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CConnectDeviceDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConnectDeviceDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConnectDeviceDialog, CDialog)
	//{{AFX_MSG_MAP(CConnectDeviceDialog)
	ON_BN_CLICKED(ID_CONNECT, OnConnect)
	ON_BN_CLICKED(ID_CANCEL, OnCancel)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConnectDeviceDialog message handlers

void CConnectDeviceDialog::OnConnect() 
{
	// TODO: Add your control notification handler code here
	CMy1_7FFDoc* Doc = (CMy1_7FFDoc*)(((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument());
	Doc->ConnectDevice();
	if(Doc->ConnectDevice())
	{
		OnOK();
	}
	else
	{

	}
}

void CConnectDeviceDialog::OnCancel() 
{
	// TODO: Add your control notification handler code here
	exit(0);
}

void CConnectDeviceDialog::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	exit(0);
	CDialog::OnClose();
}
