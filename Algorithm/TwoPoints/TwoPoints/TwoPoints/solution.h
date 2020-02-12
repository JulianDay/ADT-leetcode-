#pragma once
#include <vector>
#include <algorithm>
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

using namespace std;
class Solution
{
public:
	//LeetCode 11. 盛最多水的容器
	//给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
	//	在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和(i, 0)。
	//	找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
	//说明：你不能倾斜容器，且 n 的值至少为 2。
	int maxArea(const vector<int>& height) {
		int l = 0;
		int r = height.size() - 1;
		int ret = 0;
		while (l < r)
		{
			ret = max(ret, min(height[l], height[r])*(r - l));
			if (height[l] < height[r])
			{
				l++;
			}
			else
			{
				r--;
			}
		}

		return ret;
	}
	//LeetCode 42. 接雨水
	//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
	int trap(const vector<int>& height) {
		int l = 0;
		int r = height.size() - 1;
		int ret = 0;
		int left_max, right_max;
		left_max = right_max = 0;
		while (l < r)
		{
			if (height[l] < height[r]) {
				height[l] >= left_max ? (left_max = height[l]) : ret += (left_max - height[l]);
				++l;
			}
			else {
				height[r] >= right_max ? (right_max = height[r]) : ret += (right_max - height[r]);
				--r;
			}
		}
		return ret;
	}

	//LeetCode 11. 三数之和
	//注意两个错误1.数组越界2.边界问题[0,0,0,0] 输出：[[0,0,0],[0,0,0]]
	//注意：答案中不可以包含重复的三元组。(不重复则第一个不能重复)
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		sort(nums.begin(), nums.end()); //1.先排个序
		for (int i = 0;i < (int)(nums.size() - 2);i++)//第一个错误：这个地方还是得注意如果不强制转化成int会数值越界
		{
			if (i > 0 && nums[i - 1] == nums[i])// 过滤一下相同的三元组
			{
				continue;
			}
			int left = i + 1;
			int right = nums.size() - 1;
			if (nums[i] > 0 && nums[right] > 0) // 第一个和最后都>0 就break;
			{
				break;
			}
			while (left < right)
			{
				int sum = nums[i] + nums[left] + nums[right];
				if (sum == 0)
				{
					ret.push_back(vector<int>{nums[i], nums[left], nums[right]});
					while (left < right && nums[left] == nums[++left])
					{

					}
					while (left < right && nums[right] == nums[--right])
					{

					}
					//if (left < right && nums[left + 1] == nums[left])
					//{
					//	left++;
					//}
					//else
					//{
					//	right--;
					//}
				}
				else if (sum > 0)//太大了就把右值移动一下
				{
					right--;
				}
				else
				{
					left++;
				}
			}
		}
		return ret;
	}
};