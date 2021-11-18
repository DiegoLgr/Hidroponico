#ifndef DISPENSADOR_H
#define DISPENSADOR_H

/*#include "Bomba.h"*/
class Dispensador
{
private:
    float cantidad_queda;
    
public:
    Dispensador();
    
    void dispensar(float cantidad);
    void rellenar();
    float mostrar_contenido();
};

#endif
