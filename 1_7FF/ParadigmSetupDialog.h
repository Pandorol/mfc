#if !defined(AFX_PARADIGMSETUPDIALOG_H__7F003C11_753B_4A5A_864D_F7F74B4ADB4C__INCLUDED_)
#define AFX_PARADIGMSETUPDIALOG_H__7F003C11_753B_4A5A_864D_F7F74B4ADB4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ParadigmSetupDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CParadigmSetupDialog dialog

class CParadigmSetupDialog : public CDialog
{
// Construction
public:
	void DisplayList();
	CParadigmSetupDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CParadigmSetupDialog)
	enum { IDD = IDD_PARADIGM_SETUP_DIALOG };
	CComboBox	m_final_item;
	CListCtrl	m_aclist;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParadigmSetupDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CParadigmSetupDialog)
	afx_msg void OnAddActivity();
	afx_msg void OnReset();
	virtual BOOL OnInitDialog();
	afx_msg void OnOk();
	afx_msg void OnRepeat();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARADIGMSETUPDIALOG_H__7F003C11_753B_4A5A_864D_F7F74B4ADB4C__INCLUDED_)
