#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
//本来和是sum，现在要改变一些数的符号，那么很容易想到把正数和负数分开成两部分，将其中的一部分作为01背包问题求解
//设正数和的绝对值为positive，负数和的绝对值为negative(提取所有负号在前面即可)，则有positive-negative=target;
//而positive+negative=sum;因此推出positive=(target+sum)/2
//所以把正数的这一部分设为背包，背包的最大容量为(target+sum)/2，如果最大容量不是正数，说明这个问题无解
//则元素就是物品

//1.确定dp数组和下标含义
//dp[j]表示背包容量为j的时候，装满容量为j的背包有多少种方法，还是注意，题目求什么，就把dp数组值设为什么！
//2.递推公式
//装满j-nums[i]容量的背包有dp[j-nums[i]]种方法，只要放入nums[i]，那么这dp[j-nums[i]]种方法就能为j背包所用了，所以dp[j]+=dp[j-nums[i]]
//3.dp数组初始化，dp[0]=1;装满容量为0的背包有一种方法，就是什么也不放
//4.遍历顺序，外层元素，内层容量，容量从大到小遍历，
//5.debug

//时间复杂度为O(m*n)，m为背包容量，n为元素个数
//空间复杂对O(m)，背包容量
class Solution
{
public:
	int findTargetSumWays(vector<int>& nums, int target)
	{
		auto sum = accumulate(nums.begin(), nums.end(), 0);
		int ret = 0;
		if (target > sum || target < -sum)
		{
			return 0;
		}
		if ((target + sum) % 2 == 1)//因为nums[i]都是整数，所以如果容量带小数的话一定不行
		{
			return 0;
		}
		auto positive = (target + sum) / 2;
		vector<int>dp(positive + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = positive; j >= nums[i]; --j)
			{
				dp[j] += dp[j - nums[i]];
			}
		}
		return dp[positive];
	}
};

//自己想的思路也对，就是题解的思路！
//如果有nums[i]+nums[j]+nums[k]+.....+nums[n]+nums[m]=sum，现在需要让一些元素改变符号，使得这个等式结果变为
//-(nums[i]+nums[j]+....+nums[n])+nums[m]=target;假设改变了从i到n的元素
//那么两个式子相减即为2*(nums[i]+....+nums[n])=sum-target;
//即需要找到一个容量sum-target的背包，选择2*nums[i]的元素放进去并放满，有多少种放元素的方法
//那么dp数组的含义一定要设置为，dp[j]表示，将容量为j的背包放满的方法数
//然后再来确定递推公式，这第一步确定dp的含义很重要！


//时间复杂度为O((sum-target)*n),
//空间复杂度为O(sum-target)，其实dp数组开一半，然后元素的重量是nums[i]即可
int findTargetSumWays(vector<int>& nums, int target)
{
	auto sum = accumulate(nums.begin(), nums.end(), 0);
	if (target<-sum || target>sum)
	{
		return 0;
	}
	auto size = sum - target;
	if (size % 2 == 1)
	{
		return 0;
	}
	auto diff = size / 2;
	vector<int>dp(diff + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = diff; j >= nums[i]; --j)
		{
			dp[j] += dp[j - nums[i]];
		}
	}
	return dp.back();
}

void test01()
{
	Solution s;
	vector<int>nums{ 2,1,0,2,1};
	s.findTargetSumWays(nums, 0);
}

int main()
{
	test01();
	system("pause");
	return 0;
}