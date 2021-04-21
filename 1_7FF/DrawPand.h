#if !defined(AFX_DRAWPAND_H__D4B83972_D516_477D_9ABF_1FD317CA27AD__INCLUDED_)
#define AFX_DRAWPAND_H__D4B83972_D516_477D_9ABF_1FD317CA27AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DrawPand.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDrawPand window
#define MYWNDCLASS _T("MyDrawPad")
class CDrawPand : public CWnd
{
// Construction
public:
	CDrawPand();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawPand)
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawObject(CDC *pDC);
	void Drawwave(CDC *pDC);
	CString title;
	short d_width,d_height;
	short* p_data;
	BOOL RegisterWndClass();
	virtual ~CDrawPand();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDrawPand)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWPAND_H__D4B83972_D516_477D_9ABF_1FD317CA27AD__INCLUDED_)
