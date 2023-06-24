#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "StopWatch.h"

using namespace std;

void Print(int n, int index1, int index2);
void Print_arr(int n, vector<int> &arr);
void select1(int n, vector<int> &arr);
void select2(int n, vector<int> &arr);

int main()
{
	int n;
	cin >> n;
	
	vector<int> arr(0);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	vector<int> arr2 = arr;

	cout << "정렬 전 : ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;;

	{
		StopWatch check;
		check.Start();
		for (int i = 0; i < 100; i++)
		{
			arr2 = arr;
			select1(n, arr2);
		}
		cout << endl << "정렬 후1 : ";
		for (int i = 0; i < n; i++)
		{
			cout << arr2[i] << " ";
		}
		check.Stop();
		cout << "\n1번 : " << check.getElapsedTime() << "ms" << endl;
	}



	{
		StopWatch check;
		check.Start();
		for (int i = 0; i < 100; i++)
		{
			arr2 = arr;
			select2(n, arr2);
		}
		cout << endl << "정렬 후2 : ";
		for (int i = 0; i < n; i++)
		{
			cout << arr2[i] << " ";
		}
		check.Stop();
		cout << "\n2번 : " << check.getElapsedTime() << "ms" << endl;
	}

	return 0;
}

void Print(int n, int index1, int index2)
{
	for (int i = 0; i < n; i++)
	{
		if (i == index1)
			cout << "* ";
		else if (i == index2)
			cout << "+ ";
		else
			cout << "  ";
	}
	cout << endl;
}

void Print_arr(int n, vector<int> &arr)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void select1(int n, vector<int>& arr)
{
	for (int i = 0; i < n; i++)
	{
		int min = arr[i];
		int min_index = i;
		for (int j = i; j < n; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				min_index = j;
			}
		}
		Print(n, i, min_index);
		Print_arr(n, arr);
		swap(arr[i], arr[min_index]);
	}
}

void select2(int n, vector<int>& arr)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				Print(n, i, j);
				Print_arr(n, arr);
				swap(arr[i], arr[j]);
				i--;
				break;
			}
		}
	}
}
