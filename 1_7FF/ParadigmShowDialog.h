#if !defined(AFX_PARADIGMSHOWDIALOG_H__CEE42987_22FA_4EE3_8A6B_F044D2F68413__INCLUDED_)
#define AFX_PARADIGMSHOWDIALOG_H__CEE42987_22FA_4EE3_8A6B_F044D2F68413__INCLUDED_

#include "CAClistFile.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ParadigmShowDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CParadigmShowDialog dialog

class CParadigmShowDialog : public CDialog
{
// Construction
public:
	short WriteSwitch;
	short tag;
	CMy1_7FFDoc* Doc;
	short order;
	CAClistFile cfile;
	CParadigmShowDialog(CWnd* pParent = NULL);   // standard constructor
	CWinThread *m_pthread;
	static UINT WriteData(LPVOID lparam);
// Dialog Data
	//{{AFX_DATA(CParadigmShowDialog)
	enum { IDD = IDD_PARADIGM_SHOW };
	
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParadigmShowDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CParadigmShowDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARADIGMSHOWDIALOG_H__CEE42987_22FA_4EE3_8A6B_F044D2F68413__INCLUDED_)
