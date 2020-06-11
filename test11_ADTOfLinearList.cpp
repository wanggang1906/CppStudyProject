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
//			静态链表 - 静态数组


// 一些语法，函数
// @1 - new/delete是C++的操作符，而malloc/free是C中的函数
// @2 - new做两件事，一是分配内存，二是调用类的构造函数；同样，delete会调用类的析构函数和释放内存。而malloc和free只是分配和释放内存
// @3 - new建立的是一个对象，而malloc分配的是一块内存；new建立的对象可以用成员函数访问，不要直接访问它的地址空间；malloc分配的是一块内存
//			区域，用指针访问，可以在里面移动指针；new出来的指针是带有类型信息的，而malloc返回的是void指针
// exit() - 进程退出
// friend 类型 函数名(形参) - 友元函数

void test11_ADTOfLinearList::classMain()
{
	std::cout << "test11_ADTOfLinearList" << "\n";
	// 顺序表
	//SqList sequenceList;
	//sequenceList = this->createSequenceList();
	//this->printSequenceList(sequenceList);
	//this->insertOfSequenceList(sequenceList, 3, 9);
	//this->printSequenceList(sequenceList);
	//ElemType e = 999;
	//this->deleteOfSequenceList(sequenceList, 3, e);
	//std::cout << "被删除的元素为：" << e << "\n";
	//std::cout << "查找的元素位序为：" << this->findElem(sequenceList, 2) << "\n";

	// 单链表
	LinkList linkList, lList;
	lList = this->createListOfHead(linkList);
	this->printList(lList);



	// 双链表

}

// 顺序表的基本操作
// 建立顺序表 - 先初始化length=0，再赋值data[]
test11_ADTOfLinearList::SqList test11_ADTOfLinearList::createSequenceList()
{
	int sequenceListLength = 5;
	SqList L;
	L.length = 0;
	for (int i = 0; i < sequenceListLength; i++)
	{
		L.data[i] = i;
		L.length++;
	}
	return L;
}

// 插入 - 把e插入到L的第i个位置
bool test11_ADTOfLinearList::insertOfSequenceList(SqList& L, int i, ElemType e)
{
	// 判断i是否有效 - i的范围在顺序表的合理范围内
	if (i<1 || i>L.length + 1)
	{
		return false;
	}
	// 判断顺序表是否已满
	if (L.length == 10)
	{
		return false;
	}
	// 后移length-i个元素
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	// 插入
	L.data[i - 1] = e;
	// 表长+1
	L.length++;
	return true;
}

// 删除 - 删除i位置的元素，e接受要删除的元素
bool test11_ADTOfLinearList::deleteOfSequenceList(SqList& L, int i, ElemType& e)
{
	// 判断删除位置有效
	if (i<1 || i>L.length)
	{
		return false;
	}
	// 把要删除的元素赋值给e
	e = L.data[i - 1];
	// 后续元素前移
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	// 长度-1
	L.length--;
	return true;
}

// 按值查找 - 顺序查找，并返回元素位序
int test11_ADTOfLinearList::findElem(SqList L, ElemType e)
{
	// 从头开始遍历链表，若data域相等，则返回元素位置(位序)，不存在则返回0
	for (int j = 0; j <= L.length; j++)
	{
		if (e == L.data[j])
		{
			// 下标位j的元素值等于呃，返回其位序j + 1
			return j + 1;
		}
	}
	return 0;
}

// 打印顺序表 - 顺序表从0开始计数
void test11_ADTOfLinearList::printSequenceList(SqList& L)
{
	// 
	for (int i = 0; i < L.length; i++)
	{
		std::cout << L.data[i] << " ";
	}
	std::cout << "顺序表打印完毕" << "\n";
}




// 单链表的基本操作

// 头插法建立单链表 - 从表尾到表头逆向建立单链表L，每次均在头节点之后插入元素
test11_ADTOfLinearList::LinkList test11_ADTOfLinearList::createListOfHead(LinkList& L)
{
	LNode* s;
	int x;
	// 创建头节点
	L = (LinkList)malloc(sizeof(LNode));
	// 初始链表为空
	L->next = NULL;
	// 输入节点值，为9999表示结束
	scanf_s("%d", &x);
	while (9999 != x)
	{
		// 创建新节点
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s; // 将新节点插入表中，L为头指针
		scanf_s("%d", &x);
	}
	return L;
}

// 打印链表 - 从头节点开始，一次遍历输出链表
// 有/无头节点，会影响第一个输出，
// 头/尾插法会影响输出的顺序
void test11_ADTOfLinearList::printList(LinkList& L)
{
	LNode* p = L;
	p->next = L->next;
	// 第一个节点，数据域没有利用的和有利用的
	// 输出中间节点
	while (p->next != NULL)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	// 输出最后一个节点
	if (p->next == NULL)
	{
		std::cout << p->data << "\n";
	}
	std::cout << "链表打印完毕" << "\n";
}

// 尾插法建立单链表
test11_ADTOfLinearList::LinkList test11_ADTOfLinearList::createListOfFinal(LinkList& L)
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode* s, * r = L;
	scanf_s("%d", &x);
	while (999 != x)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf_s("%d", &x);
	}
	r->next = NULL;
	return L;
}


