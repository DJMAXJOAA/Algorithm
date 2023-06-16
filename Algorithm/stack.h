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
	int max;	// 최대 용량
	int ptr;	// 현재 용량
	int* stk;	// 첫요소(맨 마지막 저장한 데이터)의 포인터

public:
	/* 스택 초기화 */
	int Initialize(int max);

	/* 스택에 데이터 푸시 - 맨 위에 데이터 추가 */
	int Push(int x);

	/* 스택에 데이터 팝 - 맨 위 데이터 제거 */
	int Pop(int* x);

	/* 스택에 데이터 피크 - 맨 마지막 값 반환 */
	int Peek(int* x);

	/* 스택 데이터 비우기 */
	void Clear();

	/* 용량 */
	int Capacity();

	/* 사이즈 */
	int Size();

	/* 출력 */
	void Print();

	/* 삭제 */
	void Terminate();
};