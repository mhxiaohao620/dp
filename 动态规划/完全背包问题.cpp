#include<iostream>
using namespace std;
#include<vector>
//1.dp[i][j]设置为前i件物品任意取放入容量为j的背包中，背包中物品的最大价值
//2.递推公式，如果容量不能放下第i-1件物品，则dp[i-1][j]，如果能放下，从放和不放中选择最大值
//dp[i][j]=max(dp[i-1][j],dp[i][j-weight[i-1]]+value[i-1]);注意这里放物品i-1的状态，因为物品i-1是可以重复选择的
//所以是dp[i]
class Solution
{
public:
	//二维dp数组
	int completeBag(vector<int>& value, vector<int>& weight, int Weight)
	{
		vector<vector<int>>dp(weight.size() + 1, vector<int>(Weight + 1, 0));
		//初始化，dp[0][j]=0;
		//dp[i][0]=0;
		for (int i = 1; i <= weight.size(); ++i)
		{
			for (int j = 1; j <= Weight; ++j)
			{
				if (j < weight[i - 1])
				{ 
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i - 1] + value[i - 1]]);
				}
			}
		}
		return dp[weight.size()][Weight];
	}

	//一维
	//1.dp[j]为容量为j的背包所装物品的最大价值
	int completeBagI(vector<int>& value, vector<int>& weight, int W)
	{
		vector<int>dp(W + 1);
		//初始化，dp[0]=0，容量为0什么也放不了
		//外层遍历物品，内层遍历容量，容量要从小到大，这样才能保证物品重复添加
		/*for (int i = 0; i <= weight.size(); ++i)
		{
			for (int j = weight[i]; j <= W; ++j)
			{
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			}
		}*/

		//外层容量，内层物品也可以，因为完全背包问题dp[i][j]的状态与前一行dp[i-1][j]与当前行j下标前的
		//状态有关，所以只需要计算j之前所有的dp值即可
		for (int j = 0; j <= W; ++j)
		{
			for (int i = 0; i < weight.size(); ++i)
			{
				if (j >= weight[i])
				{
					dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
				}
			}
		}
	}
};

