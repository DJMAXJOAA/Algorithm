#include "stack.h"

using namespace std;

int Initialize(IntStack* s, int max)
{
    s->max = max;
    char* stack = new char[max];
    s->stk = stack;
    s->ptr = 0;

    return 0;
}

int Push(IntStack* s, char x)
{
    if (s->max <= s->ptr)
    {
        cout << "������ ���� á���ϴ�." << endl;
        return 0;
    }
    
    s->stk[s->ptr] = x;
    s->ptr++;
    return 1;
}

int Pop(IntStack* s, char* x)
{
    if (s->ptr == 0)
    {
        cout << "������ ����ֽ��ϴ�." << endl;
        return 0;
    }
    *x = s->stk[s->ptr - 1];
    s->ptr--;
    
    return 1;
}

int Peek(const IntStack* s, char* x)
{
    if (s->ptr == 0)
    {
        cout << "������ ����ֽ��ϴ�." << endl;
        return 0;
    }
    *x = s->stk[s->ptr - 1];

    return 1;
}

void Clear(IntStack* s)
{
    s->ptr = 0;
    cout << "������ ������ϴ�." << endl;
}

int Size(const IntStack* s)
{
    return s->ptr;
}

int Capacity(const IntStack* s)
{
    return s->max;
}

void Terminate(IntStack* s)
{
    if (s->stk != NULL)
    {
        delete[] s->stk;
    }
    s->max = 0;
    s->ptr = 0;
}

void PrintStack(const IntStack* s)
{
    for (int i = 0; i < s->ptr; i++)
    {
        cout << s->stk[i];
    }
    printf("\n");
}