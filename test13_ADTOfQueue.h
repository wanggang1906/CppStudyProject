#pragma once
class test13_ADTOfQueue
{
	typedef int ElemType;
	// 顺序队
	typedef struct SqQueue {
		ElemType data[10];
		int front, rear; // 队头/队尾指针
	};

	// 循环队列


	// 链队
	typedef struct LinkQueueNode { // 链式队列的节点
		ElemType data;
		struct LinkQueueNode* next;
	};
	typedef struct LinkQueue { // 链式队列
		LinkQueueNode* front, * rear; // 队头/队尾
	};

public:
	void classMain();

	// 顺序队

	// 循环队列
	void initCycleQueue(SqQueue& q);
	bool isEmptyOfCycleQueue(SqQueue q);
	bool enterElemOfCycleQueue(SqQueue& q, ElemType x);
	bool deleteElemOfCycleQueue(SqQueue& q, ElemType& x);

	// 链队
	void initLinkQueue(LinkQueue& q);
	bool isLinkQueueEmpty(LinkQueue q);
	void enterELemOfLinkQueue(LinkQueue& q, ElemType x);
	bool deleteElemOfLinkQueue(LinkQueue& q, ElemType& x);

};
