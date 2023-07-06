#include <iostream>
#include <vector>
#include "StopWatch.h"

using namespace std;
const int arr_size = 9;

void Heap_Sort(vector<int> &arr, int size, vector<int> &result);
int Compare(vector<int> &arr, int size, int index);
void Swap(int& a, int& b);

int main()
{
	StopWatch check;

	check.Start();
	for (int i = 0; i < 1000; i++)
	{
		vector<int> arr = { 10, 9, 5, 8, 3, 2, 4, 6, 7, 1 };
		const int arr_size = arr.size() - 1;
		vector<int> result;

		Heap_Sort(arr, arr_size, result);

		cout << endl;
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << " ";
		}
		cout << endl;
	}
	check.Stop();
	cout << check.getElapsedTime() << "ms" << endl;

	return 0;
}


void Heap_Sort(vector<int> &arr, int size, vector<int> &result)
{
	if (size == 0)
	{
		result.push_back(arr[0]);
		return;
	}

	Compare(arr, size, 0);
	if (arr[0] < arr[1])
		Swap(arr[0], arr[1]);

	result.push_back(arr[0]);
	arr[0] = arr[size];

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;

	Heap_Sort(arr, size-1, result);
}

int Compare(vector<int> &arr, int size, int index)
{
	int a, b, c;
	if (size >= index * 2 + 2)
		b = Compare(arr, size, index * 2 + 2);
	else
		return index;

	if (size >= index * 2 + 1)
		a = Compare(arr, size, index * 2 + 1);
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