#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include <string>

#define _F_AC "acs.txt"
using namespace std;

struct ac
{
	CString acname;
	CString accontext;
	short tag;
};
class CInfoFile
{
public:
	CInfoFile();
	~CInfoFile();
	void ReadAcs();
	void WriteAcs();
	void AddAcs(CString name,CString context,short tag);
	list<ac> ls;
	short num;


};