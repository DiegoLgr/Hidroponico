#ifndef _SENSOR_EC
#define _SENSOR_EC


class Sensor_EC
{
private:
    int pin;

public:
    Sensor_EC(int pinEC);
    Sensor_EC() = default;
    float read();
};

#endif
