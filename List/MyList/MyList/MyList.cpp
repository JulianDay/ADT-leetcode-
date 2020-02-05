// MyList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "MyList.h"
#include "MyStack.h"
#include "solution.h"
template<class T>
void PrintList(const MyList<T>& l)
{
	std::cout << "[";
	for (auto iter = l.begin(); iter != l.end(); iter++)
	{
		std::cout << *iter << "	";
	}
	std::cout <<"]"<< std::endl;
}
int main()
{
	MyList<int> l;
	l.push_back(2);
	l.push_front(1);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	PrintList(l);

	MyList<int> l2(l);
	l2.push_back(4);
	l2.pop_front();
	PrintList(l2);
	MyList<int> l3;
	l3 = l2;
	l3.pop_back();
	PrintList(l3);
	removeNodeFromRight(l3, 4);
	PrintList(l3);
	//rotateRight(l3,2);

	MyStack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	std::cout << s1.top() <<std::endl;

	MyStack<int> s2(s1);
	s2.pop();
	std::cout << s2.top() << std::endl;

	MyStack<int> s3;
	s3 = s2;
	s3.pop();
	std::cout << s3.top() << std::endl;

	MyList<int> ll1;
	ll1.push_front(3);
	ll1.push_front(4);
	ll1.push_front(2);

	MyList<int> ll2;
	ll2.push_front(4);
	ll2.push_front(6);
	ll2.push_front(5);

	MyList<int> llr1;
	addTwoNum(ll1, ll2, llr1);
	PrintList(llr1);
	ll1.clear();
	ll2.clear();
	llr1.clear();
	ll1.push_front(3);
	ll1.push_front(4);
	ll1.push_front(2);
	ll1.push_front(7);
	ll2.push_front(4);
	ll2.push_front(6);
	ll2.push_front(5);
	addTwoNum2(ll1, ll2, llr1);
	PrintList(llr1);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
