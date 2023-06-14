#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stdlib.h>

using namespace std;

int int_cmp(const int* a, const int* b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}

int main()
{
	int nx, ky;
	cout << "bsearch �Լ��� ����Ͽ� �˻�" << endl;
	cout << "��� ���� : ";
	cin >> nx;
	int* x = new int[nx];

	cout << "������������ �Է��ϼ���. \n";
	cout << "x[0] : ";
	cin >> x[0];
	for (int i = 1; i < nx; i++)
	{
		do
		{
			cout << "x[i] : ";
			cin >> x[i];
		} while (x[i] < x[i-1]);
	}
	cout << "�˻��� : ";
	cin >> ky;

	int* p = (int*)bsearch(
		&ky,
		x,
		nx,
		sizeof(int),
		(int(*)(const void*, const void*)) int_cmp
	);

	if (p == NULL)
	{
		cout << "�˻��� �����߽��ϴ�." << endl;
	}
	else
	{
		printf("%d�� x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));
	}

	delete[] x;
	return 0;
}