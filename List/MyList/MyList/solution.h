#pragma once
#include "MyList.h"
#include <iostream>
//LeetCode 19: 删除链表的倒数第N个节点
void removeNodeFromRight(MyList<int>& list, int n)
{
	if (n > list.size())
	{
		return;
	}
	MyList<int>::iterator l = list.begin();
	MyList<int>::iterator r = list.begin();
	while (n--)
	{
		r++;
	}
	while (r != list.end())
	{
		r++;
		l++;
	}
	list.erase(l);
}

//LeetCode 61:旋转链表
//1->2->3->4->5 旋转2次
//思路:e指向5，把5->1，移动e2次然后指向空
void rotateRight(MyList<int> list, int n)
{
	n = n % list.size();
	if (n == 0)
	{
		return;
	}
	MyList<int>::iterator e = list.end();
	MyList<int>::iterator b = list.begin();
	e.current->next = b.current;
	while (n--)
	{
		e++;
		b++;
	}
	e.current->next = nullptr;
}