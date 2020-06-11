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
	s.data[++s.top] = x;
	return true;
}

// 元素出栈
bool test12_ADTOfStack::popStack(SqStack& s, ElemType& x)
{
	if (s.top == -1)
		return false;
	x = s.data[s.top--];
	return true;
}

// 取栈顶元素
bool test12_ADTOfStack::getTopElem(SqStack s, ElemType& x)
{
	if (s.top == -1)
		return false;
	x = s.data[s.top];
	return true;
}

// 销毁栈


// 共享栈



// 链栈

//
