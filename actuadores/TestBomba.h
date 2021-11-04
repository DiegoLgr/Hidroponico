#ifndef TESTBOMBA_H
#define TESTBOMBA_H

#include <Bomba.h>

class Buffer
{
private:
    float actTime;
    float timeLeft;
    int estado;

public:
    void act();
    void tick(float timePassed);
};

#endif
