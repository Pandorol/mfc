#if !defined(AFX_DEVICEINFODIALOG_H__A6E93D67_8308_43FC_9851_B0B2664EF69C__INCLUDED_)
#define AFX_DEVICEINFODIALOG_H__A6E93D67_8308_43FC_9851_B0B2664EF69C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeviceInfoDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeviceInfoDialog dialog

class CDeviceInfoDialog : public CDialog
{
// Construction
public:
	CDeviceInfoDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDeviceInfoDialog)
	enum { IDD = IDD_DEVICE_INFO_DIALOG };
	short	m_channelsNum;
	short	m_deviceType;
	short	m_deviceID;
	short	m_switchNo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeviceInfoDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeviceInfoDialog)
	afx_msg void OnOk();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CMy1_7FFDoc* Doc;
	
		
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEVICEINFODIALOG_H__A6E93D67_8308_43FC_9851_B0B2664EF69C__INCLUDED_)