// 按序号查找节点值
test11_ADTOfLinearList::LNode* test11_ADTOfLinearList::getElemByNum(LinkList L, int i)
{
	int j = 1;
	LNode* p = L->next;
	if (i == 0)
	{
		return L;
	}
	if (i < 1)
	{
		return NULL;
	}
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}


// 按值查找表节点
test11_ADTOfLinearList::LNode* test11_ADTOfLinearList::findElemByValue(LinkList L, ElemType e)
{
	LNode* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}


// 插入节点操作 - 将值为x的新节点，插入到单链表的第i个位置上
bool test11_ADTOfLinearList::insertNode(LinkList L, int i, int x)
{
	LNode* newNode;
	// 检查插入位置的有效 - 如何获得链表总长度
	if (i < 1)
	{
		return false;
	}
	// 定义一个新节点
	newNode = (LNode*)malloc(sizeof(LNode));
	newNode->data = x;
	// 创建指向头节点的指针
	LNode* p = L->next;
	// 找到插入位置的前驱节点i-1
	int j = 1;
	while (j <= i - 1)
	{
		p = p->next;
		j++;
	}
	// 新节点插入到前驱
	newNode->next = p->next;
	// 旧的后续节点插入到新节点后
	p->next = newNode;
	return true;
}

bool test11_ADTOfLinearList::insertNode2(LinkList L, int i, int x)
{
	LNode* p; // 一个指针，一个新的数据节点
	LNode* s;
	s = (LNode*)malloc(sizeof(LNode));
	s->data = x;

	// 判断插入位置合法
	if (i < 1)
	{
		return false;
	}

	p = this->getElemByNum(L, i - 1);
	s->next = p->next;
	p->next = s;
	return true;
}

// 删除节点操作
bool test11_ADTOfLinearList::deletdNode(LinkList L, int i)
{
	LNode* p;
	LNode* q;
	// 判断删除位置合法
	if (i < 1)
	{
		return false;
	}
	// p指针指向要删除的位置i-1
	p = this->getElemByNum(L, i - 1);
	// q指向要删除的节点
	q = p->next;
	// 将*q节点从链中断开
	p->next = q->next;
	// 释放q节点
	free(q);
	return true;
}

// 求表长操作 - 单链表的表长不包含头节点，所以不带头和带头节点的计算发放略有不同，不带头的表为空时要单独处理
int test11_ADTOfLinearList::getListLength(LinkList L)
{
	int ListLength = 0;
	LNode* p = NULL;
	p->next = L->next;
	// 带头节点
	while (p->next != NULL)
	{
		p = p->next;
		ListLength++;
	}
	return ListLength;
}


// 双链表

// 创建双链表
test11_ADTOfLinearList::DNode* test11_ADTOfLinearList::createDNodeList()
{
	DNode* head, * p, * s;
	int x, cycle = 1;
	head = (DNode*)malloc(sizeof(DNode));
	p = head;
	while (cycle)
	{
		std::cout << "输入数据：" << "\n";
		std::cin >> x;
		if (x != 0)
		{
			s = (DNode*)malloc(sizeof(DNode));
			s->data = x;
			p->next = s;
			s->prior = p;
			p = s;
		}
		else
			cycle = 0;
	}
	head = head->next;
	head->prior = NULL;
	p->next = NULL;
	return head;
}

// 打印链表
void test11_ADTOfLinearList::printDNode(DNode* head)
{
	DNode* p, * s;
	p = head;
	std::cout << "打印链表" << "\n";
	while (p->next != NULL)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << p->data << "\n";
	std::cout << "逆序打印双链表" << "\n";
	while (p->prior != NULL)
	{
		std::cout << p->data << " ";
		p = p->prior;
	}
	std::cout << p->data << "\n";
}

// https://blog.csdn.net/cfan0801/article/details/7350541?utm_source=blogxgwz0

// 双链表的插入操作
bool test11_ADTOfLinearList::insertDNode(DLinkList L, int i, int x)
{
	DNode* p, * s = NULL;
	s->data = x;
	// 判断插入位置合法
	if (i < 1)
	{
		return false;
	}
	// p指向插入位置i-1

	// 
}

// 双链表的删除操作 - 删除i位序的元素x
bool test11_ADTOfLinearList::deleteDNode(DLinkList L, int i, int x)
{
	return true;
}

// 按值查找/按位查找等同于单链表


// 循环链单链表
// 建立循环单链表
bool test11_ADTOfLinearList::createSingleCycleList()
{
	return true;
}

// 循环双链表
bool test11_ADTOfLinearList::createDoubleCycleList()
{
	return true;
}

// 静态链表 - 借助数组描述线性表的链式存储结构，指针域为相对地址(数组下标，又叫游标)，和顺序表相似，要预先分配连续的空间
// 创建静态链表
bool test11_ADTOfLinearList::createStaticList()
{
	return true;
}



// 链表的基本操作

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
void test11_ADTOfLinearList::createSqList(SqList*& L, ElemType a[], int n)
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
