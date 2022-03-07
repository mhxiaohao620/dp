#include<iostream>
using namespace std;
#include<vector>
//1.dp[i][j]����Ϊǰi����Ʒ����ȡ��������Ϊj�ı����У���������Ʒ������ֵ
//2.���ƹ�ʽ������������ܷ��µ�i-1����Ʒ����dp[i-1][j]������ܷ��£��ӷźͲ�����ѡ�����ֵ
//dp[i][j]=max(dp[i-1][j],dp[i][j-weight[i-1]]+value[i-1]);ע���������Ʒi-1��״̬����Ϊ��Ʒi-1�ǿ����ظ�ѡ���
//������dp[i]
class Solution
{
public:
	//��άdp����
	int completeBag(vector<int>& value, vector<int>& weight, int Weight)
	{
		vector<vector<int>>dp(weight.size() + 1, vector<int>(Weight + 1, 0));
		//��ʼ����dp[0][j]=0;
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

	//һά
	//1.dp[j]Ϊ����Ϊj�ı�����װ��Ʒ������ֵ
	int completeBagI(vector<int>& value, vector<int>& weight, int W)
	{
		vector<int>dp(W + 1);
		//��ʼ����dp[0]=0������Ϊ0ʲôҲ�Ų���
		//��������Ʒ���ڲ��������������Ҫ��С�����������ܱ�֤��Ʒ�ظ����
		/*for (int i = 0; i <= weight.size(); ++i)
		{
			for (int j = weight[i]; j <= W; ++j)
			{
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			}
		}*/

		//����������ڲ���ƷҲ���ԣ���Ϊ��ȫ��������dp[i][j]��״̬��ǰһ��dp[i-1][j]�뵱ǰ��j�±�ǰ��
		//״̬�йأ�����ֻ��Ҫ����j֮ǰ���е�dpֵ����
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

