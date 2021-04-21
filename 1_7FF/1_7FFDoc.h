// 1_7FFDoc.h : interface of the CMy1_7FFDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_1_7FFDOC_H__BA2993DD_0768_4579_8DBB_A63181DA4B25__INCLUDED_)
#define AFX_1_7FFDOC_H__BA2993DD_0768_4579_8DBB_A63181DA4B25__INCLUDED_

#include "EEGAMP.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy1_7FFDoc : public CDocument
{
protected: // create from serialization only
	CMy1_7FFDoc();
	DECLARE_DYNCREATE(CMy1_7FFDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1_7FFDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void SetTitle(LPCTSTR lpszTitle);
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetRecParam();
	short vchannel[32];
	int	m_port;CString	m_ip;
	BOOL DeviceOpenStatus();
	void GetReadDatas(short* pBuffer,ULONG* nCounts);
	void SetParam(P_STRU_PARAM StructParam);
	void GetDeviceInfo(P_STRU_DEVICE_INFO DeviceInfo);
	BOOL ConnectDevice();
	virtual ~CMy1_7FFDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy1_7FFDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	STRU_PARAM deviceparam;
	STRU_DEVICE_INFO deviceinfo;
	HANDLE h1;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1_7FFDOC_H__BA2993DD_0768_4579_8DBB_A63181DA4B25__INCLUDED_)
