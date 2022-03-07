#include<iostream>
using namespace std;
#include<vector>
//一眼完全背包问题，每种面额的硬币有无限个，对应于物品随便用，因此硬币就是物品
//amount就是背包的最大容量，面额就是硬币重量
//要求的是凑成最大容量的组合数
//1.dp数组以及下标含义
//dp[j]为总金额为j时，把硬币放入背包的方法数
//2.确定递推公式
//考虑总金额为j-coins[i]的情况，此时的方法数为dp[j-coins[i]]，那么再加一个coins[i]面额的硬币就可以了
//所以dp[j]+=dp[j-coins[i]];
//3.dp数组初始化
//当总金额为0时，什么硬币都不放入背包总金额就为0了，所以dp[0]=1;
//4.遍历顺序，完全背包问题容量从小到大遍历
//5.debug

//这道题遍历顺序还是有讲究，这道题要求的是组合数，比如amount是5，coins为1和2
//那么5=2+2+1，或者还有5=2+1+2，这两种情况其实是一种组合，都是2 2 1，应该统计为1
//而如果问的是排列数，那么上面这两种情况就是两种排列了，应该统计为2
//对于纯完全背包问题，两层for循环谁嵌套谁都可以，这是因为纯完全背包问题关注的是总和，只要总和能凑到
//怎么凑的无所谓，即凑的方案之间是组合还是排列都可以，所以两层for嵌套都可以

//求组合数就不关注顺序，因此只需要选定一种顺序即可，而排列对顺序有要求，一种顺序对应着一种排列
//而这道题不一样，外层物品内层容量的遍历顺序下，每次选择物品i，内层的容量只把物品i放入，因此这种遍历
//方式从是把每个物品i依次加入背包中，对于背包的每一个容量时，放入物品的顺序是确定的，不会有不同顺序的情况
//如果外层容量内层物品的遍历顺序，那么每遍历一个容量j，都要把每个物品i都放入一遍（如果能容纳下的话）
//即这个位置有好多个选择，不是确定的顺序了
//因此，求组合数要把物品或者完成的步骤放在外层循环，给他一个确定的顺序，比如这道题
//而求排列数就要把容量放在外层循环，让代码计算排列的情况，比如70.爬楼梯

//如果是二维dp数组的话，for循环的嵌套就无所谓了，因为dp[i][j]容量为j时表示选择物品i-1的方法数，这个时候
//已经确定选择一种物品了，即已经确定顺序了，所以此时再改变遍历先后顺序就不影响了
//或者说二维dp数组把所有的排列都记录了
class Solution
{
public:
	int change(int amount, vector<int>& coins)
	{
		int n = amount + 1;
		vector<int>dp(n);
		dp[0] = 1;
		/*for (int i = 0; i < coins.size(); ++i)
		{
			for (int j = coins[i]; j <= n - 1; ++j)
			{
				dp[j] += dp[j - coins[i]];
			}
		}*/
		for (int j = 0; j <= amount; ++j)
		{
			for (int i = 0; i < coins.size(); ++i)
			{
				if (j >= coins[i])
				{
					dp[j] += dp[j - coins[i]];
				}
			}
		}
		for (auto& v : dp)
		{
			cout << v << " ";
		}
		cout << endl;
		return dp.back();
	}
};

//二维的情况for循环嵌套顺序都可以
int change(int amount, vector<int>&coins)
{
	vector<vector<int>>dp(coins.size() + 1, vector<int>(amount + 1));
	for (int i = 0; i <= coins.size(); ++i)
	{
		dp[i][0] = 1;
	}
	
	for (int j = 0; j <= amount; ++j)
	{
		for (int i = 1; i <= coins.size(); ++i)
		{
			if (j >= coins[i - 1])
			{
				dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	for (auto& v1 : dp)
	{
		for (auto& v2 : v1)
		{
			cout << v2 << " ";
		}
		cout << endl;
	}
	return dp[coins.size()][amount];
}

void test01()
{
	Solution s1;
	vector<int>coins{ 1,2,5 };
	s1.change(5, coins);
	cout << endl;
	change(5, coins);
}

int main()
{
	test01();
	system("pause");
	return 0;
}