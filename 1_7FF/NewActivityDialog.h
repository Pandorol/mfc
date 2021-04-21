#if !defined(AFX_NEWACTIVITYDIALOG_H__AD3DEE37_A71E_47F8_ACA6_AEAC50881913__INCLUDED_)
#define AFX_NEWACTIVITYDIALOG_H__AD3DEE37_A71E_47F8_ACA6_AEAC50881913__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewActivityDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewActivityDialog dialog

class CNewActivityDialog : public CDialog
{
// Construction
public:
	CNewActivityDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewActivityDialog)
	enum { IDD = IDD_NEW_ACTIVITY_DIALOG };
	CString	m_newAcName;
	CString	m_newAcText;
	CString	m_tag;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewActivityDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewActivityDialog)
	afx_msg void OnOk();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWACTIVITYDIALOG_H__AD3DEE37_A71E_47F8_ACA6_AEAC50881913__INCLUDED_)
