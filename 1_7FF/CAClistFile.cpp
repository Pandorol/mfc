#include "stdafx.h"
#include "CAClistFile.h"

CAClistFile::CAClistFile(){}
CAClistFile::~CAClistFile(){}

void CAClistFile::Readtols()
{
	ifstream ifs(_F_PAC);
	char buf[1024] = {0};
	num=0;
	char *sst;
	ls.clear();
	pac temp;
	while (!ifs.eof()) //没到文件结尾
	{
		ifs.getline(buf, sizeof(buf));
		
		sst = strtok(buf, "|");
		if (sst != NULL)
		{
			temp.starttime = atoi(sst);
		}
		else
		{
			break;
		}
		sst = strtok(NULL, "|");
		temp.endtime = atoi(sst);
	
		sst = strtok(NULL, "|");
		temp.acname.Format("%s",sst);

		sst = strtok(NULL,"|");
		temp.accontext.Format("%s",sst);
		
		sst = strtok(NULL, "|");
		temp.tag = atoi(sst);

		ls.push_back(temp);
		num++;
	}
	ifs.close();

}
void CAClistFile::lsWriteto()
{
	ofstream ofs(_F_PAC);
	if (ls.size() > 0)
	{
		for (list<pac>::iterator it = ls.begin(); it != ls.end(); it++)
		{
			//ofs<<it->acname<<"|";		
			//ofs<<it->accontext<<endl;
			ofs<<it->starttime;
			ofs.write("|",strlen("|"));
			ofs<<it->endtime;
			ofs.write("|",strlen("|"));
			ofs.write(it->acname,strlen(it->acname));
			ofs.write("|",strlen("|"));
			ofs.write(it->accontext,strlen(it->accontext));
			ofs.write("|",strlen("|"));
			ofs<<it->tag;
			ofs.write("\n",strlen("\n"));
		}
	}
	ofs.close();
}
void CAClistFile::Addtols(short s,short e,CString an,CString ac,short tag)
{
	pac temp;
	temp.starttime =s;
	temp.endtime = e;
	temp.acname.Format("%s",an);
	temp.accontext.Format("%s",ac);
	temp.tag = tag;
	ls.push_back(temp);
}