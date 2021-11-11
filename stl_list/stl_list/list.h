#pragma once

namespace zsj
{
	template<class T>
	struct _list_node
	{
		_list_node* prev;
		_list_node* next;
		T data;

		//���캯��
		_list_node(const T& x = T())
			:prev(nullptr)
			,next(nullptr)
			,data(x)
		{}
	};

	//������ - �����װ����ָ��
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

		//ǰ��++
		self& operator++()
		{
			_node = _node->next;
			return *this;
		}
		//����++
		//it++ ����++���ص���++֮ǰ��ֵ
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->next;
			return tmp;//tmp����ʱ���󣬷���ֵ��������&
		}
		//ǰ��--
		self& operator--()
		{
			_node = _node->prev;
			return self(_node);
		}
		//����--
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

	//	//ǰ��++
	//	self& operator++()
	//	{
	//		_node = _node->next;
	//		return *this;
	//	}
	//	//����++
	//	//it++ ����++���ص���++֮ǰ��ֵ
	//	self operator++(int)
	//	{
	//		self tmp(*this);
	//		_node = _node->next;
	//		return tmp;//tmp����ʱ���󣬷���ֵ��������&
	//	}
	//	//ǰ��--
	//	self& operator--()
	//	{
	//		_node = _node->prev;
	//		return _list_const_iterator(_node);
	//	}
	//	//����--
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
			//��ͷ˫��ѭ������
			_head = new Node;
			_head->next = _head;
			_head->prev = _head;
		}

		//β��
		void push_back(const T& x)
		{
			//end()���ص������һ����Ч���ݵ���һ��λ�ã�Ҳ����_head
			//insert���ڵ�ǰλ�õ�ǰ��Ҳ����_head��ǰ�����
			insert(end(), x);
		}
		//ͷ��
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		//������λ�ò���һ�����
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			//a����ǰ����cur��prev
			Node* prev = cur->prev;
			//����һ���½��
			Node* newnode = new Node(x);
			//�ı����ӹ�ϵ
			prev->next = newnode;
			newnode->next = cur;
			cur->prev = newnode;
			newnode->prev = prev;
			
			//1��
			//iterator ret(newnode)
			//return ret;
            //2��return newnode; �������Ĺ��캯��֧����ʽ����ת��
			return iterator(newnode);//��������
		}

		//������λ��ɾ��
		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			//����cur��ǰһ���ͺ�һ��
			Node* prev = cur->prev;
			Node* next = cur->next;

			delete cur;   //ɾ����ǰ���

			//�ı����ӹ�ϵ
			prev->next = next;
			next->prev = prev;

			return iteartor(next);

		}
		//ͷɾ
		void pop_front()
		{
			erase(begin());
		}
		//βɾ
		void pop_back()
		{
			erase(--end());
		}

		//��������Ч���ĸ���
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

		//�ж������Ƿ�Ϊ��
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
