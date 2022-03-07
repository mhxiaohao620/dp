#include<iostream>
using namespace std;
#include<vector>
//1.确定dp数组和下标含义
//dp[i][j]代表从start走到网格下标为[i,j]处的路径数
//2.确定递推公式
//dp[i][j]=dp[i-1][j]+dp[i][j-1];
//3.dp数组初始化，因为只能向右或向下移动，所以和start属于同一行第一行所有位置路径数都为1，即dp[1][j]=1
//同理，dp[i][1]=1;
//4.确定遍历顺序，i从1到m，j从1到n
//5.debug时举例推导
//时间复杂度为O(mn)，空间复杂度为O(mn)
class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		//这里实际上相当于把n和m交换了一下
		vector<vector<int>>dp(n + 1, vector<int>(m + 1));
		//初始化dp
		for (int j = 1; j <= n; ++j)
		{
			dp[j][1] = 1;
		}
		for (int i = 1; i <= m; ++i)
		{
			dp[1][i] = 1;
		}
		for (int j = 2; j <= n; ++j)
		{
			for (int i = 2; i <= m; ++i)
			{
				dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
			}
		}
		return dp[n][m];
	}
	//优化空间版本
	//dp[i][j]的值仅仅和第i行和第i-1行的值相关
	int uniquePaths1(int m, int n)
	{
		vector<int>dp(n, 1);
		//相当于累计到一维数组上了
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)//dp的值本身已经累积了同一列前面的行了，现在只需要加上这一行前面的路径数
			{
				dp[j] += dp[j - 1];
			}
		}
		return dp.back();
	}
};

//数学方法，排列组合，总共需要向右走n-1步，向下走m-1步，即总共走m+n-2步中选择m-1个向下走的方法
//即组合
//时间复杂度为O(m)，空间复杂度为O(1)
//因为交换m，n不会对答案产生影响，所以空间复杂度可以优化为O(min(m,n))
int uniquePaths(int m, int n)
{
	long long ret = 1;
	for (int x = n, y = 1; y < m; ++x, ++y)
	{
		//为了防止溢出，每次乘分子时都要对应的除分母
		//分子数和分母数一样
		ret = ret * x / y;
	}
	return ret;
}