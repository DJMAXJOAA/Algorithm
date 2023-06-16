#include <iostream>
#include <vector>

using namespace std;
int n = 4;
int select = n;

int hanoi(int n, int start, int end, vector<int> s[]);
void print(int select, vector<int> s[]);

int main()
{
	vector<int> s[3];
	for (int i = n; i > 0; i--)
	{
		s[0].push_back(i);
	}
	
	hanoi(n, 0, 2, s);
	for (int i = 0; i < s[0].size(); i++)
	{
		cout << s[0][i];
	}

	return 0;
}

int hanoi(int n, int start, int end, vector<int> s[])
{
	int sub = 3 - start - end;

	if (n == 0)
	{
		return 0;
	}
	hanoi(n - 1, start, sub, s);
	s[end].push_back(s[start].back());
	s[start].pop_back();
	print(select, s);
	hanoi(n - 1, sub, end, s);
}

void print(int select, vector<int> s[])
{
	for (int i = n - 1; i >= 0; i--)
	{
		cout << "[ ";
		if (s[0].size() > i) cout << s[0][i];
		else cout << " ";
		cout << " ] [ ";
		if (s[1].size() > i) cout << s[1][i];
		else cout << " ";
		cout << " ] [ ";
		if (s[2].size() > i) cout << s[2][i];
		else cout << " ";
		cout << " ]";

		cout << endl;
	}
	cout << endl;
}