// 1_7FFDoc.cpp : implementation of the CMy1_7FFDoc class
//

#include "stdafx.h"
#include "1_7FF.h"
#include "EEGAMP.h"
#pragma comment(lib,"EEGAMP.lib")
#include "1_7FFDoc.h"
#include "ConnectDeviceDialog.h"
#include "TCPIPOperate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy1_7FFDoc

IMPLEMENT_DYNCREATE(CMy1_7FFDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy1_7FFDoc, CDocument)
	//{{AFX_MSG_MAP(CMy1_7FFDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1_7FFDoc construction/destruction

CMy1_7FFDoc::CMy1_7FFDoc()
{
	// TODO: add one-time construction code here
	ConnectDevice();
	int i;
	for(i=0;i<32;i++)
	{
		vchannel[i] = 1;
	}
	m_port = 50001;
	//m_ip = "192.168.191.2";
	CTCPIPOperate op;
	op.GetLocalIP(m_ip);
	
}

CMy1_7FFDoc::~CMy1_7FFDoc()
{
}

BOOL CMy1_7FFDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMy1_7FFDoc serialization

void CMy1_7FFDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMy1_7FFDoc diagnostics

#ifdef _DEBUG
void CMy1_7FFDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy1_7FFDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy1_7FFDoc commands

BOOL CMy1_7FFDoc::ConnectDevice()
{
	h1 = OpenDevice();
	if(h1==INVALID_HANDLE_VALUE)
	{
		return false;
	}
	else
	{
		return true;
	}
	
}

void CMy1_7FFDoc::GetDeviceInfo(P_STRU_DEVICE_INFO DeviceInfo)
{
	deviceinfo = ReadDeviceInfo(h1);
	DeviceInfo->nDeviceID = deviceinfo.nDeviceID;
	DeviceInfo->nRouteNum = deviceinfo.nRouteNum;
	DeviceInfo->nSwitchNo = deviceinfo.nSwitchNo;
	DeviceInfo->nType = deviceinfo.nType;
}

void CMy1_7FFDoc::SetParam(P_STRU_PARAM StructParam)
{
	deviceparam.nGateOfJam = StructParam->nGateOfJam;
	deviceparam.nHightFre = StructParam->nHightFre;
	deviceparam.nHold1 = StructParam->nHold1;
	deviceparam.nModeOfSign = StructParam->nModeOfSign;
	deviceparam.nHold2 = StructParam->nHold2;
	deviceparam.nSenseDegree = StructParam->nSenseDegree;
	deviceparam.nTimeConstant = StructParam->nTimeConstant;
	deviceparam.nWorkFre = StructParam->nWorkFre;
	WriteParam(h1,deviceparam);
	
}

void CMy1_7FFDoc::GetReadDatas(short *pBuffer, ULONG *nCounts)
{
	ReadData(h1,pBuffer,nCounts);
}

BOOL CMy1_7FFDoc::DeviceOpenStatus()
{
	if(h1==INVALID_HANDLE_VALUE)
	{
		return false;
	}
	return true;
}

void CMy1_7FFDoc::SetRecParam()
{
	deviceparam.nGateOfJam = 127;
	deviceparam.nHightFre = 50;
	deviceparam.nHold1 = 0;
	deviceparam.nModeOfSign = 1;
	deviceparam.nHold2 = 0;
	deviceparam.nSenseDegree = 0;
	deviceparam.nTimeConstant = 30;
	deviceparam.nWorkFre = 50;
	WriteParam(h1,deviceparam);
}

void CMy1_7FFDoc::SetTitle(LPCTSTR lpszTitle) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CDocument::SetTitle("MIEEG同步采集系统");
}
