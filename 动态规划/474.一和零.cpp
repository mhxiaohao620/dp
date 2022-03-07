#include<iostream>
using namespace std;
#include<vector>
#include<string>
//����������Ҫ���ҵ��Ӽ��������m��0������Ӽ��ĳ��ȣ���ô�����Ծ���01��������
//��Ʒ����ÿ���ַ�����Ҫ��ĳ��Ⱦ�Ӧ���Ǽ�ֵvalue�����ַ�������Ŀ����ÿ���ַ����ļ�ֵΪ1��
//����������������m����Ʒ��������Ϊ���ܹ��׵�0�ĸ���zero
//��ôdp[j]��Ϊ����������Ϊjʱ�����뱳����Ԫ�ص������������������Ϊvalue
//���ƹ�ʽΪdp[j]=max(dp[j],dp[j-zero]+1);

//������ֻ������������Ʒ����������һ��ά�ȣ���ôֻ��Ҫ��ά�����ά�ȼ���
//����һ�������������Ӽ����������������Ӧ����m+n��
//dp[i][j]Ϊ��������Ϊi��0��j��1�ı�����Ԫ�ص�����������������value
//���赱ǰ���������ַ���str����zero��0��one��1��zero��one��Ϊ����ά�ȵ�����
//��ô�������ַ��������뱳����״̬����dp[i][j]��������뱳����û��ǰ��״̬��dp[i-zero][j-one]�������Ԫ�ظ���+1
//��dp[i][j]=max(dp[i][j],dp[i-zero][j-one]+1);

//���Է��֣���������������m+n����Ʒ�����ַ�������Ʒ������������ά�ȣ�һ����0������һ����1������
//�ַ����ĸ�������value
class Solution
{
public:
	int findMaxForm(vector<string>& strs, int m, int n)
	{

		vector<vector<int>>dp(m + 1, vector<int>(n + 1));
		for (auto& str : strs)//������Ʒ
		{
			int zero = 0;
			int one = 0;
			for (auto& c : str)
			{
				if (c == '0')
				{
					++zero;
				}
				else
				{
					++one;
				}
			}
			for (int i = m; i >= zero; --i)
			{
				for (int j = n; j >= one; --j)
				{
					dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
				}
			}
		}
		return dp[m][n];
	}
};