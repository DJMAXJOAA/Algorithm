#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stdlib.h>

class IntStack
{
private:
	int max;	// �ִ� �뷮
	int ptr;	// ���� �뷮
	int* stk;	// ù���(�� ������ ������ ������)�� ������

public:
	/* ���� �ʱ�ȭ */
	int Initialize(int max);

	/* ���ÿ� ������ Ǫ�� - �� ���� ������ �߰� */
	int Push(int x);

	/* ���ÿ� ������ �� - �� �� ������ ���� */
	int Pop(int* x);

	/* ���ÿ� ������ ��ũ - �� ������ �� ��ȯ */
	int Peek(int* x);

	/* ���� ������ ���� */
	void Clear();

	/* �뷮 */
	int Capacity();

	/* ������ */
	int Size();

	/* ��� */
	void Print();

	/* ���� */
	void Terminate();
};