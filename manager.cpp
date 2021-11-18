#include "app/interfaz.h"
#include "app/cubeta.h"
#include "app/solenoide.h"
#include "app/reservorio.h"
#include "app/sensor_nivel.h"

#include <iostream>




int main(){
    /* -- setUp reservorio -- */
    auto sensor_nivel_bajo = Sensor_nivel(false);
    auto sensor_nivel_alto = Sensor_nivel(true);
    auto solenoide = Solenoide();
    auto cubeta = Cubeta_auxiliar(solenoide);
    auto notificador = Notificador();
    auto reservorio = Reservorio(sensor_nivel_bajo, sensor_nivel_alto, cubeta, notificador);

    /* -- setUp reservorio -- */

    for (int i = 0; i < 20; i++){
        reservorio.tick(10);
    }

    return 0;
}


