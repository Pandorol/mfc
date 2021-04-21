#include "stdafx.h"
#include "CInfoFile.h"

CInfoFile::CInfoFile()
{
}
CInfoFile::~CInfoFile()
{
}
void CInfoFile::ReadAcs()
{
	ifstream ifs(_F_AC);
	char buf[1024] = {0};
	num=0;
	char *sst;
	ls.clear();
	ac temp;
	while (!ifs.eof()) //没到文件结尾
	{
		ifs.getline(buf, sizeof(buf));
		
		sst = strtok(buf, "|");
		if (sst != NULL)
		{
			temp.acname.Format("%s",sst);
		}
		else
		{
			break;
		}
		sst = strtok(NULL, "|");
		temp.accontext.Format("%s",sst);
		sst = strtok(NULL, "|");
		temp.tag = atoi(sst);

		ls.push_back(temp);
		num++;
	}
	ifs.close();
}
void CInfoFile::WriteAcs()
{
	ofstream ofs(_F_AC);
	if (ls.size() > 0)
	{
		for (list<ac>::iterator it = ls.begin(); it != ls.end(); it++)
		{
			//ofs<<it->acname<<"|";		
			//ofs<<it->accontext<<endl;
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
void CInfoFile::AddAcs(CString name,CString context,short tag)
{
	ac temp;
	temp.acname.Format("%s",name);
	temp.accontext.Format("%s",context);
	temp.tag = tag;
	//temp.acname = name;
	//temp.accontext = context;
	ls.push_back(temp);

}