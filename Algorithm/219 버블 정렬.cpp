#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "bubble_sort.h"
#include "StopWatch.h"

using namespace std;

int main()
{
	{
		StopWatch check;
		check.Start();
		for (int i = 0; i < 1000; i++)
		{
			Bubble_Sort n;
			n.Sort2();
		}
		check.Stop();
		cout << "sort2 1000번 : 걸린 시간 : " << check.getElapsedTime() << "ms\n\n";
	}
	return 0;
}