#include <stdio.h>

int med3(int a, int b, int c);

int main()
{
	int a = 3;
	int b = 5;
	int c = 2;

	printf("%d", med3(a, b, c));

	return 0;
}

//int med3(int a, int b, int c)
//{
//	if (c > a)
//	{
//		if (a >= b)
//		{
//			return a;
//		}
//		else if (b > c)
//		{
//			return c;
//		}
//		else
//		{
//			return b;
//		}
//	}
//	else if (b > c)
//	{
//		return a;
//	}
//	else if (a > b)
//	{
//		return c;
//	}
//	else
//	{
//		return b;
//	}
//	return 0;
//}

int med3(int a, int b, int c)
{
	if (a > b && b > c || b > a && c > b)
		return b;
	else if (b >= a && a >= c || a >= b && c >= a)
		return a;
	return c;
}