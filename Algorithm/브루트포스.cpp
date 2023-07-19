#include <iostream>
#include "StopWatch.h"

using namespace std;

void Print(string str);

int main()
{
	int count = 0;

	StopWatch check;

	check.Start();
	for (int x = 0; x < 1000; x++)
	{
		cout << x << endl;

		string str = { "trusthardtoothbrushes" };
		string comp = { "tooth" };
		for (int i = 0; i < str.now_size() - comp.now_size(); i++)
		{
			count++;

			int j;
			for (j = 0; j < comp.now_size(); j++)
			{
				/*Print(str);*/
				for (int k = 0; k < j + i; k++)
				{
				}
				if (comp[j] != str[i + j])
				{
					cout << "|" << endl;
					for (int k = 0; k < i; k++)
					{
						cout << " ";
					}
					/*Print(comp);*/
					break;
				}
				//cout << "+" << endl;
				for (int k = 0; k < i; k++)
				{
				}
				/*Print(comp);*/
			}

			/*cout << "-----------------------------" << endl;*/

			if (j == comp.now_size())
				break;
		}
	}
	check.Stop();
	cout << check.getElapsedTime() << "ms";
	//cout << str.size() - comp.size() - 1 << "회 비교 시도" << endl;
	//cout << count << "번째 일치";
	return 0;
}

void Print(string str)
{
	for (int i = 0; i < str.now_size(); i++)
	{
		cout << str[i];
	}
	cout << endl;
}