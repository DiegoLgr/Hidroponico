#ifndef _RESERVORIO
#define _RESERVORIO


#include "cubeta.h"
#include "solenoide.h"
#include "notificador.h"
#include "sensor_nivel.h"

class Reservorio {
    enum Estados { BASE, RELLENANDO };
    private:
        Estados estado;
        Cubeta cubeta;
        Notificador notificador;
        Sensor_nivel sensor_nivel_alto;
        Sensor_nivel sensor_nivel_bajo;
        bool nivel_alto;
        bool nivel_bajo;

        void check_nivel(void);

    public:
        Reservorio(Cubeta cubeta, Sensor_nivel sensor_nivel_bajo, Sensor_nivel sensor_nivel_alto, Notificador notificador);
        void tick(int ms);
};
#endif
