#include <iostream>

/* ���콺 ��Ģ */
//int main()
//{
//	int n = 10;
//	int result = 0;
//
//	int result = (1 + n) * (n / 2);
//	if (n % 2) result += (1 + n) / 2;
// 
//	printf("%d", result);
//
//	return 0;
//}

/* ���콺 ��Ģ ���� */
int main()
{
	int a = 3;
	int b = 6;
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	int count = a - b + 1;
	int result = (a + b) * (count / 2);
	if (count % 2)
	{
		result += (a + b) / 2;
	}
	
	printf("%d", result);

	return 0;
}