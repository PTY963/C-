#pragma once

namespace zsj
{
	template<class T>
	struct _list_node
	{
		_list_node<T>* next;
		_list_node<T>* prev;
		T data;

		_list_node(const T& x = T())
			:next(nullptr)
			,prev(nullptr)
			,data(x)
		{}
	};

	//迭代器 - 用类封装结点的指针
	template<class T>
	struct _list_iterator
	{
		typedef _list_node<T> Node;
		Node* _node;

		_list_iterator(Node* node)
			:_node(node)
		{}

		T& operator*()
		{
			return _node->data;
		}

		//前置++
		_list_iterator<T>& operator++()
		{
			_node = _node->next;
			return *this;
		}

		bool operator!=(const _list_iterator<T>& it)
		{
			return _node != it._node;
		}

	};

	

	template<class T>
	class list
	{
	   typedef _list_node<T> Node;
	public:
		typedef _list_iterator<T> iterator;
		iterator begin()
		{
			return iterator(_head->next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		
		list() 
		{
			//带头双向循环链表
			_head = new Node();
			_head->next = _head;
			_head->prev = _head;
		}

		//尾插
		void push_back(const T& x)
		{
			//1、找尾
			Node* tail = _head->prev;
			//2、开辟一个新结点
			Node* newnode = new Node(x);
			//3、改变链接关系
			tail->next = newnode;
			newnode->prev = tail;
			_head->prev = newnode;
			newnode->next = _head;
			
		}
	private:
		Node* _head;
	};

	void Test1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}
