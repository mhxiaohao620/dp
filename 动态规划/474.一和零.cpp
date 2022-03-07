#include<iostream>
using namespace std;
#include<vector>
#include<string>
//如果这道题是要求找到子集中最多有m个0的最大子集的长度，那么很明显就是01背包问题
//物品就是每个字符串，要求的长度就应该是价值value，即字符串的数目，即每个字符串的价值为1，
//而背包容量最大就是m，物品的重量即为其能贡献的0的个数zero
//那么dp[j]即为，背包容量为j时，放入背包的元素的最大个数，这个个数即为value
//递推公式为dp[j]=max(dp[j],dp[j-zero]+1);

//而现在只不过容量和物品的重量多了一个维度，那么只需要多维护这个维度即可
//建立一个背包用来放子集，背包的最大容量应该是m+n，
//dp[i][j]为背包容量为i个0和j个1的背包中元素的最大个数，个数就是value
//假设当前遍历到的字符串str中有zero个0和one个1，zero和one即为两个维度的重量
//那么如果这个字符串不放入背包，状态就是dp[i][j]，如果放入背包，没放前的状态是dp[i-zero][j-one]，放入后元素个数+1
//即dp[i][j]=max(dp[i][j],dp[i-zero][j-one]+1);

//可以发现，背包的容量就是m+n，物品就是字符串，物品的重量有两个维度，一个是0的数量一个是1的数量
//字符串的个数就是value
class Solution
{
public:
	int findMaxForm(vector<string>& strs, int m, int n)
	{

		vector<vector<int>>dp(m + 1, vector<int>(n + 1));
		for (auto& str : strs)//遍历物品
		{
			int zero = 0;
			int one = 0;
			for (auto& c : str)
			{
				if (c == '0')
				{
					++zero;
				}
				else
				{
					++one;
				}
			}
			for (int i = m; i >= zero; --i)
			{
				for (int j = n; j >= one; --j)
				{
					dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
				}
			}
		}
		return dp[m][n];
	}
};