#include "rtdb_struct.h"

#include <stdlib.h>

#define ROOT_PATH "XXX"

RTDB::RTDB()
{
	
}

RTDB::~RTDB()
{
	if(this_Dev)
	{
		delete this_Dev;
		this_Dev = NULL;
	}
		
	if(in_Dev)
	{
		delete []in_Dev;
		in_Dev = NULL;
	}
}

bool RTDB::init()
{
	char* path = getenv(ROOT_PATH);
	//
	int num = 10;
	for(int i = 0; i < num; ++i)
	{
		
	}
}

Device_st* RTDB::getDeviceById(int dev_id)
{
	if(dev_id == 0)
		return this_Dev;
	else
	{
		for(int i = 0; i < num_in_Dev; ++i)
		{
			if(in_Dev[i].id == dev_id)
				return &in_Dev[i];
		}
	}
	return NULL;
}

Device_st* RTDB::getDeviceByAddr(int dev_addr)
{
	if(dev_addr == -1)
		return this_Dev;
	else
	{
		for(int i = 0; i < num_in_Dev; ++i)
		{
			if(in_Dev[i].addr == dev_addr)
				return &in_Dev[i];
		}
	}
	return NULL;
}

bool RTDB::getData(int dev_id, DataType type, int id, void* pval)
{
	Device_st* pDev =  getDevice(dev_id);
	switch(type)
	{
		case YC:
			return getYC(pDev, id, pval);
			break;
		case YX:
			return getYX(pDev, id, pval);
			break;
		case YK:
		case YT:			
		default:
			return false;
	}
}

bool RTDB::getYC(int dev_id, int yc_id, float* pval)
{
	Device_st* dev =  getDevice(dev_id);
	if(dev == NULL)
		return false;
	for(int i = 0; i < dev->num_YC; ++i)
	{
		if(dev->yc_data[i].id == yc_id)
		{
			memcpy(pval, &(dev->yc_data[i].value), sizeof(float));
			return true;
		}
	}
	return false;
}

bool RTDB::getYC(Device_st* pDev, int yc_id, float* pval)
{
	if(pDev == NULL)
		return false;
	for(int i = 0; i < pDev->num_YC; ++i)
	{
		if(pDev->yc_data[i].id == yc_id)
		{
			memcpy(pval, &(pDev->yc_data[i].value), sizeof(float));
			return true;
		}
	}
	return false;
}

bool RTDB::getYX(int dev_id, int yx_id, int* pval)
{
	Device_st* dev =  getDevice(dev_id);
	if(dev == NULL)
		return false;
	for(int i = 0; i < dev->num_YX; ++i)
	{
		if(dev->yx_data[i].id == yx_id)
		{
			memcpy(pval, &(dev->yx_data[i].value), sizeof(int));
			return true;
		}
	}
	return false;
}

bool RTDB::getYX(Device_st* pDev, int yc_id, int* pval)
{
	if(pDev == NULL)
		return false;
	for(int i = 0; i < pDev->num_YX; ++i)
	{
		if(pDev->yx_data[i].id == yx_id)
		{
			memcpy(pval, &(pDev->yx_data[i].value), sizeof(int));
			return true;
		}
	}
	return false;
}



