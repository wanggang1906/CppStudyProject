#include "test13_ADTOfQueue.h"
#include <iostream>
#include <string>


// 队列



void test13_ADTOfQueue::classMain()
{
	std::cout << "test13_ADTOfQueue" << "\n";

	// 循环队列
	SqQueue newCycleQueue;
	this->initCycleQueue(newCycleQueue);
	this->isEmptyOfCycleQueue(newCycleQueue);
	this->enterElemOfCycleQueue(newCycleQueue, 2);
	this->enterElemOfCycleQueue(newCycleQueue, 5);
	this->enterElemOfCycleQueue(newCycleQueue, 3);
	this->isEmptyOfCycleQueue(newCycleQueue);
	this->printElementOfCycleQueue(newCycleQueue);
	int x;
	this->deleteElemOfCycleQueue(newCycleQueue, x);
	std::cout << "出队的元素为：" << x << "\n";
	this->printElementOfCycleQueue(newCycleQueue);


}



// 顺序队列

// 初始化队列

// 判队空

// 元素入队

// 元素出队

// 取对头元素


// 循环队列


// 初始化队列
void test13_ADTOfQueue::initCycleQueue(SqQueue& q)
{
	q.rear = q.front = 0;
}

// 判队空
bool test13_ADTOfQueue::isEmptyOfCycleQueue(SqQueue q)
{
	if (q.rear == q.front)
		return true;
	return false;
}

// 元素入队
bool test13_ADTOfQueue::enterElemOfCycleQueue(SqQueue& q, ElemType x)
{
	if ((q.rear + 1) % 10 == q.front)
		return false;
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % 10;
	return true;
}

// 元素出队 - 循环队列元素出队，
bool test13_ADTOfQueue::deleteElemOfCycleQueue(SqQueue& q, ElemType& x)
{
	if (q.rear == q.front) // 判队空
		return false;
	x = q.data[q.front];
	q.front = (q.front + 1) % 10; // 
	return true;
}

// 打印队内元素 - 复制一份，逐个出队
void test13_ADTOfQueue::printElementOfCycleQueue(SqQueue& q)
{
	SqQueue temp;
	temp = q;
	//if ((temp.rear + 1) % 10 != temp.front)
	while (temp.rear != temp.front)
	{
		std::cout << temp.data[temp.front] << " ";
		temp.front = (temp.front + 1) % 10; // 循环队列尾指针前移
	}
	std::cout << "队列打印结束" << "\n";
}

// 取队头元素


// 链式队列

// 初始化
void test13_ADTOfQueue::initLinkQueue(LinkQueue& q)
{
	q.front = q.rear = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	q.front->next = NULL;
}

// 判队空
bool test13_ADTOfQueue::isLinkQueueEmpty(LinkQueue q)
{
	if (q.front == q.rear)
		return true;
	else
		return false;
}

// 入队
void test13_ADTOfQueue::enterELemOfLinkQueue(LinkQueue& q, ElemType x)
{
	LinkQueueNode* s;
	s = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	s->data = x;
	s->next = NULL;
	q.rear->next = s;
	q.rear = s;
}

// 出队
bool test13_ADTOfQueue::deleteElemOfLinkQueue(LinkQueue& q, ElemType& x)
{
	LinkQueueNode* p;
	if (q.front == q.rear)
		return false; // 空队
	p = q.front->next;
	x = p->data;
	if (q.rear == p)
		q.rear = q.front; // 若原队列只有一个节点，删除后变空队
	free(p);
	return true;
}



// 双端队列



// 队列的应用
