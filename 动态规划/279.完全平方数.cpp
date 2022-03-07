#include<iostream>
using namespace std;
#include<vector>
//用完全平方数凑和为n，示例表示同一个数能多次使用，想到了完全背包问题
//背包容量就是n，物品就是完全平方数，那么问题转化为：
//将完全平方数放入背包中，同样的数可以重复放入，当背包中完全平方数的和为n时，背包中完全平方数的最少数目
//1.dp数组和下标含义
//dp[j]表示和为j时，完全平方数的最少数量
//2.确定递推公式
//对于完全平方数i*i，当i*i大于j时则不考虑i*i，
//当i<=j时：当不考虑i时，和为j-i*i的最少数量为dp[j-i*i]，考虑i时，最少数量为dp[j-i*i]+1;
//因为要求dp[j]的最小值，所以dp[j]=min(dp[j],dp[j-i*i]+1)
//3.dp数组初始化，当j本身就是一个完全平方数时，dp[j]=1;其他位置初始化为最大值，避免在求min的过程中结果被覆盖
//此时不用初始化dp[0]因为j与i*i相同时，dp[j]=1；dp[0]+1就不需要使用了
//或者dp[0]=0;为了递推公式初始化，而非0下标的仍然是最大值
//4.遍历顺序，求的是最少数量，因此for循环的嵌套顺序不重要，完全背包问题容量从小到大，为了数能多次使用
//5.debug
class Solution
{
public:
	int numSquares(int n)
	{
		vector<int>dp(n + 1, 100000);
		for (int j = 1; j * j <= n; ++j)
		{
			dp[j * j] = 1;
		}
		//dp[0] = 0;
		for (int i = 1; i * i <= n; ++i)
		{
			for (int j = i * i; j <= n; ++j)
			{
				dp[j] = min(dp[j], dp[j - i * i] + 1);
			}
		}
		return dp[n];
	}
};