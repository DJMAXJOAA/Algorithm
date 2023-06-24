#include <iostream>
#include <vector>

using namespace std;

void Sort(vector<int> a, int n);

int main()
{
	int l;	// 도로 전체 길이
	int n;  // 도로에 있는 가로등 갯수
	vector<int> street(0);

	cout << "도로 전체 길이";
	cin >> l;
	cout << "가로등 갯수";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		street.push_back(temp);
	}
	Sort(street, n);

	int max = 0;
	for (int i = n-1; i > 0; i--)
	{
		int temp = street[i] - street[i-1];
		if (temp >= max)
			max = temp;
	}
	cout << "d : ";
	cout << max / 2 + max%2;
	return 0;
}

void Sort(vector<int> a, int n)
{
	int k = 0;
	while (k < n-1)
	{
		int last = n - 1;
		for (int i = n-1; i > k; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				last = i;
			}
		}
		k = last;
	}
}
