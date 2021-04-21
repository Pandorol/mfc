// 1_7FFView.h : interface of the CMy1_7FFView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_1_7FFVIEW_H__9B59E166_AF68_4776_A782_90F336CAEB0C__INCLUDED_)
#define AFX_1_7FFVIEW_H__9B59E166_AF68_4776_A782_90F336CAEB0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy1_7FFView : public CView
{
protected: // create from serialization only
	CMy1_7FFView();
	DECLARE_DYNCREATE(CMy1_7FFView)

// Attributes
public:
	CMy1_7FFDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1_7FFView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy1_7FFView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy1_7FFView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 1_7FFView.cpp
inline CMy1_7FFDoc* CMy1_7FFView::GetDocument()
   { return (CMy1_7FFDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1_7FFVIEW_H__9B59E166_AF68_4776_A782_90F336CAEB0C__INCLUDED_)
