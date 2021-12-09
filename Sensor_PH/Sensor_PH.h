#ifndef _SENSOR_PH
#define _SENSOR_PH


class Sensor_PH
{
private:
    int pin;

public:
    Sensor_PH(int pinPH);
    Sensor_PH() = default;
    float read();
};

#endif
