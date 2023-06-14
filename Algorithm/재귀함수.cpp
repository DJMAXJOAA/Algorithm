#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stdlib.h>

using namespace std;

void reverseDisplay(int value);
void reverseDisplay(const string& s);

int x = 0;

int main()
{
	reverseDisplay(12345);
	cout << endl;
	reverseDisplay("abcd");

	return 0;
}

void reverseDisplay(int value)
{
	cout << value % 10;
	if (value / 10 == 0)
		return;
	reverseDisplay(value / 10);
}

void reverseDisplay(const string& s)
{
	x++;
	cout << s[s.size()-x];
	if (x == s.size())
		return;
	reverseDisplay(s);
}
