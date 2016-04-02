#ifndef RTDB_STRUCT_H_
#define	RTDB_STRUCT_H_
/*
-----device-----YC
			|
			----YX
			|
			----YK
			|
			----YT
			
*/
struct YC_st
{
	int    	id;
	float  	value;
	int		yt_index;
	char   	status;  	//正常 0 、置数 1、……
	char	q;			//品质： 旧数据 0
	char	rsv[2];		//保留
};

struct YX_st
{
	int    	id;
	int  	value;
	int 	yk_index;
	char   	status;
	char	q;
	char	rsv[2];	
};

struct YK_st
{
	int    	id;
	int  	value;
	int		yx_index;
	char   	status;
	char	q;
	char	rsv[2];	
};

struct YT_st
{
	int    	id;
	float  	value;
	int		yc_index;
	char   	status;
	char	q;
	char	rsv[2];	
};

struct Device_st
{
	int		id;
	int		addr;
	int		num_YC;
	int		num_YX;
	int 	num_YK;
	int		num_YT;
	YC_st	*yc_data;
	YX_st	*yx_data;
	YK_st	*yk_data;
	YT_st	*yt_data;
};

struct Virtual_Device_st
{
	int		id;
	int		des_addr;
	
};

class RTDB
{
public:
	RTDB();
	~RTDB();
	
	enum DataType{YC=0,YX,YK,YT};
	
	bool init();
	bool init_this_Dev();
	bool init_in_Dev();
	bool init_virtual_Dev();
	
	bool getData(int dev_id, DataType type, int id, void* pval);
	
	bool getYC(int dev_id, int yc_id, float*);
	bool getYC(Device_st* pDev, int yc_id, float*);
	bool setYC(int dev_id, int yc_id, const float val);
	
	bool getYX(int dev_id, int yx_id, int*);
	bool getYX(Device_st* pDev, int yx_id, int*);
	bool setYX(int dev_id, int yx_id, const int val);
	
	bool setYK(int dev_id, int yk_id, const int val);
	bool setYT(int dev_id, int yt_id, const float val);
	
	Device_st* getDeviceById(int dev_id);
	Device_st* getDeviceByAddr(int dev_id);

private:
	Device_st	*this_Dev;
	Device_st	*in_Dev;
	int			num_in_Dev;
};

#endif