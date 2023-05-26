#include <stdio.h>

int max4(int a, int b, int c, int d);

int main()
{
	int a = 9;
	int b = 3;
	int c = 5;
	int d = 2;

	printf("%d", max4(a,b,c,d));
	return 0;
}

int max4(int a, int b, int c, int d)
{
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;
	return max;
}