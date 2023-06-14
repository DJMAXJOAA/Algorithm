#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stdlib.h>

using namespace std;

void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*));
int int_cmp(const int* a, const int* b);
int linear_search(const int range, const int* arr);

int main()
{
	int search, arr_size;
	cout << "��� ���� : ";
	cin >> arr_size;
	int* arr = new int[arr_size];

	cout << "������������ �Է��ϼ���.\n";
	cout << "arr[0] : ";
	cin >> arr[0];
	for (int i = 1; i < arr_size; i++)
	{
		do
		{
			printf("arr[%d] : ", i);
			cin >> arr[i];
		} while (arr[i] < arr[i - 1]);
	}
	cout << "�˻��� : ";
	cin >> search;

	int* p1 = (int*)bsearchx(
		&search,
		arr,
		arr_size,
		sizeof(int),
		(int(*)(const void*, const void*))int_cmp
	);

	if (p1 == NULL)
	{
		cout << "�˻��� �����߽��ϴ�." << endl;
	}
	else
	{
		printf("%d�� x[%d]�� �ֽ��ϴ�.\n", search, (int)(p1 - arr));
	}

	int p2 = linear_search((int)(p1 - arr), arr);

	if (p2 == -1)
	{
		cout << "�˻��� �����߽��ϴ�." << endl;
	}
	else
	{
		printf("���� �� %d�� x[%d]�� �ֽ��ϴ�.\n", search, p2);
	}

	delete[] arr;
	return 0;
}

void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*))
{
	char* parr = (char*)base;
	size_t first = 0;
	size_t last = nmemb - 1;
	size_t mid;
	int result;
	do
	{
		mid = (first + last) / 2;
		result = compar(&parr[mid*size], key);
		if (result == 1)
		{
			last = mid;
		}
		else if (result == -1)
		{
			first = mid;
		}
	} while (result != 0);

	return &parr[mid*size];
}

int int_cmp(const int* a, const int* b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}

int linear_search(const int range, const int* arr)
{
	for (int i = range; i > 0; i--)
	{
		if (arr[i] != arr[i - 1])
			return i;
	}
	return -1;
}