#include <iostream>

#include "app/cubeta.h"
#include "app/buffer.h"
#include "app/reservorio.h"
#include "sensores/sensor_nivel.h"
#include "actuadores/bomba.h"
#include "notificador/notificador.h"

#define ALTO true
#define BAJO false



int main(){
    Cubeta cubeta { Bomba{1} };
    Buffer buffer { Bomba{2}, Sensor_nivel {BAJO}, Sensor_nivel {ALTO} };
    Reservorio reservorio {
            cubeta, Sensor_nivel{BAJO}, Sensor_nivel{ALTO}, Notificador{} };

    for (int i = 0; i < 20; i++){
        buffer.tick(10);
        reservorio.tick(10);
    }
    return 0;
}


