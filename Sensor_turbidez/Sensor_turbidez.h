#ifndef _SENSOR_TURBIDEZ
#define _SENSOR_TURBIDEZ


class Sensor_turbidez
{
private:
    int pin;

public:
    Sensor_turbidez(int pinTurbidez);
    Sensor_turbidez() = default;
    float read();
};

#endif
