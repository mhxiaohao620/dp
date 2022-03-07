#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
//��ʵ��416.�ָ�Ⱥ��Ӽ���࣬��ʯͷ�����ֳ�������ȵ����ѣ���ײ֮��ʣ�µ�ʯͷ������С
//1.dp���麬��
//dp[j]��ʾ����Ϊj�ı����������Ա���ʯͷ������
//2.���ƹ�ʽ
//dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
//3.dp�����ʼ��
//dp[0]=0;
//4.����˳��
//���ʯͷ�ڲ������������Ӵ�С����
class Solution
{
public:
	int lastStoneWeightII(vector<int>& stones)
	{
		auto sum = accumulate(stones.begin(), stones.end(), 0);
		auto target = sum / 2;//����ȡ��
		vector<int>dp(target + 1, 0);
		for (int i = 0; i < stones.size(); ++i)
		{
			for (int j = target; j >= stones[i]; --j)
			{
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}
		}
		//����target����ȡ������dp[target]������target�����dp[target]���ʯͷһ��С�ڵ���sum-dp[target]���ʯͷ
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