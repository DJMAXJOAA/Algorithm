#pragma once
#include <iostream>

class Bubble_Sort
{
private:
	int* array;
	bool* pass;
	int size;
	int swap_num;
	int compare_num;
public:
	Bubble_Sort();
	Bubble_Sort(int size);
	~Bubble_Sort();
	void Print();
	void Sort1();
	void Sort2();
	void Sort3();
	void Swap(int *a, int *b);
	void Num_Print();
};

inline Bubble_Sort::Bubble_Sort()
	:swap_num(0), compare_num(0), size(7)
{
	int temp[7] = { 1,3,9,4,8,8,6 };
	array = new int[size];
	pass = new bool[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = temp[i];
		pass[i] = false;
	}
	
}

Bubble_Sort::Bubble_Sort(int size)
	: swap_num(0), compare_num(0)
{
	int temp;
	this->size = size;
	array = new int[size];
	pass = new bool[size];
	std::cout << "배열 값 입력";
	for (int i = 0; i < size; i++)
	{
		std::cin >> temp;
		array[i] = temp;
		pass[i] = false;
	}
}

Bubble_Sort::~Bubble_Sort()
{
	delete[] array;
}

inline void Bubble_Sort::Print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "\n";
}

// 버전1
inline void Bubble_Sort::Sort1()
{
	//std::cout << "버전1 : \n";
	for (int i = 0; i < size-1; i++)
	{
		//std::cout << i+1 << "번째\n";
		for (int j = size-1; j > i; j--)
		{
			Print();
			compare_num++;
			if (array[j] < array[j - 1])
			{
				swap_num++;
				Swap(&array[j], &array[j - 1]);
			}
		}
	}
}

inline void Bubble_Sort::Sort2()
{
	/*std::cout << "버전2 : \n";*/
	for (int i = 0; i < size - 1; i++)
	{
		int temp = size-1-i;
		//std::cout << i + 1 << "번째\n";
		for (int j = size - 1; j > i; j--)
		{
			Print();
			
			compare_num++;
			if (array[j] < array[j - 1])
			{
				swap_num++;
				Swap(&array[j], &array[j - 1]);
			}
			else
				temp--;
		}
		if (temp == 0)
			break;
	}
}

inline void Bubble_Sort::Sort3()
{
	/*std::cout << "버전3 : \n";*/
	int i;
	for (i = 0; i < size - 1; i++)
	{
		int temp = size - 1 - i;
		/*std::cout << i + 1 << "번째\n";*/
		for (int j = size - 1; j > i; j--)
		{
			Print();

			compare_num++;
			if (array[j] < array[j - 1])
			{
				swap_num++;
				Swap(&array[j], &array[j - 1]);
			}
			else
				temp--;
		}
		for (int x = i; x < size-1; x++)
		{
			if (array[x] > array[x + 1])
			{
				i--;
				break;
			}
			i++;
		}
		if (temp == 0)
			break;
	}
}

inline void Bubble_Sort::Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

inline void Bubble_Sort::Num_Print()
{
	std::cout << "비교 횟수 : " << compare_num << "\n";
	std::cout << "교환 횟수 : " << swap_num << "\n\n";
}
