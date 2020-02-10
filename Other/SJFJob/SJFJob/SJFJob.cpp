// SJFJob.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;
struct JobList
{
	priority_queue<int, vector<int>, greater<int>> list;
};

struct CPUTime
{
	CPUTime(int max) :maxCount(max), jobNum(0)
	{
		for (int i = 0;i < maxCount;i++)
		{
			timeList.push_back(0);
		}
	}

	void AddJob(int jobTime)
	{
		int index = jobNum % maxCount;
		timeList[index] += jobTime;
		jobNum++;
	}

	int MaxTime()
	{
		int time = 0;
		for (int i = 0; i < maxCount;i++)
		{
			if (timeList[i] > time)
			{
				time = timeList[i];
			}
		}
		return time;
	}
	int maxCount;
	int jobNum;
	vector<int> timeList;
};

int main()
{
	int cpuCount, JobCount;
	//3 5
	//8 4 3 1 10
	scanf_s("%d %d", &cpuCount, &JobCount);
	//cin >> cpuCount >> JobCount;
	CPUTime cupTime(cpuCount);
	JobList jobList;
	for (int i = 0;i < JobCount;i++)
	{
		int jobTime = 0;
		cin >> jobTime;
		jobList.list.push(jobTime);
	}
	while (!jobList.list.empty())
	{
		int minJobTime = jobList.list.top();
		cupTime.AddJob(minJobTime);
		jobList.list.pop();
	}
	cout << cupTime.MaxTime()<< endl;
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
