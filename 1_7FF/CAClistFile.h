#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include <string>

#define _F_PAC "pacs.txt"
using namespace std;
struct pac
{
	short starttime;
	short endtime;
	CString acname;
	CString accontext;
	short tag;
};
class CAClistFile
{
public:
	CAClistFile();
	~CAClistFile();
	void Readtols();
	void lsWriteto();
	void Addtols(short s,short e,CString an,CString ac,short tag);
	list<pac> ls;
	short num;
};