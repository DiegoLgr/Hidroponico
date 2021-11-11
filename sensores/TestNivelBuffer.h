#ifndef TESTNIVELBUFFER_H
#define TESTNIVELBUFFER_H

class TestNivelBuffer
{
private:
    int pin;
    
public:
    TestNivelBuffer(int pinNivelBuffer);
    int read();
};

#endif
