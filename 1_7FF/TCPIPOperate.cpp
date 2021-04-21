// TCPIPOperate.cpp: implementation of the CTCPIPOperate class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "1_7FF.h"
#include "1_7FFDoc.h"
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")

#include "TCPIPOperate.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTCPIPOperate::CTCPIPOperate()
{
	version = MAKEWORD(2, 0);
	skt = NULL;
	
	
}

CTCPIPOperate::~CTCPIPOperate()
{
	
	closesocket(skt); 
	WSACleanup(); 
}

BOOL CTCPIPOperate::Connect()
{
	WSAStartup(version, &wsaData);
	skt = socket(PF_INET,SOCK_STREAM,0);
	if(skt==-1)
	{
		//MessageBox("套接字创建失败！");
		return false;
	}
	server_addr.sin_family = AF_INET;
	CMy1_7FFDoc* Doc = (CMy1_7FFDoc*)(((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument());
	server_addr.sin_port = htons(Doc->m_port);
	server_addr.sin_addr.s_addr = inet_addr(Doc->m_ip);
	if (connect(skt, (sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) 
    { 
        //MessageBox("连接失败!"); 
        return false; 
    } 
	//MessageBox("连接成功!"); 
	return true;
}

BOOL CTCPIPOperate::Sendto(char *datas,int counts)
{
	if(send(skt,datas , counts, 0)==SOCKET_ERROR)
	{
		return false;
	}
	else
		return true;
}





void CTCPIPOperate::GetLocalIP(CString& s)
{
	WSAStartup(version, &wsaData);
	struct hostent *phostinfo = gethostbyname("");
	int i=0;
	
	char *pszAddr;CString addr[5];
	for(i = 0; NULL != phostinfo&& NULL != phostinfo->h_addr_list[i]; ++i)
	{
		pszAddr = inet_ntoa(*(struct in_addr *)phostinfo->h_addr_list[i]);
		addr[i].Format("%s",pszAddr);
	}
	s=addr[0];
}

int CTCPIPOperate::Recvfrom(CString &recvdata)
{
	char data[255];
	int ret = recv(skt,data,255,0);
	if(ret>0)
	{
		data[ret] = 0x00;
		CString s;
		s.Format("%s",data);
		recvdata=s;
	}
	return ret;
}
