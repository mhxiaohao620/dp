#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>
#include<unordered_map>
//һ�ۻ��ݷ�ö��
//�Լ�д�ģ�һ���Ż�:���ù�ϣ���¼�ֵ��е��ַ��������ָ�Ľ��������ͨ����ϣ������жϸ÷ָ���ĵ����Ƿ��ڴʵ���
//Ҳ��ac������100%,90%
class Solution
{
public:
	vector<string>ret;
	unordered_set<string>record;
	//���ݺ���
	//����ֵΪvoid����ΪҪ�������е����
	//�����б�Ҫ�б�����ʼλ����Ϊͬһ����ĸ���ܶ��ѡ��
	void backtracking(string& s, vector<string>& wordDict, int start, string str)
	{
		//�ݹ���ֹ����
		//����ָ�ַ������������ֹ�����Ѵ𰸼�������
		if (start >= s.size())
		{
			str.pop_back();
			ret.emplace_back(str);
			return;
		}
		//�������㣬i��Ϊ�ָ���
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

//�ٷ���⣬����������ϣ��һ���Ż��⣬�����Խ����ڶ�����ϣ������¼���±�i��ʼ������ɵľ�������Щ
//����ڻ��ݹ������������Ѿ����ʹ����±꣬��ֱ�ӿ��Դӵڶ�����ϣ���еõ�����������ظ����㣬
//����ƥ����±��ڹ�ϣ���ж�Ӧ���ǿ��б�

class Solution1
{
private:
	unordered_map<int, vector<string>>recordIndex;
	unordered_set<string>recordWord;

public:
	void backtracking(string& s, int start)
	{
		//������±��Ѿ���������ˣ������账����
		if (recordIndex.find(start) == recordIndex.end())//�����ϣ���в����ڵ�ǰ�±꣬����Ҫ��¼��
		{		
			//�ݹ���ֹ����������Ѿ�����s���յ㣬��Ӵ��±꿪ʼ������ɾ��ӣ���ϣ���м�¼Ϊ���б�������
			if (start == s.size())
			{
				recordIndex[start] = { "" };
				return;
			}
			recordIndex[start] = {};//�ڹ�ϣ���м�¼��ǰ�±�
			for (int i = start; i < s.size(); ++i)
			{
				auto str = s.substr(start, i - start + 1);
				if (recordWord.find(str) != recordWord.end())//�ָ���ĵ������ֵ���
				{
					backtracking(s, i + 1);//�ݹ鵽��һ�㣬�����ָ�
					//�ָ�����֮�󣬰Ѵӵ�ǰ�±�start��ʼ������ɵľ��Ӷ����뵽��ϣ����
					//��ʱ�ָ����������i+1;��i+1�±꿪ʼ����ɵľ��Ӵ�����recordIndex[i+1]��
					for (auto& sentence : recordIndex[i + 1])
					{
						//�����ɵľ���Ϊ�գ���ֱ�Ӽ��뵱ǰ�ָ��ĵ��ʣ�����ͽ���������������¾���
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