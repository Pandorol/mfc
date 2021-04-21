// TCPIPSetupDialog.cpp : implementation file
//

#include "stdafx.h"
#include "1_7FF.h"
#include "1_7FFDoc.h"
#include "TCPIPSetupDialog.h"

#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTCPIPSetupDialog dialog


CTCPIPSetupDialog::CTCPIPSetupDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTCPIPSetupDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTCPIPSetupDialog)
	m_ips = _T("");
	m_port = 1000;
	m_ip = _T("");
	//}}AFX_DATA_INIT
}


void CTCPIPSetupDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTCPIPSetupDialog)
	DDX_Text(pDX, IDC_EDIT_IPS, m_ips);
	DDX_Text(pDX, IDC_EDIT_PORT, m_port);
	DDX_Text(pDX, IDC_EDIT_IP_ADDR, m_ip);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTCPIPSetupDialog, CDialog)
	//{{AFX_MSG_MAP(CTCPIPSetupDialog)
	ON_BN_CLICKED(IDC_BTN_OK, OnBtnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTCPIPSetupDialog message handlers

BOOL CTCPIPSetupDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	WORD version = MAKEWORD(2, 0);
	WSADATA wsaData;
	if(WSAStartup(version, &wsaData)!=0)
	{
		MessageBox("³õÊ¼»¯´íÎó");
	}
	struct hostent *phostinfo = gethostbyname("");
	int i=0;
	
	char *pszAddr;CString addr[5];
	for(i = 0; NULL != phostinfo&& NULL != phostinfo->h_addr_list[i]; ++i)
	{
		pszAddr = inet_ntoa(*(struct in_addr *)phostinfo->h_addr_list[i]);
		addr[i].Format("%s\r\n",pszAddr);
	}
	WSACleanup();
	for(i=i-1;i>=0;i--)
	m_ips +=addr[i];
	CMy1_7FFDoc* Doc = (CMy1_7FFDoc*)(((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument());
	
	this->m_ip = Doc->m_ip;
	this->m_port = Doc->m_port;
	UpdateData(false);
	WSACleanup(); 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE

}

void CTCPIPSetupDialog::OnBtnOk() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CMy1_7FFDoc* Doc = (CMy1_7FFDoc*)(((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument());
	Doc->m_port = this->m_port;
	Doc->m_ip = this->m_ip;
	OnOK();
}
