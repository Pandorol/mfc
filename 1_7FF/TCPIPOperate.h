// TCPIPOperate.h: interface for the CTCPIPOperate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TCPIPOPERATE_H__90925223_66E9_41C5_A88C_774ED2528D77__INCLUDED_)
#define AFX_TCPIPOPERATE_H__90925223_66E9_41C5_A88C_774ED2528D77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<winsock2.h>
class CTCPIPOperate  
{
public:
	int Recvfrom(CString& recvdata);
	void GetLocalIP(CString& s);
	BOOL Sendto(char*datas,int counts);
	BOOL Connect();
	struct sockaddr_in server_addr;
	int skt;
	WSADATA wsaData;
	WORD version;
	CTCPIPOperate();
	virtual ~CTCPIPOperate();

};

#endif // !defined(AFX_TCPIPOPERATE_H__90925223_66E9_41C5_A88C_774ED2528D77__INCLUDED_)
