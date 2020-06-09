#include "test11_ADTOfLinearList.h"
#include <iostream>
#include <string>

// 线性表 - 顺序表，链表

// 链表和数组的区别
// 数组在编译时就需知道大小。数组在内存中是以相同的距离间隔隔开的
// 链表是节点的集合，节点中储存着数据并连接到其他的节点

// 链表分类
//		顺序表
//		链表
//			单向链表 - 如果一个节点将指向另外一个节点的指针作为数据成员，那么多个这样的节点可以连接起来，只用一个变量就能够访问整个节点序列。
//			双向链表
//			循环链表


void test11_ADTOfLinearList::classMain()
{
	std::cout << "test11_ADTOfLinearList" << "\n";
}


//【1】、初始化线性表L
void test11_ADTOfLinearList::intiSqList(SqList*& L)
{
	printf("【1】初始化线性表L进来了！\n");
	L = (SqList*)malloc(sizeof(SqList));//为线性表分配空间
	L->length = 0;//设为空的线性表
	printf("初始化线性表L的长度为：");
	printf("%d\n", L->length);
}


//【2】整体建立顺序表
void test11_ADTOfLinearList::creatSqList(SqList*& L, ElemType a[], int n)
{
	printf("【2】建立顺序表线性表的 方法进来了！\n");
	L = (SqList*)malloc(sizeof(SqList));//为线性表分配空间
	for (int i = 0; i < n; i++) {
		L->data[i] = a[i];
	}
	L->length = n;
	printf("建立顺序表线性表的长度为：");
	printf("%d\n", L->length);
}
//【3】、判断线性表是否为空的线性表
bool test11_ADTOfLinearList::listIsEmpty(SqList* L)
{
	printf("【3】判断线性表是否为空的线性表进来了！\n");

	if (L->length == 0) {
		printf("线性表为空！\n");
	}
	else {
		printf("线性表不为空！\n");
	}
	return (L->length == 0);
}
//【4】、在第i个位置插入元素e
bool test11_ADTOfLinearList::listInsert(SqList* L, int i, ElemType e)
{
	//先判断要插入的位置是否合法，如果合法则进行查找到该位置，然后i后面的元素从右向左的顺序全部向右移动一个位置
	printf("【4】在第i个位置插入元素e的方法进来了！\n");
	if (i<-1 || i> L->length) {
		return false;
	}
	//先进性移动，最后在i的位置进行赋值即可
	L->length = L->length + 1;
	for (int j = i; j < L->length + 1; j++) {
		L->data[L->length] = L->data[L->length - 1];
	}
	L->data[i] = e;
	return true;
}
//【5】、求线性表的长度
int test11_ADTOfLinearList::getSqListLength(SqList* L)
{
	printf("【5】求线性表的长度的方法进来了！\n");
	printf("线性表的长度为：");
	printf("%d\n", L->length);
	return L->length;
}
//【6】、求线性表中的第i个元素
// 结构体作为返回值，实现的时候需指明所属类
test11_ADTOfLinearList::ElemType test11_ADTOfLinearList::getElement(SqList* L, int i)
{
	printf("【6】求线性表中的第i个元素的方法进来了！\n");
	printf("线性表的长度为：%d\n", L->length);
	printf("查询线性表第几个位置的元素：%d\n", i);
	int count = 0;
	count = i;
	printf("count的值为：%d\n", count);
	ElemType  e;
	if (i<1 || i>L->length - 1) {
		printf("查找元素不存在");
		return false;
	}
	else {
		e = L->data[i];
	}
	printf("查找的第2个元素为：%d\n", L->data[2]);
	printf("查找的第i个元素为：%d\n", L->data[i]);
	return e;
}
