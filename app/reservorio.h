#ifndef _RESERVORIO
#define _RESERVORIO


#include "cubeta.h"
#include "reservorio.h"
#include "solenoide.h"
#include "interfaz.h"
#include "sensor_nivel.h"

enum Estados { BASE, RELLENANDO };
class Reservorio {
    private:
        Estados estado;
        Cubeta_auxiliar cubeta;
        Notificador notificador;
	Sensor_nivel sensor_nivel_alto;
	Sensor_nivel sensor_nivel_bajo;
	bool nivel_alto;
	bool nivel_bajo;

        void check_nivel(void);

    public:
        Reservorio(void);
        Reservorio(Sensor_nivel sensor_nivel_bajo, Sensor_nivel sensor_nivel_alto, Cubeta_auxiliar cubeta, Notificador notificador);
        void tick(int ms);
};
#endif
