// declaration of struct/class goes into header file
#ifndef QSDE_TICK_H
#define QSDE_TICK_H

// only difference between struct & class is that in a class all members are private by default
class Tick
{
    // attributes
    tm time;
    float open, high, low, close;

public:
    // constructor
    Tick(tm time, float open, float high, float low, float close);

    // Methods
    tm* GetTime();
    float GetOpen();
    float GetHigh();
    float GetLow();
    float GetClose();
};

#endif //QSDE_TICK_H