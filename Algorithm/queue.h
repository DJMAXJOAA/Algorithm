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
	/* 큐 초기화 */
	IntQueue(int max);
	/* 큐 종료 */
	~IntQueue();

	/* 큐에 데이터를 인큐 */
	int Enque(char x);

	/* 큐에서 데이터를 디큐 */
	int Deque(char* x);

	/* 큐에서 데이터를 피크 */
	int Peek(char* x);

	/* 모든 데이터 삭제 */
	void Clear();

	/* 큐의 최대 용량 */
	int Capacity() const;

	/* 큐에 저장된 데이터 개수 */
	int Size() const;

	/* 모든 데이터 출력 */
	void Print() const;

private:
	int max;	// que의 용량
	int num;	// que의 현재 데이터 수
	int front;
	int rear;
	char* que;	// que의 맨 앞 요소
};
