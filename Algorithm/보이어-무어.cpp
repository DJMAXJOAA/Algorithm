#include <iostream>
#include <vector>
#include "StopWatch.h"

using namespace std;

void PatternTable(string pattern, vector<int>& x);
void BoyerMoore(string str, string pattern, vector<int>& pattern_index);
void PrintStr(string x, int index);

int main()
{
	StopWatch check;
	check.Start();
	for (int i = 0; i < 1000; i++)
	{
		cout << i << endl;
		string str = { "trusthardtoothbrushes" };
		string pattern = { "tooth" };
		vector<int> pattern_index;
		PatternTable(pattern, pattern_index);
		BoyerMoore(str, pattern, pattern_index);
	}
	check.Stop();
	cout << check.getElapsedTime() << "ms";

	return 0;
}

void PatternTable(string pattern, vector<int>& x)
{
	for (int i = 0; i < pattern.now_size() - 1; i++)
	{
		x.push_back(pattern.now_size() - i - 2);
	}
	x.push_back(pattern.now_size() - 1);
}

void BoyerMoore(string str, string pattern, vector<int>& pattern_index)
{
	int rear = pattern.now_size() - 1;
	for (int i = 0; i < str.now_size() - pattern.now_size(); i++)
	{
		cout << endl;
		int j;
		if (str[i + rear] != pattern[rear])
		{
			for (j = rear - 1; j >= 0; j--)
			{
				cout << j << " ";
				if (str[i + rear] == pattern[j])
				{
					i += pattern_index[j];
					break;
				}
			}
			if (j == -1)
			{
				i += pattern_index[rear];
			}
		}
		else
		{
			for (j = rear - 1; j >= 0; j--)
			{
				cout << j << " ";
				if (str[i + j] != pattern[j])
				{
					i += j;
					break;
				}
			}
			if (j == -1)
			{
				return;
			}
		}
	}
}

void PrintStr(string x, int index)
{
	for (int i = 0; i < index; i++)
	{
		cout << "_ ";
	}
	for (auto& i : x)
	{
		cout << i << " ";
	}
	cout << endl;
}