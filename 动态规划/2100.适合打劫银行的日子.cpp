#include<iostream>
using namespace std;
#include<vector>
//������̬�滮���⣬��i�������״̬�ɷֱ�ӵ�i-1��͵�i+1����Ƴ�,����ֻ��Ҫ֪����i-1��ľ�����Ŀ�����ǵ����������͵�i+1��ľ�����Ŀ�����ǵݼ���������
//��ͨ���ж�security[i]��security[i-1]��security[i+1]�Ĺ�ϵ���ɵõ���i���״̬
//1.dp���麬�壺
//dp1[i]��ʾ��i��ǰ������Ŀ�����ǵ���������
//dp2[i]��ʾ��i�������Ŀ�����ǵݼ�������
//2.ȷ�����ƹ�ʽ
//���security[i]<=security[i-1]����dp1[i]=dp1[i-1]+1;����Ļ�dp1[i]=0;
//���security[i]<=security[i+1]����dp2[i]=dp2[i+1]+1;����Ļ�dp2[i]=0;
//3.dp�����ʼ��
//dp1[0]=0;dp2[n]=0;
//4.����˳��
//ȷ��dp1��ֵ��ǰ����ȷ��dp2��ֵ�Ӻ�ǰ
//5.debug
//ʱ��Ϳռ临�ӶȾ�ΪO(n)
class Solution
{
public:
	vector<int>goodDaysToRobBank(vector<int>& security, int time)
	{
		int n = security.size();
		vector<int>dp1(n), dp2(n);
		vector<int>ret;
		for (int i = 1, j = n - 2; i < n && j >= 0; ++i, --j)
		{
			dp1[i] = security[i] <= security[i - 1] ? dp1[i - 1] + 1 : 0;
			dp2[j] = security[j] <= security[j + 1] ? dp2[j + 1] + 1 : 0;
		}
		for (int i = time; i < n - time; ++i)
		{
			if (dp1[i] >= time && dp2[i] >= time)
			{
				ret.emplace_back(i);
			}
		}
		return ret;
	}
};