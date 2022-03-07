#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
//��������sum������Ҫ�ı�һЩ���ķ��ţ���ô�������뵽�������͸����ֿ��������֣������е�һ������Ϊ01�����������
//�������͵ľ���ֵΪpositive�������͵ľ���ֵΪnegative(��ȡ���и�����ǰ�漴��)������positive-negative=target;
//��positive+negative=sum;����Ƴ�positive=(target+sum)/2
//���԰���������һ������Ϊ�������������������Ϊ(target+sum)/2����������������������˵����������޽�
//��Ԫ�ؾ�����Ʒ

//1.ȷ��dp������±꺬��
//dp[j]��ʾ��������Ϊj��ʱ��װ������Ϊj�ı����ж����ַ���������ע�⣬��Ŀ��ʲô���Ͱ�dp����ֵ��Ϊʲô��
//2.���ƹ�ʽ
//װ��j-nums[i]�����ı�����dp[j-nums[i]]�ַ�����ֻҪ����nums[i]����ô��dp[j-nums[i]]�ַ�������Ϊj���������ˣ�����dp[j]+=dp[j-nums[i]]
//3.dp�����ʼ����dp[0]=1;װ������Ϊ0�ı�����һ�ַ���������ʲôҲ����
//4.����˳�����Ԫ�أ��ڲ������������Ӵ�С������
//5.debug

//ʱ�临�Ӷ�ΪO(m*n)��mΪ����������nΪԪ�ظ���
//�ռ临�Ӷ�O(m)����������
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
		if ((target + sum) % 2 == 1)//��Ϊnums[i]�����������������������С���Ļ�һ������
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

//�Լ����˼·Ҳ�ԣ���������˼·��
//�����nums[i]+nums[j]+nums[k]+.....+nums[n]+nums[m]=sum��������Ҫ��һЩԪ�ظı���ţ�ʹ�������ʽ�����Ϊ
//-(nums[i]+nums[j]+....+nums[n])+nums[m]=target;����ı��˴�i��n��Ԫ��
//��ô����ʽ�������Ϊ2*(nums[i]+....+nums[n])=sum-target;
//����Ҫ�ҵ�һ������sum-target�ı�����ѡ��2*nums[i]��Ԫ�طŽ�ȥ���������ж����ַ�Ԫ�صķ���
//��ôdp����ĺ���һ��Ҫ����Ϊ��dp[j]��ʾ��������Ϊj�ı��������ķ�����
//Ȼ������ȷ�����ƹ�ʽ�����һ��ȷ��dp�ĺ������Ҫ��


//ʱ�临�Ӷ�ΪO((sum-target)*n),
//�ռ临�Ӷ�ΪO(sum-target)����ʵdp���鿪һ�룬Ȼ��Ԫ�ص�������nums[i]����
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