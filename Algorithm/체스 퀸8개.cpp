#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stdlib.h>

using namespace std;

const int line = 8;	// ¸î°ö¸î?
int ct = 0;

void Queen(int n, int save, vector<vector<int>> chess);
void LeftLine(int n, int position, vector<vector<int>>&chess, int fill_or_not);
void MidLine(int n, int position, vector<vector<int>>&chess, int fill_or_not);
void RightLine(int n, int position, vector<vector<int>>&chess, int fill_or_not);
void Print(vector<vector<int>>chess);

int main()
{
	vector<vector<int>> chess(line, vector<int>(line, 0));
	
 	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < i; j++)
		{
			chess[0][j] = 0;
		}
		chess[0][i] = 2;
		Queen(1, i, chess);
		cout << i+1 << "¹øÂ°" << endl;
	}
	cout << ct;
	return 0;
}

void Queen(int n, int save, vector<vector<int>> chess)
{
	if (n == line)
	{
		ct++;
		Print(chess);
		return;
	}
	LeftLine(n, save, chess, 1);
	MidLine(n, save, chess, 1);
	RightLine(n, save, chess, 1);

	int j;

	for (j = 0; j < line; j++)
	{
		if (chess[n][j] == 1)
		{
			continue;
		}

		for (int i = 0; i < j; i++)
		{
			chess[n][i] = 1;
		}
		chess[n][j] = 2;
		Queen(n + 1, j, chess);
	}
	LeftLine(n, save, chess, 0);
	MidLine(n, save, chess, 0);
	RightLine(n, save, chess, 0);
	return;
	
}

void LeftLine(int n, int position, vector<vector<int>>& chess, int fill_or_not)
{
	int x = 1;
	for (int i = n; i < line; i++)
	{
		if (position - x < 0)
			break;
		chess[i][position - x] = fill_or_not;
		x++;
	}
}

void MidLine(int n, int position, vector<vector<int>>& chess, int fill_or_not)
{
	for (int i = n; i < line; i++)
	{
		chess[i][position] = fill_or_not;
	}
}

void RightLine(int n, int position, vector<vector<int>>& chess, int fill_or_not)
{
	int x = 1;
	for (int i = n; i < line; i++)
	{
		if (position + x >= line)
			break;
		chess[i][position + x] = fill_or_not;
		x++;
	}
}

void Print(vector<vector<int>> chess)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < line; j++)
		{
			if (chess[i][j] == 2)
				printf("¡Ù");
			else if (chess[i][j] == 1)
				printf("¡á");
			else
				printf("¡à");
		}
		printf("\n");
	}
	printf("\n");
}
