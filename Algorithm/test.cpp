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
	cout << "bsearch 함수를 사용하여 검색" << endl;
	cout << "요소 개수 : ";
	cin >> nx;
	int* x = new int[nx];

	cout << "오름차순으로 입력하세요. \n";
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
	cout << "검색값 : ";
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
		cout << "검색에 실패했습니다." << endl;
	}
	else
	{
		printf("%d는 x[%d]에 있습니다.\n", ky, (int)(p - x));
	}

	delete[] x;
	return 0;
}