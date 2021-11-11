#ifndef TESTBOMBA_H
#define TESTBOMBA_H

class TestBomba
{
private:
    int actTime;
    int timeLeft;
    int estado;

public:
    void act();
    void tick(int timePassed);
    TestBomba(int actTimeBomba);
    TestBomba() = default;
};

#endif
