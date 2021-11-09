#pragma once
namespace zsj
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finsh;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finsh;
		}
		vector()
			:_start(nullptr)
			, _finsh(nullptr)
			, _end_of_storage(nullptr)
		{}

		//�������촫ͳд��
		vector(const vector<T>& v)
		{
			//1������һ���vһ����Ŀռ�
			_start = new T[v.capacity()];
			//2����v�ռ�����ݿ�������
			memcpy(_start, v._start, sizeof(T) * v.size());
			//3���޸ĳ�ʼֵ
			_finsh = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}

		//�ִ�д���Ŀ������캯��
		/*vector(const vector<T>& v)
			:_start(nullptr)
			,_finsh(nullptr)
			,_end_of_storage(nullptr)
		{
			vector<T> temp(v.begin(), v.end());
			swap(temp);
		}*/

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finsh, v._finsh);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		
		//��ģ��ĳ�Ա�����������Զ���ģ�����
		/*template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			,_finsh(nullptr)
			,_end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}*/

		//v1 = v2
		//vector<T>& operator=(const vector<T>& v)
		//{
		//	if (this != &v) //��ֹ�Լ����Լ�����
		//	{
		//		//�ͷŵ�v1�Ŀռ�
		//		delete[] _start;
		//		_start = _finsh = _end_of_storage = nullptr;
		//		//����һ���vһ����Ŀռ�
		//		reverse(v.capacity());
		//		for (const auto& e : v)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this;
		//}

		//v1 = v2
		//v����v2�������Ҳ��v1��Ҫ��ֵ
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			delete[] _start;
			_start = _finsh = _end_of_storage = nullptr;
		}

		size_t size() const
		{
			return _finsh - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}


		void resize(size_t n, const T& value = T())
		{
			if (n <= size())
			{
				_finsh = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reverse(n);
				}

				//�����ߵ����˵���ռ��Ѿ�����
				while (_finsh < _start + n)
				{
					*_finsh = value;
					++_finsh;
				}
			}
		}
		void reverse(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];//��tmp����һ��ռ�
				memcpy(tmp, _start, sizeof(T) * sz);//��ԭ�ȿռ�����ݿ�����tmp��
				_start = tmp;
				_finsh = _start + sz;
				_end_of_storage = _start + n;
			}
		}
		void push_back(const T& x)
		{
			/*if (_finsh == _end_of_storage)
			{
				size_t newcapacity = capacity() ==  0 ? 4 : 2 * capacity();
				reverse(newcapacity);
			}
			*_finsh = x;
			++_finsh;*/

			insert(_finsh, x);
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		//�����Ѿ��Ե�����ʧЧ���˴��������������insert֮���ǻ��е�����ʧЧ������
		//����ԭ���ǣ�pos�Ǵ�ֵ���Σ��βεĸı䲢����Ӱ��ʵ��
		//��Ȼ���Դ����ý�������ǿ����ʵ�֣�pos��û�д���
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finsh);//�����൱��β��
			if (_finsh == _end_of_storage)
			{
				size_t len = pos - _start;
				int newcapcity = capacity() == 0 ? 4 : capacity();
				reverse(newcapcity);
				pos = _start + len;
			}

			iterator end = _finsh - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finsh;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finsh);
			iterator it = pos + 1;
			while (it != _finsh)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finsh;

			return pos;
		}

		

	private:
		iterator _start;
		iterator _finsh;
		iterator _end_of_storage;
	};

	void print(const vector<int>& v)
	{
		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << ' ';
			++it;
		}
		cout << endl;

		/*for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << ' ';
		}
		cout << endl;*/
	}

	void Test1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << ' ';
			++it;
		}
		cout << endl;

		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << ' ';
		}
		cout << endl;

		print(v1);
	}

	void Test2()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		print(v1);

		v1.resize(5);
		print(v1);

		v1.resize(3);
		print(v1);

		v1.resize(8);
		print(v1);

	}
	void Test3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		vector<int> v2(v1);
		for (auto e : v2)
		{
			cout << e << ' ';
		}
		cout << endl;
	}

	void Test4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		/*vector<int> v2(v1);
		for (const auto& e : v2)
		{
			cout << e << ' ';
		}
		cout << endl;*/
		vector<int> v2;
		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);
		v2.push_back(4);
		v2.push_back(5);
		v2.push_back(6);
		v2.push_back(7);
		v2.push_back(8);
		v2.push_back(9);

		v1 = v2;
		for (const auto& e : v1)
		{
			cout << e << ' ';
		}
		cout << endl; 

	}

}

