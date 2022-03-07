#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<numeric>
//�ָ�Ⱥ��Ӽ����������01���������
//��ΪҪ�������Ӽ�Ԫ�غ���ͬ������Ԫ�ض�������������ônums��Ԫ���ܺ�һ��Ҫ��ż����������Ҫ��
//�õ�Ԫ���ܺͺ󣬡�2����һ���Ӽ��е�����Ԫ�غ�Ӧ�ôﵽ��Ŀ����
//������������Ϊ�Ӽ�����������Ԫ��ֵ���ܺͣ���Ϊtarget=sum/2;
//��ô����Ҫ�������ƷʱԪ�أ�Ԫ�ص�������Ԫ�ص�ֵ����ֵҲ��Ԫ�ص�ֵ
//����ֻҪװ���ˣ���˵���Ӽ��е�Ԫ��ֵ���ܺͿ��Դﵽtarget�ˣ����ҵ��˺�Ϊtarget���Ӽ���
//�����е�Ԫ���ǲ������ظ�ʹ�õ�

//ͨ�����ϵķ�����������ȷ���������þ���01����������

//1.ȷ��dp������±꺬��
//dp[j]��ʾ������������j������������Ԫ�صĺ͵����ֵ
//2.���ƹ�ʽ��
//��Ʒi��������nums[i]����ֵҲ��nums[i]
//��01������dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
//3.dp�����ʼ��
//dp[0]������Ӧ�õ���0��dp��������λ�ó�ʼ��Ϊ0
//4.����˳������Ʒ�������������Ӵ�С
//5.debug

//ʱ�临�Ӷ�ΪO(n*target)���ռ临�Ӷ�ΪO(target)
class Solution
{
public:
	bool canPartition(vector<int>& nums)
	{
		auto sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 == 1)
		{
			return false;
		}
		auto target = sum / 2;
		int n = nums.size();
		vector<int>dp(target + 1, 0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = target; j >= nums[i]; --j)
			{
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
				//dp[j]һ����С�ڵ���j�ģ���Ϊdp[j]��ʾ�͵����ֵ��j������Ǻ͵����ֵ
				if (dp[target] == target)//�������������Ԫ�غ���target���
				{
					return true;
				}
			}
		}
		return false;
	}
};

//��ά����dp
bool canPartition(vector<int>& nums)
{
	auto sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2 == 1)
	{
		return false;
	}
	auto target = sum / 2;
	int n = nums.size();
	vector<vector<int>>dp(n, vector<int>(target + 1, 0));
	for (int j = 0; j <= target; ++j)
	{
		if (j >= nums[0])
		{
			dp[0][j] = nums[0];
		}
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j <= target; ++j)
		{
			if (j < nums[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
			}
		}
	}
	return dp[n - 1][target] == target;
}