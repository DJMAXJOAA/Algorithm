#include <iostream>
#include <vector>

using namespace std;

const int x = 5;

void setvect(vector<vector<int>> &a);
void setvect2(vector<vector<int>> &a);

int main()
{
	vector<vector<int>> a(x, vector<int>(x, 0));
	setvect(a);
	cout << a[3][3];
	return 0;
}

void setvect(vector<vector<int>> &a)
{
	a[3][3] = 3;
	setvect2(a);
}

void setvect2(vector<vector<int>> &a)
{
	a[3][3] = 4;
}