#ifndef CONTROLDISPENSADORES_H
#define CONTROLDISPENSADORES_H

#include "Dispensador.h"
#include "Solenoide.h"

/*#include "Bomba.h"*/
class ControlDispensadores
{
private:
    Dispensador sal1;
    Dispensador sal2;
    Dispensador sal3;
    Dispensador acido;
    Dispensador base;

    Notificador notif;
    
public:
    ControlDispensador(Notificador notificador);
    
    void comprobar_Contenido();
    void rellenar(String nombre);
    void dispensar_Sales(float cansal1, float cansal2, float cansal3, Solenoide solsal1, Solenoide solsal2, Solenoide solsal3);
    void dispensar_Acido(float cantidad,);
    void dispensar_Base(float cantidad);
};

#endif
