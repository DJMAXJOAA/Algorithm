#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string str = { "abababadababacabad" };
	string pattern = { "ababacaba" };
	vector<int> movement(pattern.now_size(), 0);

	for (int i = 0; i < pattern.now_size(); i++)
	{
		if (pattern[0] == pattern[i])
		{
		}
	}

	return 0;
}