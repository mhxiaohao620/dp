#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
//其实和416.分割等和子集差不多，把石头尽量分成重量相等的两堆，相撞之后剩下的石头重量最小
//1.dp数组含义
//dp[j]表示容量为j的背包，最多可以背的石头的总重
//2.递推公式
//dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
//3.dp数组初始化
//dp[0]=0;
//4.遍历顺序
//外层石头内层容量，容量从大到小遍历
class Solution
{
public:
	int lastStoneWeightII(vector<int>& stones)
	{
		auto sum = accumulate(stones.begin(), stones.end(), 0);
		auto target = sum / 2;//向下取整
		vector<int>dp(target + 1, 0);
		for (int i = 0; i < stones.size(); ++i)
		{
			for (int j = target; j >= stones[i]; --j)
			{
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}
		}
		//由于target向下取整，而dp[target]最多等于target，因此dp[target]这堆石头一定小于等于sum-dp[target]这堆石头
		return sum - dp[target] - dp[target];
	}
};

void test01()
{
	Solution s;
	vector<int>stones{ 31,26,33,21,40 };
	s.lastStoneWeightII(stones);
}

int main()
{
	test01();
	system("pause");
	return 0;
}