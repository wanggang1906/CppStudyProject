#pragma once
class test11_ADTOfLinearList
{


	typedef char ElemType;
	//线性表结构体定义
	typedef struct SqList {
		ElemType data[10]; //存放线性表的数据域
		int length;//存放线性表的长度
	};



public:
	void classMain();
	void intiSqList(SqList*& L);
	void creatSqList(SqList*& L, ElemType a[], int n);
	bool listIsEmpty(SqList* L);
	bool listInsert(SqList* L, int i, ElemType e);
	int getSqListLength(SqList* L);
	ElemType getElement(SqList* L, int i);
};
