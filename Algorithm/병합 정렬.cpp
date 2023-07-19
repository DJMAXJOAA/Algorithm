#include <iostream>
#include <vector>
#include "StopWatch.h"

using namespace std;

void MergeSort(vector<int> &arr, int start_index, int end_index);
void Merge(vector<int>& arr, int front, int mid, int rear);

int main()
{
	StopWatch check;

	check.Start();
	for (int i = 0; i < 1000; i++)
	{
		vector<int> arr = { 10, 9, 5, 8, 3, 2, 4, 6, 7, 1 };

		for (int i = 0; i < arr.now_size(); i++)
			cout << arr[i] << " ";
		cout << endl;

		MergeSort(arr, 0, arr.now_size() - 1);

		for (int i = 0; i < arr.now_size(); i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	check.Stop();
	cout<<check.getElapsedTime()<<"ms";
	return 0;
}

void MergeSort(vector<int> &arr, int start_index, int end_index)
{
	int front = start_index;
	int rear = end_index;
	int mid = (front + rear) / 2;

	if (front<rear)
	{
		MergeSort(arr, front, mid);
		MergeSort(arr, mid + 1, rear);
		Merge(arr, front, mid, rear);
	}
}

void Merge(vector<int> &arr, int front, int mid, int rear)
{
	vector<int> temp1;
	vector<int> temp2;
	int result = 0;
	
	// ¹¶Ä¡1
	for (int i = front; i <= mid; i++)
	{
		temp1.push_back(arr[i]);
	}

	// ¹¶Ä¡2
	for (int i = mid+1; i <= rear; i++)
	{
		temp2.push_back(arr[i]);
	}

	int temp1size = 0;
	int temp2size = 0;
	int i = front;

	// º´ÇÕ
	while (1)
	{
		if (temp1size >= temp1.now_size())
		{
			for (int j = temp2size; j < temp2.now_size(); j++)
			{
				arr[i] = temp2[temp2size];
				temp2size++;
				i++;
			}
			break;
		}
		if (temp2size >= temp2.now_size())
		{
			for (int j = temp1size; j < temp1.now_size(); j++)
			{
				arr[i] = temp1[temp1size];
				temp1size++;
				i++;
			}
			break;
		}

		if (temp1[temp1size] < temp2[temp2size])
		{
			arr[i] = temp1[temp1size];
			temp1size++;
		}
		else
		{
			arr[i] = temp2[temp2size];
			temp2size++;
		}
		i++;
	}
	for (int i = front; i <= rear; i++)
		cout << arr[i] << " ";
	cout << endl;
	return;
}
