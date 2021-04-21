// AddActivityDialog.cpp : implementation file
//

#include "stdafx.h"
#include "1_7FF.h"
#include "NewActivityDialog.h"
#include "ParadigmSetupDialog.h"
#include "AddActivityDialog.h"
#include "CInfoFile.h"
#include "CAClistFile.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddActivityDialog dialog


CAddActivityDialog::CAddActivityDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAddActivityDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddActivityDialog)
	m_starttime = 0;
	m_endtime = 0;
	//}}AFX_DATA_INIT
}


void CAddActivityDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddActivityDialog)
	DDX_Control(pDX, IDC_COMBO_ACS, m_comboACS);
	DDX_Text(pDX, IDC_STARTTIME, m_starttime);
	DDX_Text(pDX, IDC_ENDTIME, m_endtime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddActivityDialog, CDialog)
	//{{AFX_MSG_MAP(CAddActivityDialog)
	ON_BN_CLICKED(IDC_ADD_NEW, OnAddNew)
	ON_CBN_SELCHANGE(IDC_COMBO_ACS, OnSelchangeComboAcs)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_ACRESET, OnAcreset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddActivityDialog message handlers

void CAddActivityDialog::OnAddNew() 
{
	// TODO: Add your control notification handler code here
	CNewActivityDialog dialog;
	dialog.DoModal();
	Initm_combo();
} 

void CAddActivityDialog::OnCancel() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

BOOL CAddActivityDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	Initm_combo();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddActivityDialog::OnSelchangeComboAcs() 
{
	// TODO: Add your control notification handler code here
	int index = m_comboACS.GetCurSel();
	m_comboACS.GetLBText(index,m_acname);
	CInfoFile file;
	file.ReadAcs();
	for(list<ac>::iterator it = file.ls.begin();it!=file.ls.end();it++)
	{
		if(m_acname == it->acname)
		{
			m_accontext = it->accontext;
			m_tag = it->tag;
			break;
		}
	}
	
}

void CAddActivityDialog::OnOk() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_endtime<=m_starttime)
	{
		m_endtime = m_starttime+1;
	}
	CAClistFile cfile;
	cfile.Readtols();
	cfile.Addtols(m_starttime,m_endtime,m_acname,m_accontext,m_tag);
	cfile.lsWriteto();
	OnOK();
}

void CAddActivityDialog::Initm_combo()
{
	CInfoFile file;
	file.ReadAcs();
	m_comboACS.ResetContent();
	//for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	if(!file.ls.empty())
	{
		for(list<ac>::iterator it = file.ls.begin();it!=file.ls.end();it++)
			{
				m_comboACS.AddString(it->acname);
			}
			
			it = file.ls.begin();
			m_acname = it->acname;
			m_accontext = it->accontext;
			m_tag = it->tag;
			m_comboACS.SetCurSel(0);
			
	}
	
	CAClistFile cfile;
	cfile.Readtols();
	if(!cfile.ls.empty())
	{
		for(list<pac>::iterator pit = cfile.ls.begin();pit!=cfile.ls.end();pit++)
			{
				m_starttime = pit->endtime;
			}
	}
	
	UpdateData(false);
}

void CAddActivityDialog::OnAcreset() 
{
	// TODO: Add your control notification handler code here
	CInfoFile file;
	file.ReadAcs();
	file.ls.clear();
	file.WriteAcs();
	CAClistFile cfile;
	cfile.Readtols();
	cfile.ls.clear();
	cfile.lsWriteto();
	Initm_combo();
}
