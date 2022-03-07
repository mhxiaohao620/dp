#include<iostream>
using namespace std;
#include<vector>
//Ӳ�ҿ�������ѡ����Ҫ��ճ��ܽ��amount���뵽��ȫ��������
//������������amount����Ʒ����Ӳ�ң���Ʒ�ؾ���Ӳ�Ҽ�ֵ
//���Ǳ�������һ��������Ҫ��ճ�amount��Ӳ�Ҹ�������
//1.dp�����Լ��±꺬��
//dp[j]Ϊ���Ϊjʱ����ѡӲ�Ҽ�ֵΪjʱ������Ӳ�Ҹ���
//2.ȷ�����ƹ�ʽ
//����Ӳ��i��dp[j]ֻ���ɲ�����Ӳ��i��dp[j-coins[i]]������Ƴ�
//���i��Ŀǰ���jҪ�����ܷ���Ӳ��i��������coins[i]
//���i��Ŀǰ���jС������Է���Ӳ��i��dp[j]=dp[j-coins[i]]+1��Ӳ����Ҫ+1
//��ΪҪȡ��С��dp[j]�����dp[j]=min(dp[j],dp[j-coins[i]]+1);
//3.��ʼ��dp����
//dp[0]=0;���Ϊ0ʱ��һ��Ӳ��Ҳ���ţ�����Ҫ����Сֵ����������λ��Ҫ��ʼ��ΪINT_MAX����֮ǰ��������ȡ0�Ļ����������ᱻ0����
//4.����˳�����Ӳ�ң��ڲ��������Ҳ���ԣ���ΪֻҪ����СӲ����������Ӳ����û��˳��ûɶ��ϵ�����Զ�����
//5.debug
//ʱ�临�Ӷ�ΪO(amount*n)���ռ临�Ӷ�ΪO(amount)
class Solution
{
public:
	int coinChange(vector<int>& coins, int amount)
	{
		vector<long long>dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i < coins.size(); ++i)
		{
			for (int j = coins[i]; j <= amount; ++j)
			{
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			}
		}
		return dp[amount] == INT_MAX ? -1 : dp[amount];
	}
};