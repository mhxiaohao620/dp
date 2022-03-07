#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<numeric>
//分割等和子集问题可以用01背包解决！
//因为要求两个子集元素和相同，并且元素都是正整数，那么nums的元素总和一定要是偶数才能满足要求
//得到元素总和后，÷2就是一个子集中的所有元素和应该达到的目标了
//背包的容量即为子集中最多允许的元素值的总和，即为target=sum/2;
//那么背包要放入的物品时元素，元素的重量是元素的值，价值也是元素的值
//背包只要装满了，就说明子集中的元素值的总和可以达到target了，就找到了和为target的子集了
//背包中的元素是不可以重复使用的

//通过以上的分析，可以明确这道题可以用经典01背包问题解决

//1.确定dp数组和下标含义
//dp[j]表示背包总容量是j，背包中所放元素的和的最大值
//2.递推公式，
//物品i的重量是nums[i]，价值也是nums[i]
//套01背包：dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
//3.dp数组初始化
//dp[0]很明显应该等于0，dp数组其余位置初始化为0
//4.遍历顺序，先物品后容量，容量从大到小
//5.debug

//时间复杂度为O(n*target)，空间复杂度为O(target)
class Solution
{
public:
	bool canPartition(vector<int>& nums)
	{
		auto sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 == 1)
		{
			return false;
		}
		auto target = sum / 2;
		int n = nums.size();
		vector<int>dp(target + 1, 0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = target; j >= nums[i]; --j)
			{
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
				//dp[j]一定是小于等于j的，因为dp[j]表示和的最大值，j本身就是和的最大值
				if (dp[target] == target)//如果背包中所放元素和与target相等
				{
					return true;
				}
			}
		}
		return false;
	}
};

//二维数组dp
bool canPartition(vector<int>& nums)
{
	auto sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2 == 1)
	{
		return false;
	}
	auto target = sum / 2;
	int n = nums.size();
	vector<vector<int>>dp(n, vector<int>(target + 1, 0));
	for (int j = 0; j <= target; ++j)
	{
		if (j >= nums[0])
		{
			dp[0][j] = nums[0];
		}
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j <= target; ++j)
		{
			if (j < nums[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
			}
		}
	}
	return dp[n - 1][target] == target;
}