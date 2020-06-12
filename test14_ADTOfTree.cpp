#include "test14_ADTOfTree.h"
#include <iostream>
#include <string>


// 树 - 二叉树，森林及其使用
// 


void test14_ADTOfTree::classMain()
{
	std::cout << "test14_ADTOfTree" << "\n";
	// 顺序存储
	BinaryTreeArray newBiTreeArray;
	//this->createBinaryTreeByArray(newBiTreeArray);

	BiTree newTree;
	this->createLinkBinaryTree(newTree);
}



// 二叉树

// 满二叉树

// 完全二叉树

// 二叉排序树

// 平衡二叉树

// **二叉树**
// *顺序存储*
// 创建二叉树 - 按提示输入左右个孩子节点，（输入9999表示创建完毕 - X）
void test14_ADTOfTree::createBinaryTreeByArray(BinaryTreeArray& t)
{

	int TREE_ELEM_COUNT = 10;
	int TreeLength = TREE_ELEM_COUNT;
	for (int i = 0; i < TREE_ELEM_COUNT; i++)
	{
		if (2 * i <= TreeLength)
		{
			std::cout << "请输入left_child节点：" << "\n";
			std::cin >> t[2 * i];
		}
		else
			// 该节点没有数据 - 无法根据输入判是否有数据
			t[2 * i] = NULL;
		if (2 * i + 1 <= TreeLength)
		{
			std::cout << "请输入right_child节点：" << "\n";
			std::cin >> t[2 * i + 1];
		}
		else
			t[2 * i + 1] = NULL;
	}
	std::cout << "顺序存储的二叉树创建完成" << "\n";


}



// *链式存储*
// 创建链式存储的二叉树 - 递归法
// 先判断输入不为99，否则表示创建结束
// 创建一个新节点，数据域为输入值
// 对左孩子指针域调用create函数
// 对右孩子指针域调用create函数
void test14_ADTOfTree::createLinkBinaryTree(BiTree& t) // 要改变指针，所以要吧指针传进来，相当于指针的指针
{
	//int TREE_LENGTH = 100; // 整个树的最大节点数
	//int l_ch;
	//int r_ch;
	//int root; // 定义三个指针，左/右/根节点
	//BinaryTreeNode rootNode = { 1 };
	//BinaryTreeNode lchNode = { 1 };
	//BinaryTreeNode rchNode = { 1 };
	//for (int i = 0; i < TREE_LENGTH; i++)
	//{
	//	if (rootNode.data != NULL)
	//	{
	//		std::cout << "输入根节点" << "\n";
	//		std::cin >> rootNode.data;
	//		rootNode.lchild = &lchNode;
	//	}
	//	else if (lchNode.data != NULL)
	//	{
	//		std::cout << "左孩子" << "\n";
	//		std::cin >> lchNode.data;
	//		lchNode.lchild = &rootNode;
	//	}
	//	else if (rchNode.data != NULL)
	//	{
	//		std::cout << "右" << "\n";
	//		std::cin >> rchNode.data;
	//		rchNode.rchild = &rootNode;
	//	}

	//}
	int ch;
	std::cout << "输入孩子" << "\n";
	std::cin >> ch;
	// 输入-1表示此节点无值
	if (ch == -1)
		t = NULL;
	else
	{
		t = new BinaryTreeNode;
		t->data = ch;
		createLinkBinaryTree(t->lchild);//cout<<"输入"<<ch<<"的左孩子：" ;
		createLinkBinaryTree(t->rchild);//cout<<"输入"<<ch<<"的右孩子：" ;
	}

}

// 二叉树遍历 - 递归/非递归
// 访问根节点 - 只打印树的根节点
void test14_ADTOfTree::printTreeRootElem(BiTree t)
{
	if (t->data != NULL)
	{
		std::cout << t->data << " ";
	}
	std::cout << "此树无根节点，为空树" << "\n";
}

// 先序遍历 - 递归法
void test14_ADTOfTree::preferenceOrderOfLinkBiTree(BiTree t)
{

	if (t != NULL)
	{
		this->printTreeRootElem(t);
		this->preferenceOrderOfLinkBiTree(t->lchild);
		this->preferenceOrderOfLinkBiTree(t->rchild);
	}
}

// 中序遍历 - 递归法
void test14_ADTOfTree::midOrderOfLinkBiTree(BiTree t)
{
	if (t != NULL)
	{
		this->midOrderOfLinkBiTree(t->lchild);
		this->printTreeRootElem(t);
		this->midOrderOfLinkBiTree(t->rchild);
	}
}

// 中序 - 非递归
// 借助栈，先扫描左子树，一一入栈，
void test14_ADTOfTree::midOrderOfLinkBiTree2(BiTree t)
{
	// 初始化一个栈
	test12_ADTOfStack* test12 = new test12_ADTOfStack();
	SqStack newStack;
	test12->initStack(newStack);
	BiTree p = t; // p是遍历指针
	while (p || !test12->isStackEmpty(newStack)) // 栈不空或p不空时循环
	{
		if (p) // 根指针进栈，遍历左子树
		{
			test12->pushStack(newStack, p->data); // 每遇到非空二叉树先向左走
			p = p->lchild;
		}
		else
		{
			test12->popStack(newStack, p->data); // 退栈
			this->printTreeRootElem(p); // 访问根节点
			p = p->rchild; // 再向右子树走
		}
	}
}

// 后序遍历
void test14_ADTOfTree::finallyOrderOfLinkBiTree(BiTree t)
{
	if (t != NULL)
	{
		this->finallyOrderOfLinkBiTree(t->lchild);
		this->finallyOrderOfLinkBiTree(t->rchild);
		this->printTreeRootElem(t);
	}
}

// 层序遍历 - 非递归
void test14_ADTOfTree::layerOrderOfLinkBiTree(BiTree t)
{

}


// **线索二叉树**
// 创建线索二叉树
void test14_ADTOfTree::createThreadBinaryTree()
{

}

// 把二叉树线索化 - 中序遍历法
void test14_ADTOfTree::binaryTree2ThreadBinaryTree(ThreadTree& p, ThreadTree& pre)
{

}

// 通过中序遍历建立中序线索二叉树
void test14_ADTOfTree::createMidThreadBinaryTree(ThreadTree t)
{

}

// **线索二叉树的遍历**
// 中序线索二叉树中中序序列下的第一个节点

// 中序遍历 - 不含头节点


// 树与二叉树的转换

// 树与森林的转换

// 树/森林的遍历

// *树的应用*
// 并查集(一种简单的集合表示，支持合并，查找，初始化子集操作)
// 初始化
void test14_ADTOfTree::initUFSet(int s[])
{

}

// find操作
int test14_ADTOfTree::findOfUFSet(int s[], int x)
{
	return 0;
}


// union操作
void test14_ADTOfTree::unionOfUFSet(int s[], int root1, int root2)
{

}

// **二叉树的应用**
// 二叉排序树

// 平衡二叉树

// Huffman树

// 
