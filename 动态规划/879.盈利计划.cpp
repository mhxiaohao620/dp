#include<iostream>
using namespace std;
#include<vector>
//题目中，每种工作在一种盈利计划中只能使用一次，想到01背包，每个物品只能使用一次，还是容量的两种维度
//一种容量限制肯定是员工数要小于等于n，另一容量限制是最小利润要大于等于minProfit，所以这道题利润和员工数都是容量的维度
//根据题目要求的，求员工数最多为n时，利润最少为minProfit时，完成工作的方法数
//相应地，1.dp数组的含义：dp[j][k]为员工数最多为j，利润最少为k时，完成工作的方法数
//利润k的区间应该是[0,minProfit]，因为定义的是利润至少为k，至少为minProfit的利润就满足题目要求了
//2.确定递推公式，对于一项工作i，如果员工数太少不能完成，那么还是本身的状态，利润和员工数都不需要改变，dp[j][k]，实际上是dp[i-1][j][k]
//如果员工数够多可以完成，那么需要找前一个状态，前一个状态的员工数最多为j-group[i]
//注意利润，这里定义利润最少为k，那么前一个状态的利润最少为k-profit[i]，此时k-profit[i]可能会出现负值的情况，此时要分类讨论
//如果k<=profit[i];表明工作i就把最低要求的k利润给完成了，那么前面的工作就不需要做了，即前一个状态的利润为0即可，即dp[j-group[i]][0]
//如果k>profit[i];表明工作i能够完成profit[i]的进度，还差k-profit[i]需要前面的工作完成，即前一个状态的利润至少要有k-profit[i]，即dp[j-group[i]][k-profit[i]]
//3.初始化dp数组，当利润k=0时，人数无论为多少，dp[j][0]=1，即不做任何工作即可，都是一种方案
//4.遍历顺序，外层物品，内层两个容量，容量从大到小
class Solution
{
public:
	int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>profit)
	{
		vector<vector<int>>dp(n + 1, vector<int>(minProfit + 1));
		int mod = pow(10, 9) + 7;
		for (int i = 0; i <= n; ++i)
		{
			dp[i][0] = 1;
		}
		for (int i = 0; i < group.size(); ++i)
		{
			for (int j = n; j >= group[i]; --j)
			{
				for (int k = minProfit; k >= 0; --k)
				{
					dp[j][k] = (dp[j][k] + dp[j - group[i]][max(0, k - profit[i])]) % mod;//因为后面除了mod，所以这里不能写成dp[i][j]+=
				}
			}
		}
		return dp[n][minProfit];
	}
};

int main()
{

	system("pause");
	return 0;
}