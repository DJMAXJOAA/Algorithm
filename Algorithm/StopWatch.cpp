#include "StopWatch.h"

StopWatch::StopWatch()
{
    start = 0;
    end = 0;
}

StopWatch::~StopWatch()
{
}

void StopWatch::Start()
{
    start = clock();
}

void StopWatch::Stop()
{
    end = clock();
}

clock_t StopWatch::getElapsedTime()
{
    return end - start;
}
