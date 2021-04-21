#if !defined(AFX_IMPEDANCEDETECTIVEDIALOG_H__751B64CA_5E38_4E8B_A821_A955560409DF__INCLUDED_)
#define AFX_IMPEDANCEDETECTIVEDIALOG_H__751B64CA_5E38_4E8B_A821_A955560409DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImpedanceDetectiveDialog.h : header file
//
#define   WM_UPDATEDATA   WM_USER + 5 
/////////////////////////////////////////////////////////////////////////////
// CImpedanceDetectiveDialog dialog

class CImpedanceDetectiveDialog : public CDialog
{
// Construction
public:
	CImpedanceDetectiveDialog(CWnd* pParent = NULL);   // standard constructor
	CWinThread *m_pthread;
	static UINT RefreashData(LPVOID lparam);
// Dialog Data
	//{{AFX_DATA(CImpedanceDetectiveDialog)
	enum { IDD = IDD_IMPEDANCE_DETECTIVE_DIALOG };
	//}}AFX_DATA
	short imp[32];

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImpedanceDetectiveDialog)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CImpedanceDetectiveDialog)
	afx_msg void OnOk();
	afx_msg void OnStartDetective();
	afx_msg void OnStopDetective();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	//}}AFX_MSG
	afx_msg LRESULT OnMyUpdateData(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	short DetectiveSwitch;
	CMy1_7FFDoc* Doc;
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMPEDANCEDETECTIVEDIALOG_H__751B64CA_5E38_4E8B_A821_A955560409DF__INCLUDED_)
