#ifndef BUFFER_H
#define BUFFER_H

#include "../actuadores/bomba.h"
#include "../sensores/sensor_nivel.h"




class Buffer {
    enum Estados { BASE, RELLENANDO };
    private:
        Estados estado;
        bool nivel_bajo;
        bool nivel_alto;
        Bomba bomba;
        Sensor_nivel sensor_nivel_bajo;
        Sensor_nivel sensor_nivel_alto;

        void falta_agua();
        void check_nivel();

    public:
        Buffer(Bomba bomba, Sensor_nivel sensor_nivel_bajo, Sensor_nivel Sensor_nivel_alto);
        void tick(int nivel);
};

#endif
