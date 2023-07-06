#include <iostream>
#include "StopWatch.h"

using namespace std;

int compare = 0;
int swap_count = 0;
const int arr_size = 10;

void QuickSort(int pivot, int range, int arr[]);
void Swap(int& a, int& b);

int main()
{
	StopWatch check;

	check.Start();
	for (int i = 0; i < 1000; i++)
	{
		int arr[arr_size] = { 10, 9, 5, 8, 3, 2, 4, 6, 7, 1 };

		for (int i = 0; i < arr_size; i++)
			cout << arr[i] << ",";
		cout << endl;

		QuickSort(0, arr_size - 1, arr);

		for (int i = 0; i < arr_size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	check.Stop();

	cout << check.getElapsedTime() << "ms";

	return 0;
}

void QuickSort(int pivot, int end, int arr[])
{
	if (end <= pivot)
		return;
	int left = pivot + 1; // 1บฮลอ
	int right = end;

	while (right>=left)
	{
		while (arr[left] < arr[pivot])left++;
		while (arr[right] > arr[pivot])right--;
		if (left < right)
			Swap(arr[left], arr[right]);
		else
			break;
	}
	Swap(arr[pivot], arr[right]);
	//for (int i = 0; i < arr_size; i++)
	//	cout << arr[i] << ",";
	//cout << endl;

	QuickSort(pivot, right - 1, arr);
	QuickSort(right + 1, end, arr);
}




void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}