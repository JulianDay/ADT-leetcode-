// WordOrderDesc.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{
	string input;
	getline(cin, input);
	//滑动窗口
	int i = input.length() - 1;//指向单词的前端
	int j = i;

	string outWord = "";
	bool inWord = false;
	for (;i >= 0;)
	{
		if ((input[i] >= 'a' &&input[i] <= 'z') || (input[i] >= 'A' &&input[i] <= 'Z'))
		{
			if (inWord == false)
			{
				j = i;//标记需要单词结尾Index
				inWord = true;
			}
			i--;
		}
		else//遇到分隔符
		{
			if (inWord)//在单词状态中则输出单词
			{
				string word = input.substr(i + 1, (j - i));
				outWord.append(word).append(" ");
			}
			i--;
			inWord = false;
		}
	}
	if (inWord && i != j)
	{
		string word = input.substr(i + 1, (j - i));
		outWord.append(word);
	}

	cout << outWord<<endl;
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
