#pragma once
class test12_ADTOfStack
{
	// C++成员访问限定符
	// class中如果对成员变量和成员函数不指定访问权限限定符，默认为private
	// 而struct则默认为public。
#define MSize 10;
	//int MaxSize = 10;
	// 参考
	// https://blog.csdn.net/lizhengze1117/article/details/98746628

	// C++定义常量
	//const int MaxSize = 10;
	//constexpr int MaxSize = 10;
	// const 变量的初始化可以延迟到运行时，而 constexpr 变量必须在编译时进行初始化。
	// 所有 constexpr 变量均为常量，因此必须使用常量表达式初始化。
	typedef int ElemType;
	// 顺序栈
	typedef struct SqStack {
		ElemType data[10];
		int top; // 栈顶指针
	};

	// 共享栈 - 共享栈的数组
	typedef struct ShareStack {
		ElemType data[10];
		int top[2]; // top[0] - 0号栈的栈顶指针 - 初值为数组头  // top[1] - 1号栈的栈顶指针 - 初值为数组尾
	};

	// 链栈
	typedef struct LinkStackNode {
		ElemType data;
		struct LinkStackNode* next; // 指针域
	} *LiStack;




public:
	void classMain();

	// 顺序基本操作
	void initStack(SqStack& S);
	bool isStackEmpty(SqStack S);
	bool pushStack(SqStack& S, ElemType x);
	bool popStack(SqStack& S, ElemType& x);
	bool getTopElem(SqStack S, ElemType& x);
	void printStackElem(SqStack s);

	// 共享栈
	void initShareStack(ShareStack& s);
	bool pushShareStack(ShareStack& s, int num, int x);
	bool popShareStack(ShareStack& s, int num, int& x);
	ElemType getTopElemOfShareStack(ShareStack s, int num, int& x);



	// 链栈
	void createLinkStackOfHead();

	void initLinkStack(LinkStackNode*& s);
	bool isLinkStackEmpty(LinkStackNode* s);
	bool pushLinkStack(LinkStackNode* s, ElemType x);
	bool getElemOfLinkStack(LinkStackNode* s, ElemType& x);










};
