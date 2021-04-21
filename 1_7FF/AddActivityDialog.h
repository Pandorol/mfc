#if !defined(AFX_ADDACTIVITYDIALOG_H__16A162A4_6A6F_4FD1_AD51_D260C22967F4__INCLUDED_)
#define AFX_ADDACTIVITYDIALOG_H__16A162A4_6A6F_4FD1_AD51_D260C22967F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddActivityDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddActivityDialog dialog

class CAddActivityDialog : public CDialog
{
// Construction
public:
	void Initm_combo();
	short m_tag;
	CAddActivityDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddActivityDialog)
	enum { IDD = IDD_ADD_ACTIVITY_DIALOG };
	CComboBox	m_comboACS;
	short	m_starttime;
	short	m_endtime;
	//}}AFX_DATA
	CString m_acname;
	CString m_accontext;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddActivityDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddActivityDialog)
	afx_msg void OnAddNew();
	afx_msg void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboAcs();
	afx_msg void OnOk();
	afx_msg void OnAcreset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDACTIVITYDIALOG_H__16A162A4_6A6F_4FD1_AD51_D260C22967F4__INCLUDED_)
