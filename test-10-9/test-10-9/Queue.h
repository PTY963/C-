#pragma once

struct QueueNode
{
	QueueNode* next;
	int val;
};

//规范的玩法：
//一般情况下，短小的函数直接在类中定义，此时成员函数就成为inline
//长的函数，声明和定义分离
class Queue
{
//成员函数的声明
public:
	void Init();
	void Push(int x);
	void Pop();
	void Destory();
	//...
private:
	//成员变量的声明，告诉你变量的类型、名称但是没开空间
	QueueNode* head;
	QueueNode* tail;
};
