#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stdlib.h>

using namespace std;

const int line = 4;
int ct = 0;


void Queen(int n, int now, vector<int> chess[], int min, int mid, int max);
void Print(int n, vector<int> chess[]);

int main()
{
	vector<vector<int>> chess(line, vector<int>(line, 0));
	Queen(line - 1, 0, *chess[], 0, 0, 0);
	cout << ct;
	return 0;
}

void Queen(int n, int now, vector<int> chess[], int min, int mid, int max)
{
	if (n < 0)
	{
		ct++;
		Print(n, chess);
		return;
	}
	
	if (now == min || now == mid || now == max)
		return;

	chess[n][now] == 1;

	for (int i = 0; i < line; i++)
	{
		Queen(n - 1, i, chess, now - 1, now, now + 1);
	}
}

void Print(int n, vector<int> chess[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (chess[i][j] == 1)
				printf("бс");
			else
				printf("бр");
		}
		printf("\n");
	}
}
