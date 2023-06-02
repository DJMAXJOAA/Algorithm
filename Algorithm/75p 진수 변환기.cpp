#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void converse_cardinal(char save1[], int x, int range);
void cardinal_converse(char save1[], char save2[], int range, int range2);
void reverse(char str[]);

int main()
{
	char save1[100] = { 0 };
	char save2[100] = { 0 };
	int x = 2590;
	int decimal = 16;
	int decimal2 = 2;

	cout << "10진수 입력 : ";
	cin >> x;

	cout << "첫번째로 몇진수로 변환? : ";
	cin >> decimal;

	cout << decimal << "진수를 몇진수로 변환? : ";
	cin >> decimal2;

	converse_cardinal(save1, x, decimal);

	cout << save1 << endl;

	cardinal_converse(save1, save2,  decimal, decimal2);

	cout << save2 << endl;

	return 0;
}

void converse_cardinal(char save1[], int x, int decimal)
{
	if (x % decimal > 9)	// 10진수 이상
	{
		save1[0] = x % decimal + 55;
	}
	else if (x % decimal > 0 && x % decimal <= 9)
	{
		save1[0] = x % decimal + 48;
	}
	else save1[0] = 48;
	x /= decimal;

	int count = 1;

	while (x/decimal)
	{
		if (x % decimal > 0)
		{
			if (x % decimal > 9)
			{
				save1[count] = x % decimal + 55;
			}
			else
			{
				save1[count] = x % decimal + 48;
			}
		}
		else save1[count] = 48;
		x /= decimal;
		count++;
	}
	count++;
	if (x % decimal > 9)
	{
		save1[count] = x % decimal + 55;
	}
	else
	{
		save1[count] = x % decimal + 48;
	}
	reverse(save1);
}


void cardinal_converse(char save1[], char save2[], int decimal, int decimal2)
{
	int x = 0;
	int square = decimal;	// 제곱

	reverse(save1);
	if (*save1 >= '0' && *save1 <= '9')
	{
		x = *save1 - 48;
	}
	else if (*save1 >= 'A')
	{
		x = *save1 - 55;
	}
	save1++;

	while (*save1)
	{
		if (*save1 >= '0' && *save1 < '9')
		{
			x += (*save1 - 48) * square;
		}
		else if (*save1 >= 'A')
		{
			x += (*save1 - 55) * square;
		}

		save1++;
		square *= square;
	}

	converse_cardinal(save2, x, decimal2);
	
}

void reverse(char str[])
{
	char temp[100];
	for (int i = 0; i < strlen(str)/2; i++)
	{
		temp[i] = str[i];
		str[i] = str[strlen(str) - i - 1];
		str[strlen(str) - i - 1] = temp[i];
	}
}