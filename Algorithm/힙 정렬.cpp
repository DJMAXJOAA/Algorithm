#include <iostream>
#include <vector>
#include "StopWatch.h"

using namespace std;
const int arr_size = 9;

void Heap_Sort(vector<int> &arr, int now_size, vector<int> &result);
int Compare(vector<int> &arr, int now_size, int index);
void Swap(int& a, int& b);

int main()
{
	StopWatch check;

	check.Start();
	for (int i = 0; i < 1000; i++)
	{
		vector<int> arr = { 10, 9, 5, 8, 3, 2, 4, 6, 7, 1 };
		const int arr_size = arr.now_size() - 1;
		vector<int> result;

		Heap_Sort(arr, arr_size, result);

		cout << endl;
		for (int i = 0; i < result.now_size(); i++)
		{
			cout << result[i] << " ";
		}
		cout << endl;
	}
	check.Stop();
	cout << check.getElapsedTime() << "ms" << endl;

	return 0;
}


void Heap_Sort(vector<int> &arr, int now_size, vector<int> &result)
{
	if (now_size == 0)
	{
		result.push_back(arr[0]);
		return;
	}

	Compare(arr, now_size, 0);
	if (arr[0] < arr[1])
		Swap(arr[0], arr[1]);

	result.push_back(arr[0]);
	arr[0] = arr[now_size];

	for (int i = 0; i < now_size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < result.now_size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;

	Heap_Sort(arr, now_size-1, result);
}

int Compare(vector<int> &arr, int now_size, int index)
{
	int a, b, c;
	if (now_size >= index * 2 + 2)
		b = Compare(arr, now_size, index * 2 + 2);
	else
		return index;

	if (now_size >= index * 2 + 1)
		a = Compare(arr, now_size, index * 2 + 1);
	else
		return index;

	if (arr[a] < arr[b])
		Swap(arr[a], arr[b]);
	c = a;

	if (arr[index] < arr[c])
		Swap(arr[index], arr[c]);
	return index;
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}