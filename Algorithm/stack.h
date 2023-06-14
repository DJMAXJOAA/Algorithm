#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stdlib.h>

struct IntStack
{
	int max;	// �ִ� �뷮
	int ptr;	// ���� �뷮
	char* stk;	// ù���(�� ������ ������ ������)�� ������
};

/* ���� �ʱ�ȭ */
int Initialize(IntStack* s, int max);

/* ���ÿ� ������ Ǫ�� - �� ���� ������ �߰� */
int Push(IntStack* s, char x);

/* ���ÿ� ������ �� - �� �� ������ ���� */
int Pop(IntStack* s, char* x);

/* ���ÿ� ������ ��ũ - �� ������ �� ��ȯ */
int Peek(const IntStack* s, char* x);

/* ���� ������ ���� */
void Clear(IntStack* s);

/* ������ */
int Size(const IntStack* s);

/* �뷮 */
int Capacity(const IntStack* s);

/* ���� */
void Terminate(IntStack* s);

void PrintStack(const IntStack* s);

