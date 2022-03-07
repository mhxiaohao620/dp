#include<iostream>
using namespace std;
#include<vector>
//��Ŀ�У�ÿ�ֹ�����һ��ӯ���ƻ���ֻ��ʹ��һ�Σ��뵽01������ÿ����Ʒֻ��ʹ��һ�Σ���������������ά��
//һ���������ƿ϶���Ա����ҪС�ڵ���n����һ������������С����Ҫ���ڵ���minProfit����������������Ա��������������ά��
//������ĿҪ��ģ���Ա�������Ϊnʱ����������ΪminProfitʱ����ɹ����ķ�����
//��Ӧ�أ�1.dp����ĺ��壺dp[j][k]ΪԱ�������Ϊj����������Ϊkʱ����ɹ����ķ�����
//����k������Ӧ����[0,minProfit]����Ϊ���������������Ϊk������ΪminProfit�������������ĿҪ����
//2.ȷ�����ƹ�ʽ������һ���i�����Ա����̫�ٲ�����ɣ���ô���Ǳ����״̬�������Ա����������Ҫ�ı䣬dp[j][k]��ʵ������dp[i-1][j][k]
//���Ա�������������ɣ���ô��Ҫ��ǰһ��״̬��ǰһ��״̬��Ա�������Ϊj-group[i]
//ע���������ﶨ����������Ϊk����ôǰһ��״̬����������Ϊk-profit[i]����ʱk-profit[i]���ܻ���ָ�ֵ���������ʱҪ��������
//���k<=profit[i];��������i�Ͱ����Ҫ���k���������ˣ���ôǰ��Ĺ����Ͳ���Ҫ���ˣ���ǰһ��״̬������Ϊ0���ɣ���dp[j-group[i]][0]
//���k>profit[i];��������i�ܹ����profit[i]�Ľ��ȣ�����k-profit[i]��Ҫǰ��Ĺ�����ɣ���ǰһ��״̬����������Ҫ��k-profit[i]����dp[j-group[i]][k-profit[i]]
//3.��ʼ��dp���飬������k=0ʱ����������Ϊ���٣�dp[j][0]=1���������κι������ɣ�����һ�ַ���
//4.����˳�������Ʒ���ڲ����������������Ӵ�С
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
					dp[j][k] = (dp[j][k] + dp[j - group[i]][max(0, k - profit[i])]) % mod;//��Ϊ�������mod���������ﲻ��д��dp[i][j]+=
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