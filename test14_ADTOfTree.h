#pragma once
#include"test12_ADTOfStack.h"
#include <cstddef>

// test14公有继承test12
class test14_ADTOfTree :test12_ADTOfStack
{
	typedef int ElemType;
	// 二叉树的存储

	// 顺序存储 - 用数组存
	typedef int BinaryTreeArray[100];

	//typedef struct SqStack {
	//	ElemType data[10];
	//	int top; // 栈顶指针
	//};
	// 链栈
	//typedef struct LinkStackNode {
	//	ElemType data;
	//	struct LinkStackNode* next; // 指针域
	//} *LiStack;

	// 链式存储 - 二叉链表
	typedef struct BinaryTreeNode {
		ElemType data;
		struct BinaryTreeNode* lchild, * rchild; // 左/右孩子指针
	}BiTNode, * BiTree;


	// 线索二叉树结点 - 线索链表
	typedef struct ThreadBinaryTree {
		ElemType data;
		struct ThreadBinaryTree* lchild, * rchild;
		int ltag, rtag; // 左，右线索标志,0孩子，1线索
	} ThreadNode, * ThreadTree;

	// 全局变量pre，指向当前访问节点的前驱
	ThreadNode* pre = NULL;


	// **树的存储**
	// 双亲表示法
	typedef struct PTNode {
		ElemType data;
		int parent; // 双亲位置域
	}PTNode;

	typedef struct PTree {
		PTNode nodes[100];
		int n; // 节点数
	};
	// 孩子表示法

	// 孩子兄弟表示法
	typedef struct CSNode {
		ElemType data;
		struct CSNode* firstChild, * nextRightBrother; // 第一个孩子/右兄弟指针
	} CSNode, * CSTree;


	// 并查集
	// int UFSets[100];
	int UnionFindSets[100]; // 集合元素数组(双亲指针数组)
	// :public test12_ADTOfStack



public:
	//test12_ADTOfStack::test12_ADTOfStack();

	void classMain();

	// 顺序
	void createBinaryTreeByArray(BinaryTreeArray& t);

	// 链式
	void createLinkBinaryTree(BiTree& t);
	void printTreeRootElem(BiTree t);
	void preferenceOrderOfLinkBiTree(BiTree t);
	void preferenceOrderOfLinkBiTree2(BiTree t);
	void midOrderOfLinkBiTree(BiTree t);
	void midOrderOfLinkBiTree2(BiTree t);
	void finallyOrderOfLinkBiTree(BiTree t);
	void finallyOrderOfLinkBiTree2(BiTree t);
	void layerOrderOfLinkBiTree(BiTree t);

	void binaryTreeInThread(ThreadTree t, ThreadTree& pre);
	void binaryTreeVisit(ThreadNode* q, ThreadTree& pre);
	void createMidThreadBinaryTree2(ThreadTree t);
	void binaryTree2ThreadBinaryTree(ThreadTree& p, ThreadTree& pre);

	// 中序线索化 - 递归法
	void inThread(ThreadTree& p, ThreadTree& pre);

	void createMidThreadBinaryTree(ThreadTree t);

	// 并查集
	void initUFSet(int s[]);
	int findOfUFSet(int s[], int x);
	void unionOfUFSet(int s[], int root1, int root2);
};
