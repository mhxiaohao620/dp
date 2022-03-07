#include<iostream>
using namespace std;
#include<vector>
//���˻�������������Կ��Ƕ�̬�滮
//��̬�滮�岽
//1.ȷ��dp������±꺬�壬�Լ��ܽ��һ�����ɣ�һ��dp�����ֵ����Ҫ���صĴ𰸣����dp�ͱ�ʾ���˻�
//dp[i]�ͱ�ʾ��i�������õ����˻�
//dp[i]��ʾ��������i��ֵ����������˻�
//2.ȷ�����ƹ�ʽ
//��Ҫ�ѷֲ�������������������֡��ķ�ʽ��һ�Ƕ���j��1��n��j*(i-j)���൱���������
//����j*dp[i-j]����Ϊi-j���������Ҫ��ֵģ�dp[i-j]�൱�ڲ��i-j���õ������˻�
//j�Ͳ��ò���ˣ���Ϊj��1��i�ı������̾��Ǳ���ֵĹ���
//���dp[i]=max(dp[i],max(j*(i-j),j*dp[i-j]));
//3.dp�����ʼ��
//dp[2]=1��dp[0]=dp[1]=0����Ϊ���ǲ��ܲ��
//4.ȷ������˳���ɵ��ƹ�ʽ�õ�dp[i]��ֵ��dp[i-j]��ֵ��أ���˱����ȵõ�dp[i-j]��ֵ
//���ԣ�iҪ��С����j��1��i-1����Ӧ��i�Ǵ�3��ʼ��n
//5.debugʱ����

//����һ����̬�滮
//ʱ�临�Ӷ�ΪO(n^2)���ռ临�Ӷ�ΪO(n)
class Solution
{
public:
	int integerBreak(int n)
	{
		vector<int>dp(n + 1);
		dp[2] = 1;
		for (int i = 3; i <= n; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
			}
		}
		return dp[n];
	}
};

//����2��������ѧ��פ��Ϊe����˲��������2��3ʱȡ�����
//ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(n)
int integerBreak(int n)
{
	vector<int>dp(n + 1);
	dp[2] = 1;
	for (int i = 3; i <= n; ++i)
	{
		//ֻ�п��ܲ�ֳ�2��3ʱ�ﵽ���
		dp[i] = max(max(2 * (i - 2), 2 * dp[i - 2]), max(3 * (i - 3), 3 * dp[i - 3]));
	}
	return dp[n];
}

//����3������ѧ
//ʱ�临�Ӷ�ΪO(1)���ռ临�Ӷ�ΪO(1)
int integerBreak1(int n)
{
	//��nС�ڵ���3ʱ�����һ��1
	if (n <= 3)
	{
		return n - 1;
	}
	
	//n�ܿ��Բ��Ϊa��3��b����n=3a+b����ʽ
	int a = n / 3;
	int b = n % 3;
	if (b == 0)		
	{
		return (int)pow(3, a);
	}
	else if (b == 1)
	{
		return 4 * (int)pow(3, a - 1);
	}
	return 2 * (int)pow(3, a);
}