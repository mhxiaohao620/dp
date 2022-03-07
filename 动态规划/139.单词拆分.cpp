#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>

class Solution
{
public:
	bool workBreak(string s, vector<string>& wordDict)
	{
		int n = s.size();
		unordered_set<string>record(wordDict.begin(), wordDict.end());
		vector<bool>dp(n + 1, false);
		dp[0] = true;
		for (int j = 1; j <= n; ++j)
		{
			for (int i = 0; i < j; ++i)
			{
				if (record.find(s.substr(i, j - i)) != record.end() && dp[i])
				{
					dp[j] = true;
				}
			}
		}
		return dp[n];
	}
};

//完全背包模板的版本
//物品时字典中的字符串，背包容量就是字符串的长度
//dp[j]表示，长度为j的字符串能否由字典中的字符串组成，
//递推公式：对于物品i，可以选择放入背包，则dp[j-wordDict[i].size()]（实际上是dp[i][j-wordDict[i].size()]
//wordDict[i]放入背包的情况下（即s.substr(j-wordDict[i].size()，wordDict[i].size())==wordDict[i]），如果dp[j-wordDict[i].size()]为真，那么dp[j]也为真
//也可以选择不放入背包，则dp[j](实际上是dp[i-1][j])
//遍历顺序，不同容量的字符串都需要遍历字典来判断是否能组成，所以背包容量在外，物品在内
class Solution1
{
public:
	bool workBreak(string s, vector<string>& wordDict)
	{
		int n = s.size();
		vector<bool>dp(n + 1, false);
		dp[0] = true;
		for (int j = 1; j <= n; ++j)
		{
			for (auto& item : wordDict)
			{
				if (j >= item.size() && s.substr(j - item.size(), item.size()) == item)
				{
					dp[j] = dp[j] || dp[j - item.size()];

				}
			}
		}
		return dp[n];
	}
};