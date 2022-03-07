#include<iostream>
using namespace std;
#include<vector>
//最大乘积，最优问题可以考虑动态规划
//动态规划五步
//1.确定dp数组和下标含义，自己总结的一个规律：一般dp数组的值都是要返回的答案，因此dp就表示最大乘积
//dp[i]就表示把i拆分所获得的最大乘积
//dp[i]表示将正整数i拆分的整数的最大乘积
//2.确定递推公式
//需要把分拆的数都×起来，有两种×的方式，一是定义j从1到n，j*(i-j)，相当于两数相乘
//二是j*dp[i-j]，因为i-j这个数是需要拆分的，dp[i-j]相当于拆分i-j数得到的最大乘积
//j就不用拆分了，因为j从1到i的遍历过程就是被拆分的过程
//因此dp[i]=max(dp[i],max(j*(i-j),j*dp[i-j]));
//3.dp数组初始化
//dp[2]=1，dp[0]=dp[1]=0，因为它们不能拆分
//4.确定遍历顺序，由递推公式得到dp[i]的值与dp[i-j]的值相关，因此必须先得到dp[i-j]的值
//所以，i要从小到大，j从1到i-1，相应的i是从3开始到n
//5.debug时举例

//方法一，动态规划
//时间复杂度为O(n^2)，空间复杂度为O(n)
class Solution
{
public:
	int integerBreak(int n)
	{
		vector<int>dp(n + 1);
		dp[2] = 1;
		for (int i = 3; i <= n; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
			}
		}
		return dp[n];
	}
};

//方法2：根据数学，驻点为e，因此拆分整数在2或3时取到最大
//时间复杂度为O(n)，空间复杂度为O(n)
int integerBreak(int n)
{
	vector<int>dp(n + 1);
	dp[2] = 1;
	for (int i = 3; i <= n; ++i)
	{
		//只有可能拆分出2或3时达到最大
		dp[i] = max(max(2 * (i - 2), 2 * dp[i - 2]), max(3 * (i - 3), 3 * dp[i - 3]));
	}
	return dp[n];
}

//方法3，纯数学
//时间复杂度为O(1)，空间复杂度为O(1)
int integerBreak1(int n)
{
	//当n小于等于3时，拆分一个1
	if (n <= 3)
	{
		return n - 1;
	}
	
	//n总可以拆分为a个3和b，即n=3a+b的形式
	int a = n / 3;
	int b = n % 3;
	if (b == 0)		
	{
		return (int)pow(3, a);
	}
	else if (b == 1)
	{
		return 4 * (int)pow(3, a - 1);
	}
	return 2 * (int)pow(3, a);
}