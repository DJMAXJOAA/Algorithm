#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

void primal1(int now_size, int count);
void primal2(int now_size, int count);
void primal3(int now_size, int count);
void primal4(int now_size, int count);

int primal[1000] = { 0 };

int main()
{
	int now_size = 1000;
	int count = 0;
	
	primal1(now_size, count);
	primal2(now_size, count);
	primal3(now_size, count);
	primal4(now_size, count);

	return 0;
}

void primal1(int now_size, int count)
{
	for (int i = 2; i <= now_size; i++)
	{
		int j = 2;
		for (j = 2; j < i; j++)
		{
			count++;
			if (i % j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			cout << i << " ";
		}
	}
	cout << endl;
	cout << "ÃÑ ³ª´°¼À È½¼ö : " << count << endl;
}

void primal2(int now_size, int count)
{
	for (int i = 3; i <= now_size; i += 2)
	{
		int j = 3;
		for (j = 3; j < i; j += 2)
		{
			count++;
			if (i % j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			for (int k = 0; k < sizeof(primal)/sizeof(primal[0]); k++)
			{	// ¼Ò¼ö ¹è¿­¿¡ ³Ö¾îµÎ±â
				if (primal[k] == 0)
				{
					primal[k] = i;
					break;
				}				
			}
			/*cout << i << " ";*/
		}
	}
	cout << "ÃÑ ³ª´°¼À È½¼ö : " << count << endl;
}

void primal3(int now_size, int count)
{
	for (int i = 3; i <= now_size; i+=2)
	{
		int j = 0;
		for (j = 0; j <= sizeof(primal) / sizeof(primal[0]); j++)
		{
			if (primal[j] >= i)
			{
				break;
			}
			count++;
			if (i % primal[j] == 0)
			{
				break;
			}
		}
		if (primal[j] >= i)
		{
			/*cout << i << " ";*/
		}
	}
	cout << "ÃÑ ³ª´°¼À È½¼ö : " << count << endl;
}

void primal4(int now_size, int count)
{
	double primal_range = sqrt(now_size);
	for (int i = 3; i <= now_size; i += 2)
	{
		int j = 0;
		for (j = 0; j <= sizeof(primal) / sizeof(primal[0]); j++)
		{
			if (primal[j] >= i || primal[j] >= primal_range)
			{
				break;
			}
			count++;
			if (i % primal[j] == 0)
			{
				break;
			}
		}
		if (primal[j] >= i || primal[j] >= primal_range)
		{
			/*cout << i << " ";*/
		}
	}
	cout << "ÃÑ ³ª´°¼À È½¼ö : " << count << endl;
}