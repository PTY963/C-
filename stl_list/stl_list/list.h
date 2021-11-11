#pragma once

namespace zsj
{
	template<class T>
	struct _list_node
	{
		_list_node* prev;
		_list_node* next;
		T data;

		//构造函数
		_list_node(const T& x = T())
			:prev(nullptr)
			,next(nullptr)
			,data(x)
		{}
	};

	//迭代器 - 用类封装结点的指针
	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> Node;
		typedef _list_iterator<T, Ref, Ptr> self;
		Node* _node;

		_list_iterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->data;
		}

		//前置++
		self& operator++()
		{
			_node = _node->next;
			return *this;
		}
		//后置++
		//it++ 后置++返回的是++之前的值
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->next;
			return tmp;//tmp是临时对象，返回值不可以是&
		}
		//前置--
		self& operator--()
		{
			_node = _node->prev;
			return self(_node);
		}
		//后置--
		self operator--(int)
		{
			iterator tmp(*this);
			_node = _node->prev;
			return tmp;
		}
		bool operator!=(const self& it)
		{
			return _node != it._node;
		}

	};

	//template<class T>
	//struct _list_const_iterator
	//{
	//	typedef _list_node<T> Node;
	//	typedef _list_const_iterator<T> self;
	//	Node* _node;

	//	_list_const_iterator(Node* node)
	//		:_node(node)
	//	{}

	//	const T& operator*()
	//	{
	//		return _node->data;
	//	}

	//	//前置++
	//	self& operator++()
	//	{
	//		_node = _node->next;
	//		return *this;
	//	}
	//	//后置++
	//	//it++ 后置++返回的是++之前的值
	//	self operator++(int)
	//	{
	//		self tmp(*this);
	//		_node = _node->next;
	//		return tmp;//tmp是临时对象，返回值不可以是&
	//	}
	//	//前置--
	//	self& operator--()
	//	{
	//		_node = _node->prev;
	//		return _list_const_iterator(_node);
	//	}
	//	//后置--
	//	self operator--(int) 
	//	{
	//		iterator tmp(*this);
	//		_node = _node->prev;
	//		return tmp;
	//	}
	//	bool operator!=(const _list_const_iterator<T>& it)
	//	{
	//		return _node != it._node;
	//	}

	//};


	

	template<class T>
	class list
	{
	   typedef _list_node<T> Node;
	public:
		typedef _list_iterator<T, T&, T*>  iterator;
		typedef _list_iterator<T, const T&, const T*>  const_iterator;
		//typedef _list_const_iterator<T> const_iterator;
		iterator begin()
		{
			return iterator(_head->next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}
		
		list() 
		{
			//带头双向循环链表
			_head = new Node;
			_head->next = _head;
			_head->prev = _head;
		}

		//尾插
		void push_back(const T& x)
		{
			//end()返回的是最后一个有效数据的下一个位置，也就是_head
			//insert是在当前位置的前面也就是_head的前面插入
			insert(end(), x);
		}
		//头插
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		//在任意位置插入一个结点
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			//a、提前保存cur的prev
			Node* prev = cur->prev;
			//生成一个新结点
			Node* newnode = new Node(x);
			//改变链接关系
			prev->next = newnode;
			newnode->next = cur;
			cur->prev = newnode;
			newnode->prev = prev;
			
			//1、
			//iterator ret(newnode)
			//return ret;
            //2、return newnode; 单参数的构造函数支持隐式类型转换
			return iterator(newnode);//匿名对象
		}

		//在任意位置删除
		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			//保存cur的前一个和后一个
			Node* prev = cur->prev;
			Node* next = cur->next;

			delete cur;   //删除当前结点

			//改变链接关系
			prev->next = next;
			next->prev = prev;

			return iteartor(next);

		}
		//头删
		void pop_front()
		{
			erase(begin());
		}
		//尾删
		void pop_back()
		{
			erase(--end());
		}

		//链表中有效结点的个数
		size_t size()
		{
			size_t count = 0;
			iterator it = begin();
			while (it != end())
			{
				++it;
				++count;
			}
			return count;
		}

		//判断链表是否为空
		bool empty()
		{
			return begin() == end();
		}


	private:
		Node* _head;
	};

	void print_list(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << ' ';
			++it;
		}
		cout << endl;
	}
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

	void test2()
	{
		list<int> lt1;
		lt1.push_back(10);
		lt1.push_back(20);
		lt1.push_back(30);
		lt1.push_back(40);
		lt1.push_back(50);

		print_list(lt1);
	}
}
