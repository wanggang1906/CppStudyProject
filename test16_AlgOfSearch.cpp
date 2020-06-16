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
//			散列函数
//				直接定址法 - 线性函数
//				除留余数法 - p不大于，接近总长m，则H(key) = key % p
//				数字分析法 - 
//				平方取中法
//				折叠法
//			解决冲突的方法
//				开放定址法 - 可存放新表项的空闲地址，即向它的同义词表现开放，又向它的非同义词表项开发
//					线性探测法 - 查看下一个空闲单元
//					平方探测法 - 下一位序平方空闲单元
//					再散列法 - 双散列法，两个散列函数
//					伪随机序列法 - di=伪随机序列
//				拉链法 - 所有同义词存储在一个线性表中，使用于经常要进行插入，删除的操作
// 查找的效率指标
//		平均查找长度
// 字符串模式匹配 - 求第一个字符串(模式串)在第二个字符串(主串)中的位置
//		
// 查找算法的应用
//


void test16_AlgOfSearch::classMain()
{
	std::cout << "test16_AlgOfSearch" << "\n";

	// KMP
	std::string themeStr = "abcefabcdef";
	std::string patternStr = "abcd";
	int result = this->KMPIndexOfStr(themeStr, patternStr);
	std::cout << "模式串的位置为：" << result << "\n";

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
// 普通简单的模式匹配算法 - 返回模式串在主串中的位置
// s - 主串，t - 模式串
int test16_AlgOfSearch::indexOfStr(std::string s, std::string t)
{
	int i = 1, j = 1;
	while (i <= s[0] && j <= t[0])
	{
		if (s[i] == t[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > t[0])
		return i - t[0];
	else
		return 0;
}

// 改进模式匹配算法 - KMP
int test16_AlgOfSearch::KMPIndexOfStr(std::string t, std::string p)
{
	int i = 0, j = 0;
	int* next = this->getNextOfKMP2(t);
	while (i < (int)t.length() && j < (int)p.length())
	{
		if (j == -1 || t[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}

	}
	if (j == (int)p.length())
	{
		return i - j;
	}
	return -1;
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

// kmp的next函数
// 在主串中找next位置
int* test16_AlgOfSearch::getNextOfKMP2(std::string p)
{
	int* next = new int[p.length()];
	next[0] = -1;
	int j = 0, k = -1;
	while (j < (int)p.length() - 1)
	{
		if (k == -1 || p[j] == p[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
	return next;
}
