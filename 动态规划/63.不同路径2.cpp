#include<iostream>
using namespace std;
#include<vector>
//1.确定dp数组和下标含义
//dp[i][j]表示走到第matrix[i][j]位置的路径数
//2.确定递推公式，如果matrix[i][j]处没有障碍并且matrix[i][j-1]和matrix[i-1][j]处也没有障碍
//dp[i][j]=dp[i-1][j]+dp[i][j-1];
//如果matrix[i][j]处有障碍，则dp[i][j]=0;
//如果matrix[i][j-1]和matrix[i-1][j]处也有障碍，则不能统计dp[i][j-1]和dp[i-1][j]的贡献
//3.dp数组的初始化（这道题初始化是坑！）
//在起点没有障碍的情况下，首先初始化dp[0][0]=1，然后根据障碍初始化第一行和第一列，因为第一行或第一列上一旦有障碍，那么该行或该列后面的位置就无法到达了
//4.确定遍历顺序：从每一行的左向右遍历，从上向下
//5.debug时举个例子

//时间复杂度为O(mn)
//空间复杂度为O(mn)
class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		/*if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
		{
			return 0;
		}*/
		vector<vector<int>>dp(m, vector<int>(n, 0));
		//初始化
		dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
		for (int i = 1; i < m; ++i)
		{
			if (obstacleGrid[i][0] == 1)
			{
				dp[i][0] = 0;
			}
			else
			{
				dp[i][0] = dp[i - 1][0];
			}
		}
		for (int j = 1; j < n; ++j)
		{
			if (obstacleGrid[0][j] == 1)
			{
				dp[0][j] = 0;
			}
			else
			{
				dp[0][j] = dp[0][j - 1];
			}
		}
		//遍历
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (obstacleGrid[i][j] != 1 && obstacleGrid[i - 1][j] != 1 && obstacleGrid[i][j - 1] != 1)
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
				else if (obstacleGrid[i][j] == 1)
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] += obstacleGrid[i - 1][j] == 0 ? dp[i - 1][j] : 0;
					dp[i][j] += obstacleGrid[i][j - 1] == 0 ? dp[i][j - 1] : 0;
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};

//优化空间版本
//时间复杂度为O(mn)，空间复杂度为O(min(m,n))
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	int m = obstacleGrid.size();
	int row = m;
	int n = obstacleGrid[0].size();
	int col = n;
	//实现空间最优，O(min(m,n))
	if (m < n)
	{
		swap(m, n);
		row = n;
		col = m;
	}
	vector<int>dp(col, 0);
	dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
	//初始化
	for (int i = 1; i < col; ++i)
	{
		if (obstacleGrid[0][i] == 1)
		{
			dp[i] = 0;
		}
		else
		{
			dp[i] = dp[i - 1];
		}
	}
	//遍历
	for (int i = 1; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (j >= 1)
			{
				if (obstacleGrid[i][j] == 1)
				{
					dp[j] = 0;
				}
				else if (obstacleGrid[i][j] == 0 && obstacleGrid[i - 1][j] == 0 && obstacleGrid[i][j - 1] == 0)
				{
					dp[j] += dp[j - 1];
				}
				else
				{
					dp[j] = obstacleGrid[i - 1][j] == 0 ? dp[j] : dp[j - 1];//如果前一行同一列没障碍，那就是前一列同一行有障碍，就应该取前一行的dp值
				}
			}
			else
			{
				dp[j] = obstacleGrid[i - 1][j] == 0 && obstacleGrid[i][j] == 0 ? dp[j] : 0;//上一行没障碍，这一行也没障碍，才能等于上一行的，否则就是0
			}
		}
	}
	return dp[col - 1];
}