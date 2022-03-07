#include<iostream>
using namespace std;
#include<vector>

//二维dp数组的第一种情况
class Solution1
{
public:
	int totalweight = 4;
	vector<int>weight{ 1,3,4 };
	vector<int>value{ 15,20,30 };

	int maxValue()
	{
		//行代表物品，列代表背包容量从0到totalweight
		vector<vector<int>>dp(weight.size(), vector<int>(totalweight + 1, 0));
		//二维数组dp的初始化
		for (int j = 0; j <= totalweight; ++j)
		{
			if (j >= weight[0])
			{
				dp[0][j] = value[0];
			}
		}
		//外层遍历物品，内层遍历容量
		//for (int i = 1; i < weight.size(); ++i)
		//{
		//	for (int j = 1; j <= totalweight; ++j)
		//	{
		//		if (j < weight[i])//背包无法容纳下i的重量
		//		{
		//			dp[i][j] = dp[i - 1][j];
		//		}
		//		else
		//		{
		//			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		//		}
		//	}
		//}
		
		//外层遍历容量，内层遍历物品
		for (int j = 1; j <= totalweight; ++j)
		{
			for (int i = 1; i < weight.size(); ++i)
			{
				if (j < weight[i])//背包无法容纳下i的重量
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
				}
			}
		}
		//打印一下dp数组看看，表明这两种遍历方式打印出的dp数组是相同的
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
		//注意此时行的取值i要能取到weight.size()，因为dp[i]定义为前i个物品，i取到weight.size()才能遍历到最后一个物品
		vector<vector<int>>dp(weight.size() + 1, vector<int>(totalweight + 1, 0));
		//初始化dp数组
		//根据dp数组的含义，dp[0][j]应该都为0，dp[i][0]也应该都为0，建立dp时已经直接初始好了

		//遍历，外层物品内层容量
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

		//外层容量内层物品
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

		//打印一下
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

//一维dp数组解决
class Solution
{
public:
	int totalweight = 4;
	vector<int>weight{ 1,3,4 };
	vector<int>value{ 15,20,30 };

	int maxValue()
	{
		vector<int>dp(totalweight + 1, 0);
		//初始化所有为0即可，dp[0]一定为0
		//遍历顺序很重要，一定是先遍历物品后遍历容量，且容量要从大到小
		for (int i = 0; i < weight.size(); ++i)
		{
			for (int j = totalweight; j >= weight[i]; --j)
			{
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			}
		}
		//打印
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