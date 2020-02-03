#pragma once

template <class T>
class MyVector
{
public:
	enum MyEnum
	{
		SPARE_CAPACITY = 16
	};
	explicit MyVector(int initSize = 0) :theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
	{
		objects = new T[theCapacity];
	}
	MyVector(const MyVector &vct)
	{
		operator=(vct);
	}
	~MyVector()
	{
		delete[] objects;
	}

	const MyVector & operator= (const MyVector& vct)
	{
		if (this != &vct)
		{
			delete[] objects;
			theSize = vct.size();
			theCapacity = vct.capacity();

			objects = new T[theCapacity];
			for (int i = 0;i < theSize;i++)
			{
				objects[i] = vct[i];
			}
		}
	}

	void resize(int newSize)
	{
		if (newSize > theCapacity)
		{
			reserve();
		}
	}

	void reserve(int newCapacity)
	{
		if (newCapacity < theSize)
		{
			return;
		}
		T *oldArray = objects;
		objects = new T[newCapacity];
		for (int i = 0;i < theSize;i++)
		{
			objects[i] = oldArray[i];
		}
		theCapacity = newCapacity;
		delete[] oldArray;
	}

	T & operator[](int index)
	{
		//if (index >= theSize)
		//{
		//	throw "out of range";
		//}
		return objects[index];
	}
	const T& operator[](int index) const
	{
		//if (index >= theSize)
		//{
		//	throw "out of range";
		//}
		return objects[index];
	}

	bool empty() const
	{
		return (size() == 0);
	}

	int size() const
	{
		return theSize;
	}

	int capacity() const
	{
		return theCapacity;
	}

	void push_back(const T& x)
	{
		if (theSize == theCapacity)
		{
			reserve(2 * theCapacity + 1);
		}
		objects[theSize++] = x;
	}

	void pop_back()
	{
		theSize--;
	}

	const T& back() const
	{
		return objects[theSize - 1];
	}
private:
	int theSize;
	int theCapacity;
	T *objects;
};