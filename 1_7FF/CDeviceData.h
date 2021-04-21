#pragma once

#include <iostream>
#include <string>
using namespace std;

class CDeviceData
{
	private:

	public:
		HANDLE h1;
		short * pBuffer,*copyBuffer;
		CDeviceData();
		~CDeviceData();
		char * GetData();
		UINT ContinusReading();
		


};