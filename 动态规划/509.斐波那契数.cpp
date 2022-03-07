#include<iostream>
using namespace std;
//1.确定dp数组以及下标的含义
//dp[i]的含义是，第i个数的斐波那契值是dp[i]
//2.确定递推公式，题目已经给我们了
//dp[i] = dp[i - 1] + dp[i - 2];
//3.dp数组初始化，也给了
//dp[0] = 0; dp[1] = 1;
//4.确定遍历顺序，由递推公式，dp[i]的值依赖于dp[i - 1]和dp[i - 2]的值，所以是从前向后遍历
//5.举个例子推导，比如i=10，dp数组的值应该如下：
//0 1 1 2 3 5 8 13 21 34 55，如果代码不对，就打印dp数组看看与推导的dp数组值是否一致
class Solution
{
public:
	int fib(int n)
	{
		if (n > 1)
		{
			/*int* dp = new int[n + 1];
			dp[0] = 0;
			dp[1] = 1;
			for (int i = 2; i <= n; ++i)
			{
				dp[i] = dp[i - 1] + dp[i - 2];
			}
			return dp[n];*/

			//实际上，不需要维护数组也可以
			int dp0 = 0, dp1 = 1, ret = 0;
			for (int i = 2; i <= n; ++i)
			{
				ret = dp0 + dp1;
				dp0 = dp1;
				dp1 = ret;
			}
			return ret;
		}
		return n;
	}
};