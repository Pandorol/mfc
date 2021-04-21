// NewActivityDialog.cpp : implementation file
//

#include "stdafx.h"
#include "1_7FF.h"
#include "AddActivityDialog.h"
#include "NewActivityDialog.h"
#include "CInfoFile.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewActivityDialog dialog


CNewActivityDialog::CNewActivityDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CNewActivityDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewActivityDialog)
	m_newAcName = _T("");
	m_newAcText = _T("");
	m_tag = _T("");
	//}}AFX_DATA_INIT
}


void CNewActivityDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewActivityDialog)
	DDX_Text(pDX, IDC_NEW_AC, m_newAcName);
	DDX_Text(pDX, IDC_NEW_ACTEXT, m_newAcText);
	DDX_Text(pDX, IDC_NEW_TAG, m_tag);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewActivityDialog, CDialog)
	//{{AFX_MSG_MAP(CNewActivityDialog)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewActivityDialog message handlers

void CNewActivityDialog::OnOk() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_newAcName== _T("")||m_newAcText==_T(""))
	{
		MessageBox("不能为空！");
		return;
	}
	int i;char c;
	for(i=0;i<m_tag.GetLength();i++)
	{
		c = m_tag.GetAt(i);
		if(c < '0'||c>'9')
		{
			MessageBox("标签必须为数字！");
			return;
		}
	}
	
	UpdateData(true);
	//MessageBox(m_newAcName);
	//MessageBox(m_newAcText);
	CInfoFile file;
	file.ReadAcs();
	file.AddAcs(m_newAcName,m_newAcText,atoi(m_tag));
	file.WriteAcs();
	OnOK();
}

void CNewActivityDialog::OnCancel() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
