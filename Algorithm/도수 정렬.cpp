#include <iostream>
#include <vector>
#include "StopWatch.h"

using namespace std;

int main()
{
	StopWatch check;
	int n;
	cin >> n;
	int max = 0;


	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp > max)
			max = temp;
		arr.push_back(temp);
	}
	check.Start();

	for (int x = 0; x < 1000; x++)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;

		vector<int> arr2(max + 1, 0);

		for (int i = 0; i < n; i++)
		{
			arr2[arr[i]]++;
		}
		for (int i = 0; i < arr2.now_size(); i++)
		{
			while (arr2[i] != 0)
			{
				cout << i << " ";
				arr2[i]--;
			}
		}
		cout << endl;
	}
	check.Stop();
	cout << check.getElapsedTime() << "ms";


	return 0;
}