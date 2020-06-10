#pragma once
class test11_ADTOfLinearList
{


	typedef char ElemType;
#define MaxSize 10;
	// constexpr auto MaxSize = 10;
	//线性表结构体定义
	typedef struct SqList {
		ElemType data[10]; //存放线性表的数据域
		int length;//存放线性表的长度
	};


	// 单链表节点*类型*定义

	// 声明一个节点，一个指针
	typedef struct LNode {
		ElemType data; // 数据域
		struct LNode* next; // 指针域
	}LNode, * LinkList;

	// 在定义时进行变量声明 - 声明一个结构体变量，一个结构体指针
	typedef struct SqL {
		ElemType data[10]; // 存放线性表的数据域
		int length;// 存放线性表的长度
	} sql1, * sql2;

	// 双链表节点*类型*定义
	typedef struct DNode {
		ElemType data;
		struct DNode* prior, * next; // 前驱和后继指针
	}DNode, * DLinkList;





public:

	bool insertOfSequenceList(SqList& L, int i, ElemType e);
	bool deleteOfSequenceList(SqList& L, int i, ElemType& e);
	int findElem(SqList L, ElemType e);


	LinkList creatListOfHeader(LinkList& L);
	LinkList creatListOfFinal(LinkList& L);
	LNode* getElemByNum(LinkList L, int i);
	LNode* findElemByValue(LinkList L, ElemType e);
	bool insertNode(LinkList L, int i, int x);
	bool insertNode2(LinkList L, int i, int x);
	bool deletdNode(LinkList L, int i);
	int getListLength(LinkList L);

	// 双链表
	DNode* creatDNodeList();
	void printDNode(DNode* L);
	bool insertDNode(DLinkList L, int i, int x);



	void classMain();
	void intiSqList(SqList*& L);
	void creatSqList(SqList*& L, ElemType a[], int n);
	bool listIsEmpty(SqList* L);
	bool listInsert(SqList* L, int i, ElemType e);
	int getSqListLength(SqList* L);
	ElemType getElement(SqList* L, int i);
};
