#pragma once
#include<deque>
namespace AHAOAHA
{
	template<class T,class Container = std::deque<T>>
	class Stack
	{
	public:
		void push(T&  data)
		{
			_con.push_back(data);
		}
		T& top()
		{
			return _con.back();
		}

		void pop()
		{
			_con.pop_back();
		}

		const size_t size()
		{
			return _con.size();
		}

		const bool empty()
		{
			return _con.empty();
		}

		bool operator==(const Stack& st)
		{
			return this->_con == st._con;
		}

	private:
		Container _con;
	};
}