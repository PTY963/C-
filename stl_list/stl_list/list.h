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

		Ptr operator->()
		{
			return &(_node->data);//���ص���TreeNode��ָ��
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

		list(const list<T>& lt)
		{
			_head = new Node;
			_head->next = _head;
			_head->prev = _head;

			list<T>::const_iterator it = lt.begin();
			while (it != lt.end())
			{
				push_back(*it);
				++it;
			}
		}

		//֧��һ�ε����������ʼ��
		//��ģ�������Ϊ�˿���֧�ֲ�ͬ�����ĵ�����
		template<class InPutIterator>
		list(InPutIterator first, InPutIterator last)
		{
			_head = new Node;
			_head->next = _head;
			_head->prev = _head;

			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//lt1 = lt4
		//list<T>& operator=(const list<T>& lt)
		//{
		//	if (this != &lt)//��ֹ�Լ����Լ���ֵ
		//	{
		//		clear();//����lt1�Ľ�㣬lt1ֻʣ��ͷ���
		//		const_iterator it = lt.begin();
		//		while (it != lt.end())
		//		{
		//			push_back(*it);
		//			++it;
		//		}
		//	}
		//	return *this;
		//}
		


		//lt1 = lt4���ִ�д����ֻҪʵ���˿�������Ϳ���д�ִ�д��
		list<T>& operator=(list<T> lt)//lt����lt1�Ŀ���
		{
			std::swap(_head, lt._head);
			return *this;
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

			return iterator(next);

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

		void clear()
		{
			//ɾ����ͷ�����������н��
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);//ɾ����ǰ��㲢������һ������λ��
			}
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
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

	struct TreeNode
	{
		struct TreeNode* left;
		struct TreeNode* right;
		int val;

		TreeNode(const int& x = -1)
			:left(nullptr)
			,right(nullptr)
			,val(x)
		{}
	};

	void test3()
	{
		list<TreeNode> t;
		t.push_back(1);
		t.push_back(2);
		t.push_back(3);
		t.push_back(4);

		list<TreeNode>::iterator it = t.begin();
		while (it != t.end())
		{
			//cout << *it << ' ';//*it�õ�����TreeNode��cout����������Զ�������
			//cout << (*it).val << ' ';
			cout << it->val << ' ';//it->���ص���TreeNode��ָ��Ӧ����->һ�β�ָ��val
			++it;				   //iԭ����t->->val������Ϊ�˿ɶ��ԣ����������������⴦��
								   //ʡ��һ��->
		}
		cout << endl;
	}

	void test4()
	{
		list<int> lt1;
		lt1.push_back(10);
		lt1.push_back(20);
		lt1.push_back(30);
		lt1.push_back(40);
		lt1.push_back(50);
		for (auto& e : lt1)
		{
			cout << e << ' ';
		}
		cout << endl;

		list<int> lt2(lt1);
		for (auto& e : lt2)
		{
			cout << e << ' ';
		}
		cout << endl;

		list<int> lt3(lt1.begin(), lt1.end());
		for (auto e : lt3)
		{
			cout << e << ' ';
		}
		cout << endl;

		string s("hello");
		list<char> lt4(s.begin(), s.end());
		for (auto e : lt4)
		{
			cout << e << ' ';
		}
		cout << endl;

	}

	void test5()
	{
		list<int> lt1;
		lt1.push_back(10);
		lt1.push_back(20);
		lt1.push_back(30);
		lt1.push_back(40);

		cout << "lt1������";
		for (auto e : lt1)
		{
			cout << e << ' ';
		}
		cout << endl;

		list<int> lt4;
		lt4.push_back(50);
		lt4.push_back(60);
		lt4.push_back(70);
		lt4.push_back(80);

		cout << "lt4������";
		for (auto e : lt4)
		{
			cout << e << ' ';
		}
		cout << endl;

		lt1 = lt4;
		cout << "lt1���ڣ�";
		for (auto e : lt1)
		{
			cout << e << ' ';
		}
		cout << endl;

	}
}
