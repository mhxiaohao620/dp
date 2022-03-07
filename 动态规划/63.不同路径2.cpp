#include<iostream>
using namespace std;
#include<vector>
//1.ȷ��dp������±꺬��
//dp[i][j]��ʾ�ߵ���matrix[i][j]λ�õ�·����
//2.ȷ�����ƹ�ʽ�����matrix[i][j]��û���ϰ�����matrix[i][j-1]��matrix[i-1][j]��Ҳû���ϰ�
//dp[i][j]=dp[i-1][j]+dp[i][j-1];
//���matrix[i][j]�����ϰ�����dp[i][j]=0;
//���matrix[i][j-1]��matrix[i-1][j]��Ҳ���ϰ�������ͳ��dp[i][j-1]��dp[i-1][j]�Ĺ���
//3.dp����ĳ�ʼ����������ʼ���ǿӣ���
//�����û���ϰ�������£����ȳ�ʼ��dp[0][0]=1��Ȼ������ϰ���ʼ����һ�к͵�һ�У���Ϊ��һ�л��һ����һ�����ϰ�����ô���л���к����λ�þ��޷�������
//4.ȷ������˳�򣺴�ÿһ�е������ұ�������������
//5.debugʱ�ٸ�����

//ʱ�临�Ӷ�ΪO(mn)
//�ռ临�Ӷ�ΪO(mn)
class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		/*if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
		{
			return 0;
		}*/
		vector<vector<int>>dp(m, vector<int>(n, 0));
		//��ʼ��
		dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
		for (int i = 1; i < m; ++i)
		{
			if (obstacleGrid[i][0] == 1)
			{
				dp[i][0] = 0;
			}
			else
			{
				dp[i][0] = dp[i - 1][0];
			}
		}
		for (int j = 1; j < n; ++j)
		{
			if (obstacleGrid[0][j] == 1)
			{
				dp[0][j] = 0;
			}
			else
			{
				dp[0][j] = dp[0][j - 1];
			}
		}
		//����
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (obstacleGrid[i][j] != 1 && obstacleGrid[i - 1][j] != 1 && obstacleGrid[i][j - 1] != 1)
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
				else if (obstacleGrid[i][j] == 1)
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] += obstacleGrid[i - 1][j] == 0 ? dp[i - 1][j] : 0;
					dp[i][j] += obstacleGrid[i][j - 1] == 0 ? dp[i][j - 1] : 0;
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};

//�Ż��ռ�汾
//ʱ�临�Ӷ�ΪO(mn)���ռ临�Ӷ�ΪO(min(m,n))
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	int m = obstacleGrid.size();
	int row = m;
	int n = obstacleGrid[0].size();
	int col = n;
	//ʵ�ֿռ����ţ�O(min(m,n))
	if (m < n)
	{
		swap(m, n);
		row = n;
		col = m;
	}
	vector<int>dp(col, 0);
	dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
	//��ʼ��
	for (int i = 1; i < col; ++i)
	{
		if (obstacleGrid[0][i] == 1)
		{
			dp[i] = 0;
		}
		else
		{
			dp[i] = dp[i - 1];
		}
	}
	//����
	for (int i = 1; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (j >= 1)
			{
				if (obstacleGrid[i][j] == 1)
				{
					dp[j] = 0;
				}
				else if (obstacleGrid[i][j] == 0 && obstacleGrid[i - 1][j] == 0 && obstacleGrid[i][j - 1] == 0)
				{
					dp[j] += dp[j - 1];
				}
				else
				{
					dp[j] = obstacleGrid[i - 1][j] == 0 ? dp[j] : dp[j - 1];//���ǰһ��ͬһ��û�ϰ����Ǿ���ǰһ��ͬһ�����ϰ�����Ӧ��ȡǰһ�е�dpֵ
				}
			}
			else
			{
				dp[j] = obstacleGrid[i - 1][j] == 0 && obstacleGrid[i][j] == 0 ? dp[j] : 0;//��һ��û�ϰ�����һ��Ҳû�ϰ������ܵ�����һ�еģ��������0
			}
		}
	}
	return dp[col - 1];
}