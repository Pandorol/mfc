#include "stdafx.h"
#include "CDeviceData.h"
#include "EEGAMP.h"
#pragma comment(lib,"EEGAMP.lib")
CDeviceData::CDeviceData()
{
	h1 = OpenDevice();
}
CDeviceData::~CDeviceData(){}