#include <iostream>
#include "StopWatch.h"

using namespace std;

const int SIZE = 9;


void Print(int arr[]);
void Swap(int& a, int& b);
void Insert(int a, int b, int arr[]);

int main()
{
	StopWatch check;

	check.Start();
	for (int i = 0; i < 1000; i++)
	{
	int swap_cnt = 0;
	int comp_cnt = 0;
	int arr[SIZE] = { 5,3,8,4,9,1,6,2,7 };
	int devide = SIZE / 3 + 1;
	
	Print(arr);

		//while (devide != 1)
		//{
		//	int i = 0;
		//	while (i + devide < SIZE)
		//	{
		//		if (arr[i] > arr[i + devide])
		//		{
		//			Swap(arr[i], arr[i + devide]);
		//			swap_cnt++;
		//		}
		//		comp_cnt++;
		//		i++;
		//	}
		//	devide = devide / 3 + 1;
		//	Print(arr);
		//}

		//cout << "ÃÑ ºñ±³ È½¼ö : " << comp_cnt << ", ";
		//cout << "ÃÑ ½º¿Ò È½¼ö : " << swap_cnt << " // ";
		//Print(arr);

		for (int i = 1; i < SIZE; i++)
		{
			int a = SIZE, b = i;
			for (int j = 0; j < i; j++)
			{
				if (arr[j] >= arr[i])
				{
					a = j;
					b = i;
					Insert(a, b, arr);
					swap_cnt++;
					break;
				}
				comp_cnt++;
			}
			Print(arr);
			int x = 0;
			for ( x = 0; x < SIZE-1; x++)
			{
				if (arr[x + 1] < arr[x])
					break;
			}
			if (x == SIZE - 1)
				break;
		}

		cout << "ÃÑ ºñ±³ È½¼ö : " << comp_cnt << ", ";
		cout << "ÃÑ ½º¿Ò È½¼ö : " << swap_cnt << " // ";
		Print(arr);
	}
	check.Stop();
	cout << check.getElapsedTime() << "ms" << endl;

	
	return 0;
}

void Print(int arr[])
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}



void Insert(int a, int b, int arr[])
{
	int temp = arr[b];
	for (int i = b; i > a; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[a] = temp;
}
