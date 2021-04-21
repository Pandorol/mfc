// DrawPand.cpp : implementation file
//

#include "stdafx.h"
#include "1_7FF.h"
#include "DrawPand.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawPand

CDrawPand::CDrawPand()
{
	RegisterWndClass(); 
	
	title.Format("ff:");
	d_width = 7000;
	d_height = 600;
	p_data = (short*)malloc(2*d_width);
	int i;
	for(i=0;i<d_width;i++)
	{
		p_data[i]=200;
	}/*
	Invalidate();*/
}

CDrawPand::~CDrawPand()
{
	if(p_data)
	{
		free(p_data);
	}
	
}


BEGIN_MESSAGE_MAP(CDrawPand, CWnd)
	//{{AFX_MSG_MAP(CDrawPand)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDrawPand message handlers

BOOL CDrawPand::RegisterWndClass()
{
	WNDCLASS windowclass;  
    HINSTANCE hInst = AfxGetInstanceHandle();  
  
    if(!(::GetClassInfo(hInst,MYWNDCLASS,&windowclass)))  
    {  
        windowclass.style = CS_DBLCLKS;  
        windowclass.lpfnWndProc = ::DefWindowProc;  
        windowclass.cbClsExtra = windowclass.cbWndExtra = 0;  
        windowclass.hInstance =hInst;  
        windowclass.hIcon = NULL;  
        windowclass.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);  
        windowclass.hbrBackground = ::GetSysColorBrush(COLOR_WINDOW);  
        windowclass.lpszMenuName = NULL;  
        windowclass.lpszClassName = MYWNDCLASS;  
  
        if(!AfxRegisterClass(&windowclass))  
        {  
            AfxThrowResourceException();  
            return FALSE;  
        }  
    }  
    return TRUE; 
}

//DEL void CDrawPand::OnPaint() 
//DEL {
//DEL 	CPaintDC dc(this); // device context for painting
//DEL 	
//DEL 	// TODO: Add your message handler code here
//DEL 	//dc.MoveTo(0,0);
//DEL 	//dc.LineTo(20,20);
//DEL 	// Do not call CWnd::OnPaint() for painting messages
//DEL }

void CDrawPand::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	//dc.MoveTo(0,0);dc.LineTo(20,20);
	// Do not call CWnd::OnPaint() for painting messages
	Drawwave(&dc);
}






void CDrawPand::Drawwave(CDC *pDC)
{
	
	CRect rect;
	GetClientRect(&rect);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap NewBitmap;
	NewBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	memDC.SelectObject(&NewBitmap);
	
	DrawObject(&memDC);
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);
	NewBitmap.DeleteObject();
	memDC.DeleteDC();

}

void CDrawPand::DrawObject(CDC *pDC)
{
	
	CRect rect;
	GetClientRect(&rect);
	pDC->FillSolidRect(0,0,rect.Width(),rect.Height(),RGB(255, 255, 255));
	
	pDC->SetMapMode(MM_ANISOTROPIC);						    //设置映射模式
	pDC->SetWindowExt(CSize(d_width+d_width/10,d_height));			    //设置窗口逻辑
	pDC->SetViewportExt(rect.Width(),rect.Height());		 //X轴水平向右，Y轴垂直向上
	//CFont font;
	//font.CreatePointFont(20,TEXT("Arial"));
	//pDC->SelectObject(&font);
	short startx = d_width/10,starty = d_height/2;
	pDC->DrawText(title, CRect(0,0,startx,d_height), DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	short i;
	
	pDC->MoveTo(startx,starty-p_data[0]);
	for(i=1;i<d_width;i++)
	{
		pDC->LineTo(startx+i,starty-p_data[i]);
	}
	pDC->SetMapMode(MM_TEXT);
	
	
}

BOOL CDrawPand::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	//return CWnd::OnEraseBkgnd(pDC);
	return true;
}
