#if !defined(AFX_CONNECTDEVICEDIALOG_H__D883D4FC_9C8C_44C7_8FD0_75749B51A7E8__INCLUDED_)
#define AFX_CONNECTDEVICEDIALOG_H__D883D4FC_9C8C_44C7_8FD0_75749B51A7E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConnectDeviceDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConnectDeviceDialog dialog

class CConnectDeviceDialog : public CDialog
{
// Construction
public:
	CConnectDeviceDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CConnectDeviceDialog)
	enum { IDD = IDD_CONNECT_DEVICE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConnectDeviceDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConnectDeviceDialog)
	afx_msg void OnConnect();
	afx_msg void OnCancel();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONNECTDEVICEDIALOG_H__D883D4FC_9C8C_44C7_8FD0_75749B51A7E8__INCLUDED_)
