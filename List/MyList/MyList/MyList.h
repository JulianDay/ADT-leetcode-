#pragma once
template <class T>
class MyList
{
private:
	struct Node
	{
		T data;
		Node *prev;
		Node *next;
		Node(const T &d = T(), Node *p = nullptr, Node *n = nullptr) :data(d), prev(p), next(n) {}
	};
public:
	class const_iterator
	{
	public:
		const_iterator() :current(nullptr) {	}
		const T& operator* () const { return retrieve(); }
		//所以在某些情况下++i比i++的效率高，++i可能是原子操作而i++不是
		const_iterator & operator++()
		{
			current = current->next;
			return *this;
		}

		const_iterator & operator--()
		{
			this->current = this->current->prev;
			return *this;
		}
		const_iterator operator++(int)
		{
			const_iterator old = (*this);
			++(*this);
			return old;
		}
		const_iterator operator--(int)
		{
			const_iterator old = (*this);
			--(*this);
			return old;
		}
		bool operator==(const const_iterator &rhs) const
		{
			return (current == rhs.current);
		}

		bool operator!=(const const_iterator &rhs) const
		{
			return !(*this == rhs);
		}
	public:
		Node* current;

		T & retrieve() const
		{
			return current->data;
		}

		const_iterator(Node *p) :current(p) {}

		friend class MyList<T>;
	};
	class iterator : public const_iterator
	{
	public:
		iterator() {}
		T& operator*()
		{
			return this->retrieve();
		}
		const T& operator*() const
		{
			return const_iterator::operator *();
		}
		iterator & operator++()
		{
			this->current = this->current->next;
			return *this;
		}
		iterator & operator--()
		{
			this->current = this->current->prev;
			return *this;
		}
		iterator operator++ (int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}

		iterator operator-- (int)
		{
			iterator old = *this;
			--(*this);
			return old;
		}
	protected:
		iterator(Node *p) :const_iterator(p) {}
		friend class MyList<T>;
	};
public:
	MyList()
	{
		init();
	}
	~MyList()
	{
		clear();
		delete head;
		head = nullptr;
		delete tail;
		tail = nullptr;
	}
	MyList(const MyList & l)
	{
		init();
		*this = l;
	}
	const MyList & operator= (const MyList & l)
	{
		if (this == &l)
		{
			return *this;
		}
		clear();
		for (const_iterator iter = l.begin();iter != l.end(); iter++)
		{
			push_back(*iter);
		}
		return *this;
	}

	iterator begin()
	{
		return iterator(head->next);
	}

	const_iterator begin() const
	{
		return const_iterator(head->next);
	}

	iterator end()
	{
		return iterator(tail);
	}

	const_iterator end() const
	{
		return const_iterator(tail);
	}

	int size() const
	{
		return theSize;
	}

	bool empty() const
	{
		return (size() == 0);
	}

	void clear()
	{
		while (!empty())
		{
			pop_front();
		}
	}

	T & front()
	{
		return *begin();
	}

	const T & front() const
	{
		return *begin();
	}

	T & back()
	{
		return *--end();
	}

	const T & back() const
	{
		return *--end();
	}

	void push_front(const T& x)
	{
		insert(begin(), x);
	}
	void push_back(const T& x)
	{
		insert(end(), x);
	}

	void pop_front()
	{
		erase(begin());
	}

	void pop_back()
	{
		erase(--end());
	}

	iterator insert(iterator iter, const T& x)
	{
		Node* p = iter.current;
		++theSize;
		return iterator(p->prev = p->prev->next = new Node(x, p->prev, p));
	}

	iterator erase(iterator iter)
	{
		Node *p = iter.current;
		iterator retVal(p->next);
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		p = nullptr;
		--theSize;
		return retVal;
	}


	iterator erase(iterator start, iterator end)
	{
		for (iterator iter = start; iter != end;)
		{
			iter = erase(iter);
		}
		return end;
	}
private:
	int theSize;
	Node* head;
	Node* tail;

	void init()
	{
		theSize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}
};