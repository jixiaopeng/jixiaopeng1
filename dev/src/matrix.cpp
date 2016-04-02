#include "matrix.h"

CMatrix::CMatrix()
{
	m_iRowNum = 0;
	m_iColNum = 0;
	_data = NULL;
}

CMatrix::CMatrix(int rowNum,int colNum)
{
	m_iRowNum = rowNum;
	m_iColNum = colNum;
	_data = new float[rowNum*colNum];
	memset(_data, 0, sizeof(float)*rowNum*colNum);
}

CMatrix::~CMatrix()
{
	if(_data)
		delete []_data;
	m_iRowNum = 0;
	m_iColNum = 0;
	_data = NULL;
}

bool CMatrix::getElement(int rowId, int colId, float *element)
{
	if((rowId<1)||(rowId>rowNum)||(colId<1)||(colId>colNum))
		return false;
	*element = _data[(rowId-1)*colNum+colId-1];
	return true;
}