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

		//拷贝构造传统写法
		vector(const vector<T>& v)
		{
			//1、开辟一块和v一样大的空间
			_start = new T[v.capacity()];
			//2、将v空间的内容拷贝过来
			memcpy(_start, v._start, sizeof(T) * v.size());
			//3、修改初始值
			_finsh = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}

		//现代写法的拷贝构造函数
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
		
		//类模板的成员函数，还可以定义模板参数
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
		//	if (this != &v) //防止自己对自己拷贝
		//	{
		//		//释放掉v1的空间
		//		delete[] _start;
		//		_start = _finsh = _end_of_storage = nullptr;
		//		//开辟一块和v一样大的空间
		//		reverse(v.capacity());
		//		for (const auto& e : v)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this;
		//}

		//v1 = v2
		//v就是v2的深拷贝，也是v1想要的值
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

				//程序走到这里，说明空间已经够了
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
				T* tmp = new T[n];//给tmp开辟一块空间
				memcpy(tmp, _start, sizeof(T) * sz);//将原先空间的内容拷贝到tmp中
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

		//里面已经对迭代器失效做了处理，但是外面调用insert之后还是会有迭代器失效的问题
		//根本原因是，pos是传值传参，形参的改变并不会影响实参
		//虽然可以传引用解决，但是库里的实现，pos并没有传参
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finsh);//等于相当于尾插
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

