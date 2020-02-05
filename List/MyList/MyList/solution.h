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

//LeetCode 2:两数相加
//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//示例：
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
//思路：增加一个进位的变量extra，遍历一遍list得出结果
void addTwoNum(const MyList<int>& l1, const MyList<int>& l2, MyList<int> &out)
{
	int extra = 0;
	auto l1_iter = l1.begin();
	auto l2_iter = l2.begin();
	while (l1_iter != l1.end() || l2_iter != l2.end() || extra != 0)
	{
		int l1_value = 0;
		if (l1_iter != l1.end())
		{
			l1_value = *(l1_iter);
			l1_iter++;
		}
		int l2_value = 0;
		if (l2_iter != l2.end())
		{
			l2_value = *(l2_iter);
			l2_iter++;
		}
		int sum = l1_value + l2_value + extra;
		extra = sum / 10; //得到进位
		out.push_back(sum % 10);
	}
}

//LeetCode 445. 两数相加 II
//给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
//你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//进阶 :
//如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
//示例 :
//输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出 : 7 -> 8 -> 0 -> 7
//思路：根据上一题的思路两数相加从个位开始遍历相加，处理进位即可，但是不能翻转链表的话,既然需要翻转就
//是链表的好搭档栈来提供翻转的功能
void addTwoNum2(const MyList<int>& l1, const MyList<int>& l2, MyList<int> &out)
{
	MyStack<int> s1;
	MyStack<int> s2;
	for (auto iter = l1.begin();iter != l1.end(); iter++)
	{
		s1.push(*iter);
	}
	for (auto iter = l2.begin();iter != l2.end(); iter++)
	{
		s2.push(*iter);
	}
	int extra = 0;
	while (!s1.empty() || !s2.empty() || extra != 0)
	{
		int l1_value = 0;
		if (!s1.empty())
		{
			l1_value = s1.top();
			s1.pop();
		}
		int l2_value = 0;
		if (!s2.empty())
		{
			l2_value = s2.top();
			s2.pop();
		}
		int sum = l1_value + l2_value + extra;
		extra = sum / 10;
		out.push_front(sum % 10); // 这里的话是向前插
	}
}