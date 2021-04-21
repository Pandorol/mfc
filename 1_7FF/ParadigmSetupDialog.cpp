// ParadigmSetupDialog.cpp : implementation file
//

#include "stdafx.h"
#include "1_7FF.h"
//#include "NewActivityDialog.h"
#include "AddActivityDialog.h"
#include "ParadigmSetupDialog.h"
#include "CAClistFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CParadigmSetupDialog dialog


CParadigmSetupDialog::CParadigmSetupDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CParadigmSetupDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CParadigmSetupDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CParadigmSetupDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CParadigmSetupDialog)
	DDX_Control(pDX, IDC_COMBO1, m_final_item);
	DDX_Control(pDX, IDC_LISTACS, m_aclist);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CParadigmSetupDialog, CDialog)
	//{{AFX_MSG_MAP(CParadigmSetupDialog)
	ON_BN_CLICKED(IDC_ADD_ACTIVITY, OnAddActivity)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_REPEAT, OnRepeat)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParadigmSetupDialog message handlers

void CParadigmSetupDialog::OnAddActivity() 
{
	// TODO: Add your control notification handler code here
	CAddActivityDialog dialog;
	dialog.DoModal();
	DisplayList();
	//OnInitDialog();
}

void CParadigmSetupDialog::OnReset() 
{
	// TODO: Add your control notification handler code here
	CAClistFile cfile;
	cfile.Readtols();
	cfile.ls.clear();
	cfile.lsWriteto();
	m_aclist.DeleteAllItems();
}

BOOL CParadigmSetupDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	m_aclist.SetExtendedStyle(m_aclist.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	CRect rect;
	m_aclist.GetWindowRect(rect);
	m_aclist.InsertColumn(0,_T("开始时间"), LVCFMT_CENTER,rect.Width()/4);
	m_aclist.InsertColumn(1,_T("结束时间"), LVCFMT_CENTER,rect.Width()/4);
	m_aclist.InsertColumn(2,_T("想象活动"), LVCFMT_CENTER,rect.Width()/4);
	m_aclist.InsertColumn(3,_T("标签"), LVCFMT_CENTER,rect.Width()/4);
	/*CString str;
	str.Format("555");
	m_aclist.InsertItem(0,str);
	m_aclist.SetItemText(0,1,str);
	m_aclist.SetItemText(0,2,str);*/
	DisplayList();
	m_final_item.AddString("1");
	m_final_item.AddString("2");
	m_final_item.AddString("3");
	m_final_item.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CParadigmSetupDialog::DisplayList()
{
	m_aclist.DeleteAllItems();
	CAClistFile cfile;
	cfile.Readtols();
	int i=0,col =1;CString str;
	for(list<pac>::iterator it = cfile.ls.begin();it!=cfile.ls.end();it++)
	{
		str.Format("%d",it->starttime);
		m_aclist.InsertItem(i,str);
		col=1;
		str.Format("%d",it->endtime);
		m_aclist.SetItemText(i,col++,str);
		str.Format("%s",it->acname);
		m_aclist.SetItemText(i,col++,str);
		str.Format("%d",it->tag);
		m_aclist.SetItemText(i,col++,str);
		i++;
	}
}

void CParadigmSetupDialog::OnOk() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CParadigmSetupDialog::OnRepeat() 
{
	// TODO: Add your control notification handler code here
	CString str;
	short index;
	index = m_final_item.GetCurSel();
	m_final_item.GetLBText(index,str);
	short n_item = atoi(str);
	CAClistFile cfile;
	cfile.Readtols();
	if(cfile.ls.size()>=n_item)
	{
		list<pac>::iterator it = cfile.ls.end();
		short i,m_starttime,m_endtime;
		it--;
		m_starttime = it->endtime;
		m_endtime = m_starttime;
		for(i=1;i<n_item;i++)
		{
			it--;
		}
		for(i=0;i<n_item;i++,it++)
		{
			m_endtime = m_starttime+it->endtime-it->starttime;
			cfile.Addtols(m_starttime,m_endtime,it->acname,it->accontext,it->tag);
			m_starttime = m_endtime;
		}
		cfile.lsWriteto();
		DisplayList();
	}
	
	
	
}
