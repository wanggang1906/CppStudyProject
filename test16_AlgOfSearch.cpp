#include "test16_AlgOfSearch.h"
#include <iostream>
#include <string>

// 查找算法
// 线性结构
//		顺序查找 - 线性查早，从线性表的一端开始，逐个检查关键字是否满足给的的条件，
//		分块查找
//		折半查找
// 树形结构
//		二叉排序树
//		二叉平衡树
//		B树
//		B+树
// 散列结构
//		Hash散列
// 查找的效率指标
//		平均查找长度
// 字符串模式匹配
// 查找算法的应用
//


void test16_AlgOfSearch::classMain()
{
	std::cout << "test16_AlgOfSearch" << "\n";
}



// 一般线性表的顺序查找
int test16_AlgOfSearch::searchSeq(SSTable st, ElemType key)
{
	// 在顺序表st中顺序查找关键字为key的元素，若找到则返回该元素在表中的位置
	st.elem[0] = key; // 0号位置作为哨兵
	for (int i = st.TableLen; st.elem[i] != key; --i) // 从后往前找
	{
		return i; // 若表中不存在关键字为key的元素，将查找到i为0时退出for循环
	}
}

// 折半查找 - (二分查找)
int test16_AlgOfSearch::binarySearch(SeqList l, ElemType key)
{
	// 在有序表l中查找关键字为key的元素，若存在则返回其位置，不存在则返回-1
	int low = 0, high = l.TableLen - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2; // 取中间位置
		if (l.elem[mid] == key)
			return mid; // 查找成功则返回所在位置
		else if (l.elem[mid] > key)
			high = mid - 1; // 从前半部分继续查找
		else
			low = mid + 1; // 从后半部分继续查找
	}
	return -1; // 不存在返回-1
}


// 分块查找 - （索引顺序查找=顺序查找+折半查找）
int test16_AlgOfSearch::blockSearch(SeqList l, ElemType key)
{
	// 快内元素无序，块间有序
	return 0;
}

// B树 - (多路平衡查找树)


// B+树 - 



// Hash散列表


// 字符串模式匹配
// 普通模式匹配算法
int test16_AlgOfSearch::indexOfStr()
{
	return 0;
}

// 改进模式匹配算法 - KMP
int test16_AlgOfSearch::KMPIndexOfStr()
{
	return 0;
}

// KMP算法的next函数
void test16_AlgOfSearch::getNextOfKMP(char t[], int next[])
{
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i <= t[0])
	{
		if (j == 0 || t[i] == t[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}
