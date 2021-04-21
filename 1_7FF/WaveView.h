#if !defined(AFX_WAVEVIEW_H__02913687_BB85_4DB9_BF0D_4D4145D53B79__INCLUDED_)
#define AFX_WAVEVIEW_H__02913687_BB85_4DB9_BF0D_4D4145D53B79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WaveView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWaveView view

class CWaveView : public CScrollView
{
protected:
	CWaveView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CWaveView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWaveView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CWaveView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CWaveView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAVEVIEW_H__02913687_BB85_4DB9_BF0D_4D4145D53B79__INCLUDED_)
