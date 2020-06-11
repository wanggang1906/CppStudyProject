#pragma once
class test14_ADTOfTree
{
	typedef int ElemType;

	// 顺序存储

	// 链式存储
	typedef struct BinaryTreeNode {
		ElemType data;
		struct BinaryTreeNode* lchild, * rchild; // 左/右孩子指针
	}BiTNode, * BiTree;


	// 树的存储
	// 双亲表示法

	// 孩子表示法

	// 孩子兄弟表示法




public:
	void classMain();
};
