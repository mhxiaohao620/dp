#include<iostream>
using namespace std;
#include<vector>

//����˵���������������ʵ˳��ͬ�����б�������ͬ����ϣ�ʵ���Ͼ�����������
//��Ϊ����ֻҪ�����еĸ����������ð��������ж��г����������û�����ʵ�������Žⷨ��
//������������ѡȡ������Ŀ�������ܺ�target�������뵽��ȫ�������⣬
//����������о��Ǳ�������������target����Ʒ���������������ͼ�ֵ����nums[i]
//��������ת��Ϊ�����������뱳����ʹ�ñ��������ж����ַ�������������������������
//�������������˳��Ҫ����������ڲ���Ʒ

//1.dp�����Լ��±꺬��
//dp[j]��ʾ�����ܺ�Ϊjʱ��˳��ͬ��������������˵���������ķ���
//2.ȷ�����ƹ�ʽ
//��������nums[i]�����j<nums[i]�����޷���nums[i]���뱳������dp[j]����j>=nums[i]ʱ��
//�����ܺ�Ϊj-nums[i]ʱ���������ʱ��������Ϊdp[j-nums[i]]��ֻ��Ҫ��nums[i]���뼴�ɣ����dp[j]+=dp[j-nums[i]];
//3.dp�����ʼ��
//��j=0ʱ��ʲô���������÷ţ������һ�ַ�������dp[0]=1;
//4.����˳��һ������������ڲ���Ʒ������С����֤��Ʒ���ظ�ʹ��
//5.debug
class Solution
{
public:
	int combinationSum4(vector<int>& nums, int target)
	{
		vector<int>dp(target + 1);
		dp[0] = 1;
		for (int j = 0; j <= target; ++j)
		{
			for (int i = 0; i < nums.size(); ++i)
			{
				if (j >= nums[i] && dp[j] < INT_MAX - dp[j - nums[i]])
				{
					dp[j] += dp[j - nums[i]];
				}
			}
		}
		return dp[target];
	}
};

//�����뵽�ľ��ǻ��ݣ���Ϊ���������������������
class Backtracking
{
public:
	int ret = 0;
	void backtracking(vector<int>& nums, int target, int sum)//��Ϊ���в�ͬ�������ʵ���������⣬���Բ���Ҫstart����
	{
		//�����ǰ������ܺ�=target�ˣ����+1��������һ��
		if (sum == target)
		{
			++ret;
			return;
		}
		if (sum > target)
		{
			return;
		}
		//������ǰ�㣬��������ÿ�α�������0��ʼ
		for (int i = 0; i < nums.size(); ++i)
		{
			backtracking(nums, target, sum + nums[i]);
		}
	}
	int combinationSum4(vector<int>& nums, int target)
	{
		backtracking(nums, target, 0);
		return ret;
	}
};