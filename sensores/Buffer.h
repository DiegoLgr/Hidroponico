 #ifndef BUFFER_H
#define BUFFER_H

#include "TestBomba.h"
/*#include "Bomba.h"*/
class Buffer
{
private:

    TestBomba bomba_reservorio;
    /*Bomba bomba_reservorio;*/
    
    void falta_agua();

public:
    Buffer(TestBomba bomba);

    void check(int nivel);
};

#endif
