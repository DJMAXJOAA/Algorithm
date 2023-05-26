#include <iostream>
using namespace std;

int main()
{
	int n = 6;
	for (int i = 1; i < n; i++)
	{ 
		int count = n * 2 + 1 - (i * 2);
		for (int k = 1; k < i; k++)
		{
			cout << " ";
		}
		for (int j = 0; j < count; j++)
		{
			cout << i;
		}
		for (int k = 1; k < i; k++)
		{
			cout << " ";
		}
		cout << endl;
	}

	for (int i = n; i >= 1; i--)
	{
		int count = n * 2 + 1 - (i * 2);
		for (int k = 1; k < i; k++)
		{
			cout << " ";
		}
		for (int j = 0; j < count; j++)
		{
			cout << i;
		}
		for (int k = 1; k < i; k++)
		{
			cout << " ";
		}
		cout << endl;
	}

	return 0;
}