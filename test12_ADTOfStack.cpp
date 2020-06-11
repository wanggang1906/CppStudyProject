#include "test12_ADTOfStack.h"
#include <iostream>
#include <string>

// 栈
// @1 - 首先是一种线性表
// 
// 
// 
// 
// 
// 

void test12_ADTOfStack::classMain()
{
	std::cout << "test12_ADTOfStack" << "\n";

	// 顺序栈
	//SqStack newStack; // 定义一个栈变量
	//this->initStack(newStack); // 初始化为空栈
	//this->isStackEmpty(newStack);
	//this->pushStack(newStack, 4);
	//this->pushStack(newStack, 6);
	//this->pushStack(newStack, 7);
	//this->pushStack(newStack, 8);
	//this->isStackEmpty(newStack);
	//this->printStackElem(newStack);
	//int x;
	//this->popStack(newStack, x);
	//std::cout << "\nX的值为：" << x << "\n";
	//this->printStackElem(newStack);
	//this->getTopElem(newStack, x);
	//std::cout << "\nX的值为：" << x << "\n";
	//this->printStackElem(newStack);

	// 链栈


}


// 顺序栈

// 初始化一个空栈
void test12_ADTOfStack::initStack(SqStack& s)
{
	s.top = -1;
}

// 判断一个栈是否为空
bool test12_ADTOfStack::isStackEmpty(SqStack s)
{
	if (s.top == -1)
		return true;
	else
		return false;
}

// 元素进栈
bool test12_ADTOfStack::pushStack(SqStack& s, ElemType x)
{
	if (s.top == 10 - 1)
		return false;
	s.data[++s.top] = x; // 指针先++，在入栈
	return true;
}

// 元素出栈 - 栈顶元素出栈，用x接受出栈的元素
bool test12_ADTOfStack::popStack(SqStack& s, ElemType& x)
{
	if (s.top == -1)
		return false;
	x = s.data[s.top--]; // 先出栈，指针再--
	return true;
}

// 取栈顶元素 - 用x接受栈顶元素，原栈元素不变
bool test12_ADTOfStack::getTopElem(SqStack s, ElemType& x)
{
	if (s.top == -1)
		return false;
	x = s.data[s.top];
	return true;
}

// 打印栈内元素
void test12_ADTOfStack::printStackElem(SqStack s)
{
	int resultElem;
	SqStack temp = s; // 复制一份，temp逐个出栈，输出
	if (temp.top == -1)
		std::cout << "此栈为空栈" << "\n";
	while (temp.top != -1)
	{
		resultElem = temp.data[temp.top];
		std::cout << resultElem << " ";
		temp.top--;
	}
}

// 销毁栈


// 共享栈
// 
void test12_ADTOfStack::initShareStack(ShareStack& s)
{
	s.top[0] = -1;
	s.top[1] = 10;
}

// 指定元素进入第num个栈
bool test12_ADTOfStack::pushShareStack(ShareStack& s, int num, int x)
{
	if (s.top[0] + 1 < s.top[1]) // 判断栈是否满了
	{
		if (num == 0)
		{
			++s.top[0];
			s.data[s.top[0]] = x;
			return true;
		}
		else if (num == 1)
		{
			--s.top[1];
			s.data[s.top[1]] = x;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

// 
bool test12_ADTOfStack::popShareStack(ShareStack& s, int num, int& x)
{
	if (num == 0)
	{
		if (s.top[0] != -1)
		{
			x = s.data[s.top[0]];
			--s.top[0];
			return true;
		}
		else
			return false;
	}
	else if (num == 1)
	{
		if (s.top[1] != 10)
		{
			x = s.data[s.top[1]];
			++s.top[1];
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

// 取
test12_ADTOfStack::ElemType test12_ADTOfStack::getTopElemOfShareStack(ShareStack s, int num, int& x)
{
	if (num == 0)
	{
		if (s.top[0] != -1)
		{
			x = s.data[s.top[0]];
		}
		else
			return -1;
	}
	else if (num == 1)
	{
		if (s.top[1] != 10)
		{
			x = s.data[s.top[1]];
		}
		else
			return -1;
	}
	else
		return -1;
}


// 链栈 - 链表 + 栈(限制一端进出)

// 头插法创建链栈
void test12_ADTOfStack::createLinkStackOfHead()
{
	//LinkStackNode* linkStack;

}


// 初始化
void test12_ADTOfStack::initLinkStack(LinkStackNode*& s)
{
	s = (LinkStackNode*)malloc(sizeof(LinkStackNode)); // 头节点
	s->next = NULL;
}

// 判栈空
bool test12_ADTOfStack::isLinkStackEmpty(LinkStackNode* s)
{
	if (s->next == NULL)
		return true;
	else
		return false;
}

// 入栈
bool test12_ADTOfStack::pushLinkStack(LinkStackNode* s, ElemType x)
{
	LinkStackNode* p;
	p = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	p->data = x; // 头插法入栈
	p->next = s->next;
	s->next = p;
	return true;
}

// 出栈
bool test12_ADTOfStack::getElemOfLinkStack(LinkStackNode* s, ElemType& x)
{
	LinkStackNode* p;
	if (s->next == NULL)
		return false;
	p = s->next;
	x = p->data;
	s->next = p->next;
	free(p);
	return true;
}
