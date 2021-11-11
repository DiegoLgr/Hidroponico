#ifndef _RESERVORIO
#define _RESERVORIO


#include "cubeta.h"
#include "reservorio.h"
#include "solenoide.h"
#include "interfaz.h"
#include "sensor_nivel.h"

class Reservorio {
    private:
        enum Estados { base, rellenando };
        Estados estado;
        Cubeta_auxiliar cubeta;
        Interfaz notificador;
	Sensor_nivel sensor_nivel_alto;
	Sensor_nivel sensor_nivel_bajo;

        void check_nivel(void);

    public:
        Reservorio();
        Reservorio(Sensor_nivel sensor_nivel_bajo, Sensor_nivel sensor_nivel_alto, Cubeta_auxiliar cubeta, Interfaz notificador);
        void tick(int ms);
};
#endif
