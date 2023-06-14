#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stdlib.h>

struct IntStack
{
	int max;	// 최대 용량
	int ptr;	// 현재 용량
	char* stk;	// 첫요소(맨 마지막 저장한 데이터)의 포인터
};

/* 스택 초기화 */
int Initialize(IntStack* s, int max);

/* 스택에 데이터 푸시 - 맨 위에 데이터 추가 */
int Push(IntStack* s, char x);

/* 스택에 데이터 팝 - 맨 위 데이터 제거 */
int Pop(IntStack* s, char* x);

/* 스택에 데이터 피크 - 맨 마지막 값 반환 */
int Peek(const IntStack* s, char* x);

/* 스택 데이터 비우기 */
void Clear(IntStack* s);

/* 사이즈 */
int Size(const IntStack* s);

/* 용량 */
int Capacity(const IntStack* s);

/* 삭제 */
void Terminate(IntStack* s);

void PrintStack(const IntStack* s);

