#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void swap(int *a, int *b);

int main()
{
	const int now_size = 6;
	int arr[now_size];

	for (int i = 0; i < now_size; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < now_size/2; i++)
	{
		cout << endl;
		swap(&arr[i], &arr[now_size - i - 1]);
		cout << "arr[" << i << "]��" << "arr[" <<
			now_size - i - 1 << "]�� ��ȯ�մϴ�." << endl;
		for (int i = 0; i < now_size; i++)
		{
			cout << arr[i] << " ";
		}
	}
	cout << endl;
	cout << "���� �Է��� �����մϴ�.";
	

	return 0;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}