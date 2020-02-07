// BortherWord.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isBrother(string str, string s) {
	if (str.size() == s.size()) {
		if (str == s)
			return false;
		sort(str.begin(), str.end());
		sort(s.begin(), s.end());
		if (str == s)
			return true;
	}
	return false;
}
int main()
{
	int num;
	while (cin >> num)
	{
		vector<string> wordList;
		for (int i = 0;i < num;i++)
		{
			string input;
			cin >> input;
			wordList.push_back(input);
		}
		sort(wordList.begin(), wordList.end());
		string findWord;
		cin >> findWord;
		int index;
		cin >> index;
		string indexWord;
		int counts = 0;
		for (int i = 0; i < num; ++i) {
			if (isBrother(findWord, wordList[i])) {
				counts++;
				if (counts == index)
					indexWord = wordList[i];
			}
		}
		cout << counts << endl;
		cout << indexWord << endl;
	}

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
