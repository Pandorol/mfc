#if !defined(AFX_EEGWAVEDIALOG_H__33C425C6_A3AD_4919_922F_8B1AFA9D5586__INCLUDED_)
#define AFX_EEGWAVEDIALOG_H__33C425C6_A3AD_4919_922F_8B1AFA9D5586__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EEGWaveDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEEGWaveDialog dialog
class CDrawPand;
class CEEGWaveDialog : public CDialog
{
// Construction
public:
	short writeSwitch;
	short d_height;
	CString channelname[33];
	short page;
	void StopT();
	short GetSwitch;
	short index;
	short* p_data;
	short d_width;
	CEEGWaveDialog(CWnd* pParent = NULL);   // standard constructor
	CDrawPand m_draw[12];
	CWinThread *m_pthread;
	CComboBox	m_combo_height;
	CComboBox	m_combo_width;
	static UINT GetData(LPVOID lparam);
	CMy1_7FFDoc* Doc;
// Dialog Data
	//{{AFX_DATA(CEEGWaveDialog)
	enum { IDD = IDD_EEGWAVE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEEGWaveDialog)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEEGWaveDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnCancel();
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnNextPage();
	afx_msg void OnLastPage();
	afx_msg void OnSwitchscale();
	afx_msg void OnCollect();
	afx_msg void OnStopCollect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EEGWAVEDIALOG_H__33C425C6_A3AD_4919_922F_8B1AFA9D5586__INCLUDED_)
