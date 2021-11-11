/*
#include "reservorio.h"
*/
#include "interfaz.h"
#include "cubeta.h"
#include "solenoide.h"
#include "sensor_nivel.h"

#include <iostream>


int main(){
    auto sensor_nivel_bajo = Sensor_nivel(false);
    auto sensor_nivel_alto = Sensor_nivel(true);
    auto solenoide = Solenoide();
    auto cubeta = Cubeta_auxiliar(solenoide);
    auto notificador = Interfaz();

    //auto reservorio = Reservorio(sensor_nivel_bajo, sensor_nivel_alto, cubeta, notificador);

    return 0;
}


