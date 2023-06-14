#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stdlib.h>

class IntQueue
{
public:
	/* ť �ʱ�ȭ */
	IntQueue(int max);
	/* ť ���� */
	~IntQueue();

	/* ť�� �����͸� ��ť */
	int Enque(char x);

	/* ť���� �����͸� ��ť */
	int Deque(char* x);

	/* ť���� �����͸� ��ũ */
	int Peek(char* x);

	/* ��� ������ ���� */
	void Clear();

	/* ť�� �ִ� �뷮 */
	int Capacity() const;

	/* ť�� ����� ������ ���� */
	int Size() const;

	/* ��� ������ ��� */
	void Print() const;

private:
	int max;	// que�� �뷮
	int num;	// que�� ���� ������ ��
	int front;
	int rear;
	char* que;	// que�� �� �� ���
};
