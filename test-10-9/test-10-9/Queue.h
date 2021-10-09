#pragma once

struct QueueNode
{
	QueueNode* next;
	int val;
};

//�淶���淨��
//һ������£���С�ĺ���ֱ�������ж��壬��ʱ��Ա�����ͳ�Ϊinline
//���ĺ����������Ͷ������
class Queue
{
//��Ա����������
public:
	void Init();
	void Push(int x);
	void Pop();
	void Destory();
	//...
private:
	//��Ա��������������������������͡����Ƶ���û���ռ�
	QueueNode* head;
	QueueNode* tail;
};
