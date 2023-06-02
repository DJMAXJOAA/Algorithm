#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

void print(int n, int low, int mid, int high, const vector<int>& value);

int main()
{
	int search;
	int n;

	cout << "검색값 입력 : ";
	cin >> search;

	cout << "배열 크기 입력 : ";
	cin >> n;

	vector<int> value(n);

	cout << "배열 데이터 입력 : ";
	for (int i = 0; i < n; i++)
	{
		cin >> value[i];
	}
	cout << endl;

	int low = 0;
	int high = n-1;
	int mid = high / 2;

	cout << "\t| ";
	for (int i = 0; i < n; i++)
	{
		printf("%3d", i);
	}
	cout << endl << "--------+---------------------------------------------" << endl;

	while (1)
	{
		print(n, low, mid, high, value);
		if (search >= value[mid])
		{
			if (search == value[mid])
			{
				cout << endl << "검색 완료!" << endl;
				break;
			}
			low = mid;
		}
		else
		{
			high = mid;
		}
		mid = (low + high) / 2;

		if (mid == low || mid == high)
		{
			cout << "검색값 없음" << endl;
			break;
		}
	}

	return 0;
}

void print(int n, int low, int mid, int high, const vector<int>& value)
{
	cout << "\t|  ";
	for (int i = 0; i < n; i++)
	{
		if (i == low)
			cout << "<- ";
		else if (i == high)
			cout << "->";
		else if (i == mid)
			cout << "+  ";
		else
			cout << "   ";
	}
	cout << endl << value[mid] << "\t| ";
	for (int i = 0; i < n; i++)
	{
		printf("%3d", value[i]);
	}
	cout << endl;
}
