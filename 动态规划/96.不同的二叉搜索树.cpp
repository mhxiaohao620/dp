#include<iostream>
using namespace std;
#include<vector>
//1.确定dp数组和下标含义
//假设dp[i]为i个结点，不同的i个值为结点值能组成的BST数目
//2.确定递推公式
//取n=4，则以1或4为根结点有dp[3]×dp[0]个，以2或3为根结点有dp[2]×dp[1]个
//取n=5，则以1或5为根结点有dp[4]×dp[0]个，以2或4为根结点有dp[3]×dp[1]个，以3为根结点有dp[2]×dp[2]个
//i为偶数时，dp[i]=Σ2*dp[i-j-1]*dp[j],j为[0,i/2-1]
//i为奇数时，dp[i]=Σ2*dp[i-j-1]*dp[j]+dp[j+1]*dp[j+1]
//3.初始化dp数组，dp[0]=1,dp[1]=1,dp[2]=2
//4.从j为0开始遍历，i为1开始遍历
//5.debug举例

//这道题其实比较难想到用dp，对于这种题目，需要先分析几种简单的情况，看看有没有递推公式，如果有递推公式，可以考虑用dp解答
//假设dp[i]为i个结点，不同的i个值为结点值能组成的BST数目，
//对于n = 4，即根节点分别为1, 2, 3, 4这种情况，如果选定根节点为2，则其能组成的BST数目为dp[1] * dp[2]，即1个元素能组成的BST数乘2个元素能组成的BST数，选定根节点为3则为dp[2] * dp[1]，
//进一步地，如果是1 - i的情况，选定根节点为j（j为[1, i]），以j为根结点的BST数为dp[j - 1] * dp[i - j]，j - 1为j左边的元素个数，i - j为j右边的元素个数，因此找到了递推公式，使用动态规划解决

//递推公式：以i为根结点的树，dp[i]值等于从1到i每个元素作为头结点所能组成的二叉搜索树的数量
// 等于以不同值作为头结点，其左子树能组成的数目×右子树能组成的数目的总和
//设j从1到i，dp[j-1]为以j为头结点，左子树能组成的BST数目，dp[i-j]为以j为头结点，右子树能组成的BST数目
//dp[i]+=dp[j-1]*dp[i-j];（j-1为j左子树的元素个数，i-j为j右子树的元素个数，根据dp定义，他们的dp值即为左右子树能组成的BST个数）

//此时只需要初始化dp[0]=1，初始化为0则乘法的结果都变为0了
class Solution
{
public:
	int numTrees(int n)
	{
		vector<int>dp(n + 1);
		/*dp[0] = dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; ++i)
		{
			for (int j = 0; j < i / 2; ++j)
			{
				dp[i] += 2 * dp[i - j - 1] * dp[j];
			}
			if (i % 2 == 1)
			{
				dp[i] += dp[i / 2] * dp[i / 2];
			}
		}*/
		dp[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				dp[i] += dp[j - 1] * dp[i - j];
			}
		}
		return dp[n];
	}
};