#include<iostream>
using namespace std;
#include<vector>
//1.ȷ��dp�����Լ��±�ĺ���
//dp[i]��ʾ�����±�Ϊi��̨�׵��ܻ���
//2.ȷ�����ƹ�ʽ��Ҫ���ܻ�����ͣ�֧��һ�η��ÿ�����һ����������̨�ף����ȡ��ǰһ��̨�׻�ǰ����̨��������i��̨�׻��ѵ���Сֵ
//dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
//3.dp����ĳ�ʼ��
//dp[0]=0,dp[1]=0,��0��̨�׻���1��̨������������Ǯ
//4.ȷ������˳��
//��ǰ����ע�����Ҫ���������һ��̨��֮����㵽��¥����������Ľ����dp[n]��n=cost.size()
//5.�ٸ�����debug
class Solution
{
public:
	int minCostClimbingStairs(vector<int>& cost)
	{
		int n = cost.size();
		/*int* dp = new int[n + 1]{ 0 };
		dp[0] = dp[1] = 0;*/
		int dp[3] = { 0 };
		dp[0] = dp[1] = 0;
		if (n > 2)
		{
			/*for (int i = 2; i <= n; ++i)
			{
				dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
			}
			return dp[n];*/
			for (int i = 2; i <= n; ++i)
			{
				dp[2] = min(dp[1] + cost[i - 1], dp[0] + cost[i - 2]);
				dp[0] = dp[1];
				dp[1] = dp[2];
			}
			return dp[2];
		}
		return min(cost[0], cost[1]);
	}
};