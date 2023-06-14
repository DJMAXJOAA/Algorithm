#include "queue.h"

IntQueue::IntQueue(int max)
{
	this->max = max;
	char* QUE = new char[max];
	que = QUE;
	num = 0;
	front = 0;
	rear = 0;
}

IntQueue::~IntQueue()
{
	delete[] que;
	que = nullptr;
}

int IntQueue::Enque(char x)
{
	if (num >= max)
	{
		return 0;
	}
	if (num == 0)
	{
		que[0] = x;
		front = 0;
		rear = 0;
		num++;
		return 1;
	}
	num++;
	if (rear == max)
	{
		rear = 0;
	}
	else
	{
		rear++;
	}
	que[rear] = x;

	return 1;
}

int IntQueue::Deque(char* x)
{
	if (num == 0)
	{
		return 0;
	}
	num--;
	*x = que[front];
	que[front] = 0;
	if (front == max)
	{
		front = 0;
	}
	front++;

	return 1;
}

int IntQueue::Peek(char* x)
{
	if (num == 0)
	{
		return 0;
	}
	*x = que[front];

	return 1;
}

void IntQueue::Clear()
{
	num = 0;
	front = 0;
	rear = 0;
}

int IntQueue::Capacity() const
{
	return max;
}

int IntQueue::Size() const
{
	return num;
}


void IntQueue::Print() const
{
	for (int i = 0; i < num; i++)
	{
		std::cout << que[(i + front) % max];
	}
	std::cout << std::endl;
}