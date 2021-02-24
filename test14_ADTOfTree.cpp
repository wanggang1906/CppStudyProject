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
	this->preferenceOrderOfLinkBiTree(newTree);

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
// 创建链式存储的二叉树 - 递归法，先序遍历法
// 先判断输入不为99，否则表示创建结束
// 创建一个新节点，数据域为输入值，为-1则表示次节点无数据
// 对左孩子指针域调用create函数
// 对右孩子指针域调用create函数
void test14_ADTOfTree::createLinkBinaryTree(BiTree& t) // 要改变指针，所以要吧指针传进来，相当于指针的指针
{
	int ch;
	std::cout << "输入节点值( != -1 )" << "\n";
	std::cin >> ch;
	if (ch != 99)
	{
		// 输入-1表示此节点无值
		if (ch == -1)
			t = NULL;
		else
		{
			t = new BinaryTreeNode; // 开堆区空间，等同malloc()
			t->data = ch;
			createLinkBinaryTree(t->lchild);//cout<<"输入"<<ch<<"的左孩子：" ;
			createLinkBinaryTree(t->rchild);//cout<<"输入"<<ch<<"的右孩子：" ;
		}
	}
}

// 二叉树遍历 - 递归/非递归
// 访问根节点 - 只打印树的根节点 == visit
void test14_ADTOfTree::printTreeRootElem(BiTree t)
{
	if (t->data != NULL)
	{
		std::cout << t->data << " ";
	}
	else
		std::cout << "此树无根节点，为空树" << "\n";
}

// 先序遍历 - 递归法
void test14_ADTOfTree::preferenceOrderOfLinkBiTree(BiTree t)
{
	// 根，左，右
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
	// 左根右
	if (t != NULL)
	{
		this->midOrderOfLinkBiTree(t->lchild);
		this->printTreeRootElem(t);
		this->midOrderOfLinkBiTree(t->rchild);
	}
}

// 后序遍历
void test14_ADTOfTree::finallyOrderOfLinkBiTree(BiTree t)
{
	// 左，右，根
	if (t != NULL)
	{
		this->finallyOrderOfLinkBiTree(t->lchild);
		this->finallyOrderOfLinkBiTree(t->rchild);
		this->printTreeRootElem(t);
	}
}

// 层序遍历

// 中序 - 非递归
// 借助栈，先扫描左子树，一一入栈，
void test14_ADTOfTree::midOrderOfLinkBiTree2(BiTree t)
{
	// 初始化一个栈
	test12_ADTOfStack* test12 = new test12_ADTOfStack();
	SqStack newStack;
	test12->initStack(newStack);

	BiTree p = t; // p是遍历指针
	while (p || !test12->isStackEmpty(newStack)) // 栈不空或p树不空时循环
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


// 层序遍历 - 非递归
void test14_ADTOfTree::layerOrderOfLinkBiTree(BiTree t)
{

}


// **线索二叉树**
// 创建线索二叉树(二叉树线索化) - 根据遍历序列加线索指针，左前右后



// 中序线索二叉树 - 递归,分开的
// 主过程
void test14_ADTOfTree::createMidThreadBinaryTree2(ThreadTree t)
{
	// 全局变量pre，指向当前访问节点的前驱
	ThreadNode* pre = NULL;

	// 中序线索化
	this->binaryTree2ThreadBinaryTree(t, pre);

}

// 中序线索化二叉树t - 分开的
void test14_ADTOfTree::binaryTree2ThreadBinaryTree(ThreadTree& p, ThreadTree& pre)
{
	ThreadTree t;
	pre = NULL; // pre初始为NULL
	if (t != NULL) // 非空二叉树才能线索化
	{
		this->binaryTreeInThread(t, pre); // 中序线索化二叉树
		if (pre->rchild == NULL)
		{
			pre->rtag = 1; // 处理遍历的最后一个节点
		}
	}
}

// 中序遍历二叉树，一边遍历一边线索化 - 递归
void test14_ADTOfTree::binaryTreeInThread(ThreadTree t, ThreadTree& pre)
{
	if (t != NULL)
	{
		this->binaryTreeInThread(t->lchild, pre);
		this->binaryTreeVisit(t, pre);
		this->binaryTreeInThread(t->rchild, pre);
	}
}

// 访问 <=> 加线索
void test14_ADTOfTree::binaryTreeVisit(ThreadNode* q, ThreadTree& pre)
{
	if (q->lchild == NULL)
	{
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre != NULL && pre->rchild == NULL)
	{
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
}

// 中序线索化 - 递归法
// 主过程
void test14_ADTOfTree::createMidThreadBinaryTree(ThreadTree t)
{
	ThreadTree pre = NULL;
	if (t != NULL) // 非空二叉树线索化
	{
		this->inThread(t, pre); // 线索化二叉树
		pre->rchild = NULL; // 处理遍历的最后一个节点
		pre->rtag = 1;
	}
}

// 递归线索化
void test14_ADTOfTree::inThread(ThreadTree& p, ThreadTree& pre)
{
	if (p != NULL)
	{
		this->inThread(p->lchild, pre); // 递归，线索化*左*子树
		if (p->lchild == NULL) //左子树为空，建立前驱线索
		{
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL)
		{
			pre->rchild = p; // 建立前驱节点的后继线索
			pre->rtag;
		}
		pre = p; // 标记当前节点成为刚刚访问过的节点
		this->inThread(p->rchild, pre); // 递归，线索化*右*子树
	}
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
