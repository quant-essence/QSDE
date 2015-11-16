/*
 * class that holds single bar data
 * */

// implementation of struct/class goes into source file
#include <iostream>
#include "Tick.h"

using namespace std;

// constructor
Tick::Tick(tm time, float open, float high, float low, float close)
{
    this->time = time;
    this->open = open;
    this->high = high;
    this->low  = low;
    this->close = close;
}

tm* Tick::GetTime()
{
    //return this->time;
    return &time;
}

float Tick::GetOpen()
{
    return this->open;
}

float Tick::GetHigh()
{
    return this->high;
}

float Tick::GetLow()
{
    return this->low;
}

float Tick::GetClose()
{
    return this->close;
}