#include <iostream>

using namespace std;

void Print(int n);

int main()
{
	int n = 11;
	Print(n);

	return 0;
}

void Print(int n)
{
	for (int i = 0; i < n; i++)
	{
		bool check = false;
		for (int j = 0; j < n-1; j++)
		{
			if (i > n / 2)
			{
				if (j == i)
				{
					cout << "*";
					check = true;
				}
				else
				{
					if (check == true)
						cout << "+";
					else
						cout << " ";
				}
			}
			else
			{
				if (j == n - 1 - i)
				{
					cout << "*";
					check = true;
				}
				else
				{
					if (check == true)
						cout << "+";
					else
						cout << " ";
				}
			}
			
		}
		cout << "*" << endl;
	}
}
