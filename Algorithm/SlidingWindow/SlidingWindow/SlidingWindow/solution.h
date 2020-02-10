#pragma once
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

class solution
{
public:
	//325:Maximum Size Subarray Sum Equals k
	int maxLenSubArraySumEqK(const vector<int>& nums, int k)
	{
		if (nums.empty())
		{
			return 0;
		}
		int b, e;
		b = 0;
		e = 1;
		int maxLen = 0;
		int sum = nums[b];
		for (;e < nums.size();)
		{
			sum += nums[e];
			if (sum == k)
			{
				int curLen = e - b + 1;
				if (curLen > maxLen)
				{
					maxLen = curLen;
				}
				b++;
				e = b + 1;
				sum = nums[b];
			}
			else
			{
				e++;
			}
		}
		return maxLen;
	}
	//3:无重复字符的最长子串
	int lengthOfLongestSubstring(string s)
	{
		int n = s.length();
		int b, e, maxLen;
		b = e = maxLen = 0;
		unordered_set<char> set;
		while (b < n && e < n)
		{
			if (set.count(s[e]) == 0)
			{
				set.insert(s[e]);
				e++;
				maxLen = max(maxLen, e - b);
			}
			else
			{
				set.erase(s[b]);
				b++;
			}
		}
		return maxLen;
	}
};