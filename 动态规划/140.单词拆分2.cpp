#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>
#include<unordered_map>
//一眼回溯法枚举
//自己写的，一层优化:即用哈希表记录字典中的字符串，当分割的结果出来后，通过哈希表快速判断该分割出的单词是否在词典中
//也可ac，击败100%,90%
class Solution
{
public:
	vector<string>ret;
	unordered_set<string>record;
	//回溯函数
	//返回值为void，因为要返回所有的情况
	//参数列表，要有遍历起始位置因为同一个字母不能多次选择
	void backtracking(string& s, vector<string>& wordDict, int start, string str)
	{
		//递归终止条件
		//如果分割到字符串的最后，则终止，并把答案加入结果集
		if (start >= s.size())
		{
			str.pop_back();
			ret.emplace_back(str);
			return;
		}
		//遍历单层，i即为分割线
		for (int i = start; i < s.size(); ++i)
		{
			auto tempStr = s.substr(start, i - start + 1);
			if (record.find(tempStr) != record.end())
			{
				backtracking(s, wordDict, i + 1, str + tempStr + " ");
			}
		}
	}

	vector<string>wordBreak(string s, vector<string>& wordDict)
	{
		for (auto& word : wordDict)
		{
			record.emplace(word);
		}
		backtracking(s, wordDict, 0, "");
		return ret;
	}
};

//官方题解，除了上述哈希表一层优化外，还可以建立第二个哈希表，来记录从下标i开始可以组成的句子有哪些
//如果在回溯过程中遇到了已经访问过的下标，则直接可以从第二个哈希表中得到结果，无需重复计算，
//不能匹配的下标在哈希表中对应的是空列表

class Solution1
{
private:
	unordered_map<int, vector<string>>recordIndex;
	unordered_set<string>recordWord;

public:
	void backtracking(string& s, int start)
	{
		//如果该下标已经被处理过了，则无需处理了
		if (recordIndex.find(start) == recordIndex.end())//如果哈希表中不存在当前下标，则需要记录了
		{		
			//递归终止条件，如果已经到了s的终点，则从此下标开始不能组成句子，哈希表中记录为空列表，并返回
			if (start == s.size())
			{
				recordIndex[start] = { "" };
				return;
			}
			recordIndex[start] = {};//在哈希表中记录当前下标
			for (int i = start; i < s.size(); ++i)
			{
				auto str = s.substr(start, i - start + 1);
				if (recordWord.find(str) != recordWord.end())//分割出的单词在字典中
				{
					backtracking(s, i + 1);//递归到下一层，继续分割
					//分割完了之后，把从当前下标start开始的能组成的句子都加入到哈希表中
					//此时分割后的新起点是i+1;从i+1下标开始能组成的句子储存在recordIndex[i+1]中
					for (auto& sentence : recordIndex[i + 1])
					{
						//如果组成的句子为空，则直接加入当前分隔的单词，否则就将单词组合起来更新句子
						recordIndex[start].emplace_back(sentence.empty() ? str : str + " " + sentence);
					}
				}
			}
		}
	}
	vector<string>wordBreak(string s, vector<string>& wordDict)
	{
		for (auto& str : wordDict)
		{
			recordWord.emplace(str);
		}
		backtracking(s, 0);
		return recordIndex[0];
	}
};