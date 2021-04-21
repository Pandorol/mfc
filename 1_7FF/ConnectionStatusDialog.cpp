// ConnectionStatusDialog.cpp : implementation file
//

#include "stdafx.h"
#include "1_7FF.h"
#include "ConnectionStatusDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConnectionStatusDialog dialog


CConnectionStatusDialog::CConnectionStatusDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CConnectionStatusDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConnectionStatusDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CConnectionStatusDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConnectionStatusDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConnectionStatusDialog, CDialog)
	//{{AFX_MSG_MAP(CConnectionStatusDialog)
	ON_BN_CLICKED(ID_BTN_OK, OnBtnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConnectionStatusDialog message handlers

void CConnectionStatusDialog::OnBtnOk() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
