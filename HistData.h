//
// Created by ole on 10.11.15.
//

#ifndef TEST_HISTDATA_H
#define TEST_HISTDATA_H

#include <vector>
#include "Tick.h"

using namespace std;

class HistData
{
    // vector of pointers to Tick objects to save historic data
    vector<Tick*> hist_data;

public:
    // constructor
    HistData();
    // access methods
    size_t GetSize();
    tm* GetTime(size_t index);
    float GetOpen(size_t index);
    float GetHigh(size_t index);
    float GetLow(size_t index);
    float GetClose(size_t index);
};


#endif //TEST_HISTDATA_H
