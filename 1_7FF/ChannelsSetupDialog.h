#if !defined(AFX_CHANNELSSETUPDIALOG_H__3600D055_993C_497E_B561_4E38DA05C97E__INCLUDED_)
#define AFX_CHANNELSSETUPDIALOG_H__3600D055_993C_497E_B561_4E38DA05C97E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChannelsSetupDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChannelsSetupDialog dialog

class CChannelsSetupDialog : public CDialog
{
// Construction
public:
	CChannelsSetupDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChannelsSetupDialog)
	enum { IDD = IDD_CHANNELS_SETUP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	CComboBox m_highfre[32];
	CComboBox m_workfre[32];
	CComboBox m_timec[32];
	CButton m_check[32];
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChannelsSetupDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChannelsSetupDialog)
	afx_msg void OnOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBackset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANNELSSETUPDIALOG_H__3600D055_993C_497E_B561_4E38DA05C97E__INCLUDED_)
