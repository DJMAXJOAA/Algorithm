#include <iostream>

using namespace std;

void Print(string str);

int main()
{
	int count = 0;

	string str;
	cin >> str;
	string comp;
	cin >> comp;

	cout << endl;

	for (int i = 0; i < str.size() - comp.size(); i++)
	{
		count++;

		

		int j;
		for ( j = 0; j < comp.size(); j++)
		{
			Print(str);
			for (int k = 0; k < j+i; k++)
			{
				cout << " ";
			}
			if (comp[j] != str[i + j])
			{
				cout << "|" << endl;
				for (int k = 0; k < i; k++)
				{
					cout << " ";
				}
				Print(comp);
				break;
			}
			cout << "+" << endl;
			for (int k = 0; k < i; k++)
			{
				cout << " ";
			}
			Print(comp);
		}
		
		cout << "-----------------------------" << endl;

		if (j == comp.size())
			break;
	}

	cout << str.size() - comp.size() - 1 << "회 비교 시도" << endl;
	cout << count << "번째 일치";
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
