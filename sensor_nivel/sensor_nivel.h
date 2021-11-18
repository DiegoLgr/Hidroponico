#ifndef _SENSOR_NIVEL
#define _SENSOR_NIVEL


class Sensor_nivel
{
private:
    int pin;

public:
    Sensor_nivel(int pinNivel);
    Sensor_nivel() = default;
    int read();
};

#endif
