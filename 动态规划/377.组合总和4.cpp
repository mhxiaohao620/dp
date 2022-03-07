#include<iostream>
using namespace std;
#include<vector>

//本题说是求组合数，但其实顺序不同的序列被视作不同的组合，实际上就是求排列数
//因为本题只要求排列的个数，而不用把所有排列都列出来，所以用回溯其实不是最优解法！
//整数可以无限选取，还有目标整数总和target，于是想到完全背包问题，
//因此整数序列就是背包，容量就是target，物品就是整数，重量和价值都是nums[i]
//即该问题转化为，将整数放入背包中使得背包放满有多少种方法，而且是求排列数的问题
//排列数问题遍历顺序要外层容量，内层物品

//1.dp数组以及下标含义
//dp[j]表示整数总和为j时，顺序不同的序列数，或者说放满背包的方法
//2.确定递推公式
//对于整数nums[i]，如果j<nums[i]，则无法将nums[i]放入背包，则dp[j]，而j>=nums[i]时，
//考虑总和为j-nums[i]时的情况，此时的序列数为dp[j-nums[i]]，只需要将nums[i]放入即可，因此dp[j]+=dp[j-nums[i]];
//3.dp数组初始化
//当j=0时，什么整数都不用放，这就是一种方案，即dp[0]=1;
//4.遍历顺序，一定是外层容量内层物品，都从小到大保证物品的重复使用
//5.debug
class Solution
{
public:
	int combinationSum4(vector<int>& nums, int target)
	{
		vector<int>dp(target + 1);
		dp[0] = 1;
		for (int j = 0; j <= target; ++j)
		{
			for (int i = 0; i < nums.size(); ++i)
			{
				if (j >= nums[i] && dp[j] < INT_MAX - dp[j - nums[i]])
				{
					dp[j] += dp[j - nums[i]];
				}
			}
		}
		return dp[target];
	}
};

//首先想到的就是回溯，因为回溯是用来解决组合问题的
class Backtracking
{
public:
	int ret = 0;
	void backtracking(vector<int>& nums, int target, int sum)//因为序列不同的组合其实是排列问题，所以不需要start参数
	{
		//如果当前组合内总和=target了，结果+1并返回上一层
		if (sum == target)
		{
			++ret;
			return;
		}
		if (sum > target)
		{
			return;
		}
		//遍历当前层，排列问题每次遍历都从0开始
		for (int i = 0; i < nums.size(); ++i)
		{
			backtracking(nums, target, sum + nums[i]);
		}
	}
	int combinationSum4(vector<int>& nums, int target)
	{
		backtracking(nums, target, 0);
		return ret;
	}
};