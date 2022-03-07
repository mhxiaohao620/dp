#include<iostream>
using namespace std;
#include<vector>

//��άdp����ĵ�һ�����
class Solution1
{
public:
	int totalweight = 4;
	vector<int>weight{ 1,3,4 };
	vector<int>value{ 15,20,30 };

	int maxValue()
	{
		//�д�����Ʒ���д�����������0��totalweight
		vector<vector<int>>dp(weight.size(), vector<int>(totalweight + 1, 0));
		//��ά����dp�ĳ�ʼ��
		for (int j = 0; j <= totalweight; ++j)
		{
			if (j >= weight[0])
			{
				dp[0][j] = value[0];
			}
		}
		//��������Ʒ���ڲ��������
		//for (int i = 1; i < weight.size(); ++i)
		//{
		//	for (int j = 1; j <= totalweight; ++j)
		//	{
		//		if (j < weight[i])//�����޷�������i������
		//		{
		//			dp[i][j] = dp[i - 1][j];
		//		}
		//		else
		//		{
		//			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		//		}
		//	}
		//}
		
		//�������������ڲ������Ʒ
		for (int j = 1; j <= totalweight; ++j)
		{
			for (int i = 1; i < weight.size(); ++i)
			{
				if (j < weight[i])//�����޷�������i������
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
				}
			}
		}
		//��ӡһ��dp���鿴�������������ֱ�����ʽ��ӡ����dp��������ͬ��
		for (auto& outer : dp)
		{
			for (auto& v : outer)
			{
				cout << v << " ";
			}
			cout << endl;
		}

		
		return dp.back()[totalweight];
	}
};

class Solution2
{
public:
	int totalweight = 4;
	vector<int>weight{ 1,3,4 };
	vector<int>value{ 15,20,30 };

	int maxValue()
	{
		//ע���ʱ�е�ȡֵiҪ��ȡ��weight.size()����Ϊdp[i]����Ϊǰi����Ʒ��iȡ��weight.size()���ܱ��������һ����Ʒ
		vector<vector<int>>dp(weight.size() + 1, vector<int>(totalweight + 1, 0));
		//��ʼ��dp����
		//����dp����ĺ��壬dp[0][j]Ӧ�ö�Ϊ0��dp[i][0]ҲӦ�ö�Ϊ0������dpʱ�Ѿ�ֱ�ӳ�ʼ����

		//�����������Ʒ�ڲ�����
		for (int i = 1; i <= weight.size(); ++i)
		{
			for (int j = 1; j <= totalweight; ++j)
			{
				if (j < weight[i-1])
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
				}
			}
		}

		//��������ڲ���Ʒ
		/*for (int j = 1; j <= totalweight; ++j)
		{
			for (int i = 1; i <= weight.size(); ++i)
			{
				if (j < weight[i - 1])
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
				}
			}
		}*/

		//��ӡһ��
		for (auto& outer : dp)
		{
			for (auto& v : outer)
			{
				cout << v << " ";
			}
			cout << endl;
		}
		return dp.back()[totalweight];
	}
};

//һάdp������
class Solution
{
public:
	int totalweight = 4;
	vector<int>weight{ 1,3,4 };
	vector<int>value{ 15,20,30 };

	int maxValue()
	{
		vector<int>dp(totalweight + 1, 0);
		//��ʼ������Ϊ0���ɣ�dp[0]һ��Ϊ0
		//����˳�����Ҫ��һ�����ȱ�����Ʒ�����������������Ҫ�Ӵ�С
		for (int i = 0; i < weight.size(); ++i)
		{
			for (int j = totalweight; j >= weight[i]; --j)
			{
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			}
		}
		//��ӡ
		for (auto& v : dp)
		{
			cout << v << " ";
		}
		cout << endl;
		return dp.back();
	}
};

void test01()
{
	Solution s1;
	s1.maxValue();
}

int main()
{
	test01();
	system("pause");
	return 0;
}