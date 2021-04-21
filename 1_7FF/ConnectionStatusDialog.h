#if !defined(AFX_CONNECTIONSTATUSDIALOG_H__A20F7C9F_425C_4298_9A07_1FE9DAFA149B__INCLUDED_)
#define AFX_CONNECTIONSTATUSDIALOG_H__A20F7C9F_425C_4298_9A07_1FE9DAFA149B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConnectionStatusDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConnectionStatusDialog dialog

class CConnectionStatusDialog : public CDialog
{
// Construction
public:
	CConnectionStatusDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CConnectionStatusDialog)
	enum { IDD = IDD_CONNECTION_STATUS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConnectionStatusDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConnectionStatusDialog)
	afx_msg void OnBtnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONNECTIONSTATUSDIALOG_H__A20F7C9F_425C_4298_9A07_1FE9DAFA149B__INCLUDED_)
