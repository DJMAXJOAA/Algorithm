#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void swap(int *a, int *b);

int main()
{
	const int size = 6;
	int arr[size];

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < size/2; i++)
	{
		cout << endl;
		swap(&arr[i], &arr[size - i - 1]);
		cout << "arr[" << i << "]와" << "arr[" <<
			size - i - 1 << "]를 교환합니다." << endl;
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
	}
	cout << endl;
	cout << "역순 입력을 종료합니다.";
	

	return 0;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}