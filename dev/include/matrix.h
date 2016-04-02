#ifndef CMATRIX_H_
#define CMATRIX_H_

//行优先存储 1 
class CMatrix
{
public:
	CMatrix();
	CMatrix(int rowNum,int colNum);
	~CMatrix();
	
	bool getElement(int rowId, int colId, float *element);
	//bool getRowElement(int row,std::vector<int> &ielevt);
	
private:
	int		m_iRowNum;
	int		m_iColNum;
	float 	*_data;
};

#endif