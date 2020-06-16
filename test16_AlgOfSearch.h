#include <string>

#pragma once
class test16_AlgOfSearch
{
	typedef int ElemType;

	// 一般线性表的顺序查找
	typedef struct SSTable { // 查找表的数据结构
		ElemType* elem; // 元素存储空间基址，建表时按实际长度分配，0号单源留空
		int TableLen; // 表的长度
	};

	typedef struct SeqList {
		ElemType* elem;
		int TableLen;
	};


public:
	void classMain();

	int searchSeq(SSTable st, ElemType key);

	int binarySearch(SeqList l, ElemType key);
	int blockSearch(SeqList l, ElemType key);

	int indexOfStr(std::string s, std::string t);
	int KMPIndexOfStr(std::string t, std::string p);
	void getNextOfKMP(char t[], int next[]);
	int* getNextOfKMP2(std::string p);
};
