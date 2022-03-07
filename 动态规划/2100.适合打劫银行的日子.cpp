#include<iostream>
using namespace std;
#include<vector>
//看着像动态规划问题，第i天的两种状态可分别从第i-1天和第i+1天的推出,，即只需要知道第i-1天的警卫数目连续非递增的天数和第i+1天的警卫数目连续非递减的天数，
//再通过判断security[i]与security[i-1]和security[i+1]的关系即可得到第i天的状态
//1.dp数组含义：
//dp1[i]表示第i天前警卫数目连续非递增的天数
//dp2[i]表示第i天后警卫数目连续非递减的天数
//2.确定递推公式
//如果security[i]<=security[i-1]，则dp1[i]=dp1[i-1]+1;否则的话dp1[i]=0;
//如果security[i]<=security[i+1]，则dp2[i]=dp2[i+1]+1;否则的话dp2[i]=0;
//3.dp数组初始化
//dp1[0]=0;dp2[n]=0;
//4.遍历顺序
//确定dp1的值从前到后，确定dp2的值从后到前
//5.debug
//时间和空间复杂度均为O(n)
class Solution
{
public:
	vector<int>goodDaysToRobBank(vector<int>& security, int time)
	{
		int n = security.size();
		vector<int>dp1(n), dp2(n);
		vector<int>ret;
		for (int i = 1, j = n - 2; i < n && j >= 0; ++i, --j)
		{
			dp1[i] = security[i] <= security[i - 1] ? dp1[i - 1] + 1 : 0;
			dp2[j] = security[j] <= security[j + 1] ? dp2[j + 1] + 1 : 0;
		}
		for (int i = time; i < n - time; ++i)
		{
			if (dp1[i] >= time && dp2[i] >= time)
			{
				ret.emplace_back(i);
			}
		}
		return ret;
	}
};