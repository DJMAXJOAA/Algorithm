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
		for (int i = 0; i < str.size() - comp.size(); i++)
		{
			count++;

			int j;
			for (j = 0; j < comp.size(); j++)
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

			if (j == comp.size())
				break;
		}
	}
	check.Stop();
	cout << check.getElapsedTime() << "ms";
	//cout << str.size() - comp.size() - 1 << "ȸ �� �õ�" << endl;
	//cout << count << "��° ��ġ";
	return 0;
}

void Print(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
	cout << endl;
}