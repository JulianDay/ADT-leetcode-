#pragma once
#include "MyList.h"
template <class T>
class MyStack
{
public:
	MyStack()
	{

	}

	~MyStack()
	{

	}

	/*MyStack(MyStack& s)
	{
		*this = s;
	}

	const MyStack & operator= (MyStack& s)
	{
		if (this == &s)
		{
			return *this;
		}
		clear();
		while (!s.empty())
		{
			list.push_front(s.top());
			s.pop();
		}

		return *this;
	}*/
public:
	bool empty() const 
	{ 
		return list.empty();
	}
	int size() const 
	{
		return list.size();
	}
	T& top() 
	{ 
		return list.back();
	}
	const T& top() const 
	{ 
		return list.back();
	}
	void push(const T& x) //Ñ¹Õ»
	{ 
		list.push_back(x);
	}
	void pop() //³öÕ»
	{ 
		list.pop_back();
	}
public:
	void clear()
	{
		list.clear();
	}
private:
	MyList<T> list;
};