#include <iostream>
#include <vector>
#include <list>

using namespace std;

void Print1(int n, int a, int b);
void Print2(vector<int> &arr);
void InsertSort(int n, vector<int> &arr);
void Insert(int a, int b, vector<int> &arr);

int main()
{
	int n = 7;
	vector<int> arr(n);
	arr = { 6,4,8,5,2,9,7 };
	cout << "정렬 전 : ";
	Print2(arr);

	InsertSort(n, arr);

	cout << "정렬 후 : ";
	Print2(arr);

	return 0;
}

void Print1(int n, int a, int b)
{
	int i;
	bool check = false;
	for (i = 0; i < n; i++)
	{
		if (i == a)
		{
			cout << "^";
			check = true;
		}
		else if (i == b)
		{
			if (!check)
				cout << " ";
			cout << "+";
			break;
		}

		if (check)
			cout << "--";
		else
			cout << "  ";
	}
	cout << endl;
}

void Print2(vector<int>& arr)
{
	vector<int>::iterator itr = arr.begin();
	for (vector<int>::iterator itr = arr.begin(); itr != arr.end(); itr++)
	{
		cout << " " << *itr;
	}
	cout << endl;
}

void InsertSort(int n, vector<int>& arr)
{
	for (int i = 1; i < n; i++)
	{
		int a = n, b = i;
		Print2(arr);
		for (int j = 0; j < i; j++)
		{
			if (arr[j] >= arr[i])
			{
				a = j;
				b = i;
				Insert(a, b, arr);
				break;
			}
		}
		
		Print1(n, a, b);
	}
}

void Insert(int a, int b, vector<int>& arr)
{
	int temp = arr[b];
	for (int i = b; i > a; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[a] = temp;
}
