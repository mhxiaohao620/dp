#include<iostream>
using namespace std;
#include<vector>
//硬币可以无限选，且要求凑成总金额amount，想到完全背包问题
//背包容量就是amount，物品就是硬币，物品重就是硬币价值
//但是本题多加了一个条件，要求凑成amount的硬币个数最少
//1.dp数组以及下标含义
//dp[j]为金额为j时，所选硬币价值为j时的最少硬币个数
//2.确定递推公式
//考虑硬币i，dp[j]只能由不考虑硬币i的dp[j-coins[i]]的情况推出
//如果i比目前金额j要大，则不能放入硬币i，不考虑coins[i]
//如果i比目前金额j小，则可以放入硬币i，dp[j]=dp[j-coins[i]]+1，硬币数要+1
//因为要取最小的dp[j]，因此dp[j]=min(dp[j],dp[j-coins[i]]+1);
//3.初始化dp数组
//dp[0]=0;金额为0时，一个硬币也不放，由于要求最小值，所以其他位置要初始化为INT_MAX，像之前的题那样取0的话所求结果都会被0覆盖
//4.遍历顺序，外层硬币，内层金额，反过来也可以，因为只要求最小硬币数量，跟硬币有没有顺序没啥关系，所以都可以
//5.debug
//时间复杂度为O(amount*n)，空间复杂度为O(amount)
class Solution
{
public:
	int coinChange(vector<int>& coins, int amount)
	{
		vector<long long>dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i < coins.size(); ++i)
		{
			for (int j = coins[i]; j <= amount; ++j)
			{
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			}
		}
		return dp[amount] == INT_MAX ? -1 : dp[amount];
	}
};