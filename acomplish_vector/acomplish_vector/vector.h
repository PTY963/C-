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
			if (_finsh == _end_of_storage)
			{
				size_t newcapacity = capacity() ==  0 ? 4 : 2 * capacity();
				reverse(newcapacity);
			}
			*_finsh = x;
			++_finsh;
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

}

