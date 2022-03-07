#include<iostream>
using namespace std;
//1.ȷ��dp�����Լ��±�ĺ���
//dp[i]�ĺ����ǣ���i������쳲�����ֵ��dp[i]
//2.ȷ�����ƹ�ʽ����Ŀ�Ѿ���������
//dp[i] = dp[i - 1] + dp[i - 2];
//3.dp�����ʼ����Ҳ����
//dp[0] = 0; dp[1] = 1;
//4.ȷ������˳���ɵ��ƹ�ʽ��dp[i]��ֵ������dp[i - 1]��dp[i - 2]��ֵ�������Ǵ�ǰ������
//5.�ٸ������Ƶ�������i=10��dp�����ֵӦ�����£�
//0 1 1 2 3 5 8 13 21 34 55��������벻�ԣ��ʹ�ӡdp���鿴�����Ƶ���dp����ֵ�Ƿ�һ��
class Solution
{
public:
	int fib(int n)
	{
		if (n > 1)
		{
			/*int* dp = new int[n + 1];
			dp[0] = 0;
			dp[1] = 1;
			for (int i = 2; i <= n; ++i)
			{
				dp[i] = dp[i - 1] + dp[i - 2];
			}
			return dp[n];*/

			//ʵ���ϣ�����Ҫά������Ҳ����
			int dp0 = 0, dp1 = 1, ret = 0;
			for (int i = 2; i <= n; ++i)
			{
				ret = dp0 + dp1;
				dp0 = dp1;
				dp1 = ret;
			}
			return ret;
		}
		return n;
	}
};