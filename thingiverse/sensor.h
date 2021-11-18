#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
 private:
    float temperatura0;
    float ec0;
    int ph0;
    float nivel_reservorio0;
    ThingsBoard tb0;

public:
    void set_temperatura(float temperatura);
    void set_EC(float ec);
    void set_nivel_reservorio(float nivel_reservorio);
    void set_PH(int ph);
    void actualizar_thingsboard(float temperatura, float ec, int ph, float nivel_reservorio);
    Sensor()=default;
 Sensor(float temperatura1, float ec1, int ph1, float nivel_reservorio1, ThingsBoard tb1);
 
};
#endif
