#pragma once
#include "MyList.h"
#include <iostream>
//LeetCode 19: ɾ������ĵ�����N���ڵ�
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

//LeetCode 61:��ת����
//1->2->3->4->5 ��ת2��
//˼·:eָ��5����5->1���ƶ�e2��Ȼ��ָ���
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