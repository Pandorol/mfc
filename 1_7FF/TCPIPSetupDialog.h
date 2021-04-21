#if !defined(AFX_TCPIPSETUPDIALOG_H__602B4922_A274_42C7_8E94_3CCE8129AB0B__INCLUDED_)
#define AFX_TCPIPSETUPDIALOG_H__602B4922_A274_42C7_8E94_3CCE8129AB0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TCPIPSetupDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTCPIPSetupDialog dialog

class CTCPIPSetupDialog : public CDialog
{
// Construction
public:
	CTCPIPSetupDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTCPIPSetupDialog)
	enum { IDD = IDD_TCPIP_SETUP_DIALOG };
	CString	m_ips;
	int		m_port;
	CString	m_ip;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPIPSetupDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTCPIPSetupDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPIPSETUPDIALOG_H__602B4922_A274_42C7_8E94_3CCE8129AB0B__INCLUDED_)
