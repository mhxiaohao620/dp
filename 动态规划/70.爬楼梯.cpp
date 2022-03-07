#include<iostream>
using namespace std;
#include<vector>
//1.确定dp数组和下标含义
//dp[i]表示到达i阶台阶的方法数
//2.确定递推公式
//找规律，当跳到第i-1级台阶时，再跳一步就是第i级了，当跳到第i-2级台阶时，再跳两步就是第i级了
//因此：跳到第i级台阶的方法=跳到第i-1级台阶的方法数+跳到第i-2级台阶的方法数
//dp[i]=dp[i-1]+dp[i-2],(i>=3)
//3.dp数组初始化：dp[1]=1,dp[2]=2,
//4.确定遍历顺序：从前向后
//5.举个例子debug用
class Solution
{
public:
	int climbStairs(int n)
	{
		int dp[4] = { 0 };
		dp[1] = 1;
		dp[2] = 2;
		int ret = 0;
		if (n >= 3)
		{
			for (int i = 3; i <= n; ++i)
			{
				ret = dp[1] + dp[2];
				dp[1] = dp[2];
				dp[2] = ret;
			}
			return dp[2];
		}
		return n;
	}
};

//如果这道题改成，每次可以上1-m阶台阶，到达第n阶台阶的方法
//很明显是一个完全背包问题，爬的台阶数可以重复使用，背包容量就是n，物品就是1阶，2阶....m阶
//因此求得就是装满背包的方法数，而且是排列数！
//所以容量要放在外层
//递推公式：当爬到j-i级台阶的时候，再向上上一级就可以了，因此dp[j]+=dp[j-i];
//下列代码中的m改成2，即为70的AC代码
int climbStairs(int n, int m)
{
	vector<int>dp(n + 1, 0);
	dp[0] = 1;
	for (int j = 1; j <= n; ++j)
	{
		for (int i = 1; i <= m; ++i)
		{
			if (j >= i)
			{
				dp[j] += dp[j - i];
			}
		}
	}
	return dp[n];
}