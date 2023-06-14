#include "stack.h"

using namespace std;

int Initialize(IntStack* s, int max)
{
    s->max = max;
    int* stack = new int[max];
    s->stk = stack;
    s->ptr = 0;

    return 0;
}

int Push(IntStack* s, int x)
{
    if (s->max <= s->ptr)
    {
        cout << "스택이 가득 찼습니다." << endl;
        return 0;
    }
    
    *s->stk = x;
    s->stk++;

    s->ptr += 1;
    return 1;
}

int Pop(IntStack* s, int* x)
{
    if (s->ptr == 0)
    {
        cout << "스택이 비어있습니다." << endl;
        return 0;
    }
    x = s->stk;
    s->stk--;
    s->ptr--;
    
    return 1;
}

int Peek(const IntStack* s, int* x)
{
    if (s->ptr == 0)
    {
        cout << "스택이 비어있습니다." << endl;
        return 0;
    }
    x = s->stk;

    return 1;
}

void Clear(IntStack* s)
{
    s->ptr = 0;
    s->stk = 0;
    cout << "스택을 비웠습니다." << endl;
}

int Search(const IntStack* s, int x)
{
    int* temp = s->stk;
    for (int i = 0; i < s->ptr; i++)
    {
        if (*(temp - i - 1) == x)
        {
            cout << (s->ptr-i) << "번째 검색 완료" << endl;
            return 1;
        }
    }
    cout << "검색 값이 없습니다." << endl;
    return 0;
}

void Print(const IntStack* s)
{
    int* temp = s->stk;
    for (int i = s->ptr; i>0; i--)
    {
        /*cout << s->stk[i] << endl;*/
        printf("%d ", *(temp - i) );
    }
    cout << "출력 완료" << endl;
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
