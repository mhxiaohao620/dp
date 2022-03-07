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

//��ȫ����ģ��İ汾
//��Ʒʱ�ֵ��е��ַ������������������ַ����ĳ���
//dp[j]��ʾ������Ϊj���ַ����ܷ����ֵ��е��ַ�����ɣ�
//���ƹ�ʽ��������Ʒi������ѡ����뱳������dp[j-wordDict[i].size()]��ʵ������dp[i][j-wordDict[i].size()]
//wordDict[i]���뱳��������£���s.substr(j-wordDict[i].size()��wordDict[i].size())==wordDict[i]�������dp[j-wordDict[i].size()]Ϊ�棬��ôdp[j]ҲΪ��
//Ҳ����ѡ�񲻷��뱳������dp[j](ʵ������dp[i-1][j])
//����˳�򣬲�ͬ�������ַ�������Ҫ�����ֵ����ж��Ƿ�����ɣ����Ա����������⣬��Ʒ����
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