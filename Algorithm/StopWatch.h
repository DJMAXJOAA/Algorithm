#pragma once
#include <iostream>
#include <string>
#include <time.h>

class StopWatch
{
private:
	clock_t start;
	clock_t end;
public:
	StopWatch();
	~StopWatch();

	void Start();
	void Stop();
	clock_t getElapsedTime();
};
