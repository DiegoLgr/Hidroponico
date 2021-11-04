#ifndef BUFFER_H
#define BUFFER_H

#include <Bomba.h>

class Buffer
{
private:
    float nivel_agua;
    float valor_max;
    float valor_min;
    Bomba bomba_reservorio;
    
    void falta_agua();
    void sobra_agua():

public:
    Buffer(float valmax, float valmin, Bomba bomba);

    void check(float nivel);
};

#endif
