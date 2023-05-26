#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	string str;
	cin >> str;
	string str1;
	string str2;
	string str3;

	int max = 0;

	cout << str.front() << endl;

	for (int i = 1; i < str.size()-2; i++)
	{
		if (str[i] <= str.front())
		{
			max = i;
		}
	}

	str1 = str.substr(0, max);
	str = str.substr(max);

	for (int i = 1; i < str.size() - 1; i++)
	{
		if (str[i] <= str.front())
		{
			max = i;
		}
	}

	str2 = str.substr(0, max);
	str3 = str.substr(max);

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	reverse(str3.begin(), str3.end());

	str = str1 + str2 + str3;

	cout << str << endl;
	return 0;
}