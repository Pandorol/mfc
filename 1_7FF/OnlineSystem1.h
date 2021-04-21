#if !defined(AFX_ONLINESYSTEM1_H__2D258A3B_603B_4260_A499_D4D2BE143C24__INCLUDED_)
#define AFX_ONLINESYSTEM1_H__2D258A3B_603B_4260_A499_D4D2BE143C24__INCLUDED_

#include "TCPIPOperate.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OnlineSystem1.h : header file
//
#define   WM_UPDATEDATA_ON1   WM_USER + 6
/////////////////////////////////////////////////////////////////////////////
// COnlineSystem1 dialog

class COnlineSystem1 : public CDialog
{
// Construction
public:
	CRect m_window_rect;
	CRect m_cube_rect;
	int m_cube_posleft;

	void StopTransData();
	CTCPIPOperate* tcpip;
	CMy1_7FFDoc* Doc;
	int o_skt;
	BOOL sendSwitch;
	BOOL recvSwitch;
	static UINT SendData(LPVOID lparam);
	static UINT RecvData(LPVOID lparam);
	CWinThread *m_pthread_send;
	CWinThread *m_pthread_recv;
	COnlineSystem1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COnlineSystem1)
	enum { IDD = IDD_ONLINESYSTEM1_DIALOG };
	CStatic	m_cube;
	CString	m_Instruction;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COnlineSystem1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COnlineSystem1)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonStart();
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	afx_msg LRESULT OnMyUpdateData(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONLINESYSTEM1_H__2D258A3B_603B_4260_A499_D4D2BE143C24__INCLUDED_)
