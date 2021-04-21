// 1_7FFView.cpp : implementation of the CMy1_7FFView class
//

#include "stdafx.h"
#include "1_7FF.h"

#include "1_7FFDoc.h"
#include "1_7FFView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy1_7FFView

IMPLEMENT_DYNCREATE(CMy1_7FFView, CView)

BEGIN_MESSAGE_MAP(CMy1_7FFView, CView)
	//{{AFX_MSG_MAP(CMy1_7FFView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1_7FFView construction/destruction

CMy1_7FFView::CMy1_7FFView()
{
	// TODO: add construction code here

}

CMy1_7FFView::~CMy1_7FFView()
{
}

BOOL CMy1_7FFView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy1_7FFView drawing

void CMy1_7FFView::OnDraw(CDC* pDC)
{
	CMy1_7FFDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMy1_7FFView diagnostics

#ifdef _DEBUG
void CMy1_7FFView::AssertValid() const
{
	CView::AssertValid();
}

void CMy1_7FFView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1_7FFDoc* CMy1_7FFView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1_7FFDoc)));
	return (CMy1_7FFDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy1_7FFView message handlers
