#include "stack.h"
int IntStack::Initialize(int max)
{
	IntStack::max = max;
	stk = new(std::nothrow) int[max];
	ptr = 0;

	if (stk == NULL)
		return -1;
	else
		return 0;
}

int IntStack::Push(int x)
{
	/*if (ptr < max)
	{
		ptr++;
		stk = new int[ptr];
		stk[ptr] = x;
		return 0;
	}
	else
		return -1;*/

	if (ptr < max)
	{
		ptr++;
		stk[ptr - 1] = x;
		return 0;
	}
	else
		return -1;

}

int IntStack::Pop(int* x)
{
	/*if (ptr > 0)
	{
		ptr--;
		int* temp = new int[ptr];
		for (int i = 0; i < ptr; i++)
		{
			temp[i] = stk[i];
		}

		delete[] stk;
		stk = temp;

	}*/

	if (ptr > 0)
	{
		stk[ptr - 1] = -1;
		ptr--;

	}
	return 0;
}

int IntStack::Peek(int* x)
{
	if (ptr > 0)
	{
		*x = stk[ptr - 1];
		return 0;
	}
	else
		return -1;
}

void IntStack::Clear()
{
	for (int i = 0; i < ptr; i++)
	{
		stk[ptr - 1] = -1;
	}
	ptr = 0;
}

int IntStack::Capacity()
{
	return max;
}

int IntStack::Size()
{
	return ptr;
}

void IntStack::Print()
{
	for (int i = 0; i < ptr; i++)
	{
		std::cout << stk[i] << " ";
	}
}

void IntStack::Terminate()
{
	delete[] stk;
	stk = nullptr;
}