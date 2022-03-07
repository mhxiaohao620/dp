#include<iostream>
using namespace std;
#include<vector>
//1.ȷ��dp������±꺬��
//dp[i][j]�����start�ߵ������±�Ϊ[i,j]����·����
//2.ȷ�����ƹ�ʽ
//dp[i][j]=dp[i-1][j]+dp[i][j-1];
//3.dp�����ʼ������Ϊֻ�����һ������ƶ������Ժ�start����ͬһ�е�һ������λ��·������Ϊ1����dp[1][j]=1
//ͬ��dp[i][1]=1;
//4.ȷ������˳��i��1��m��j��1��n
//5.debugʱ�����Ƶ�
//ʱ�临�Ӷ�ΪO(mn)���ռ临�Ӷ�ΪO(mn)
class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		//����ʵ�����൱�ڰ�n��m������һ��
		vector<vector<int>>dp(n + 1, vector<int>(m + 1));
		//��ʼ��dp
		for (int j = 1; j <= n; ++j)
		{
			dp[j][1] = 1;
		}
		for (int i = 1; i <= m; ++i)
		{
			dp[1][i] = 1;
		}
		for (int j = 2; j <= n; ++j)
		{
			for (int i = 2; i <= m; ++i)
			{
				dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
			}
		}
		return dp[n][m];
	}
	//�Ż��ռ�汾
	//dp[i][j]��ֵ�����͵�i�к͵�i-1�е�ֵ���
	int uniquePaths1(int m, int n)
	{
		vector<int>dp(n, 1);
		//�൱���ۼƵ�һά��������
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)//dp��ֵ�����Ѿ��ۻ���ͬһ��ǰ������ˣ�����ֻ��Ҫ������һ��ǰ���·����
			{
				dp[j] += dp[j - 1];
			}
		}
		return dp.back();
	}
};

//��ѧ������������ϣ��ܹ���Ҫ������n-1����������m-1�������ܹ���m+n-2����ѡ��m-1�������ߵķ���
//�����
//ʱ�临�Ӷ�ΪO(m)���ռ临�Ӷ�ΪO(1)
//��Ϊ����m��n����Դ𰸲���Ӱ�죬���Կռ临�Ӷȿ����Ż�ΪO(min(m,n))
int uniquePaths(int m, int n)
{
	long long ret = 1;
	for (int x = n, y = 1; y < m; ++x, ++y)
	{
		//Ϊ�˷�ֹ�����ÿ�γ˷���ʱ��Ҫ��Ӧ�ĳ���ĸ
		//�������ͷ�ĸ��һ��
		ret = ret * x / y;
	}
	return ret;
}