#include<iostream>
using namespace std;
#include<vector>
//1.确定dp数组以及下标的含义
//dp[i]表示到达下标为i的台阶的总花费
//2.确定递推公式：要求总花费最低，支付一次费用可以爬一个或者两个台阶，因此取从前一个台阶或前两个台阶跳到第i级台阶花费的最小值
//dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
//3.dp数组的初始化
//dp[0]=0,dp[1]=0,从0号台阶或者1号台阶起跳都不花钱
//4.确定遍历顺序
//从前到后，注意最后要遍历到最后一个台阶之后才算到达楼顶，即计算的结果是dp[n]，n=cost.size()
//5.举个例子debug
class Solution
{
public:
	int minCostClimbingStairs(vector<int>& cost)
	{
		int n = cost.size();
		/*int* dp = new int[n + 1]{ 0 };
		dp[0] = dp[1] = 0;*/
		int dp[3] = { 0 };
		dp[0] = dp[1] = 0;
		if (n > 2)
		{
			/*for (int i = 2; i <= n; ++i)
			{
				dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
			}
			return dp[n];*/
			for (int i = 2; i <= n; ++i)
			{
				dp[2] = min(dp[1] + cost[i - 1], dp[0] + cost[i - 2]);
				dp[0] = dp[1];
				dp[1] = dp[2];
			}
			return dp[2];
		}
		return min(cost[0], cost[1]);
	}
};