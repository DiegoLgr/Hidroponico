#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
 private:
    int temperatura0;
    int ec0;
    int ph0;
    int nivel_reservorio0;
    ThingsBoard tb0;

public:
    void set_temperatura(int temperatura);
    void set_EC(int ec);
    void set_nivel_reservorio(int nivel_reservorio);
    void set_PH(int ph);
    void actualizar_thingsboard(int temperatura, int ec, int ph, int nivel_reservorio);
    Sensor()=default;
 Sensor(int temperatura1, int ec1, int ph1, int nivel_reservorio1, ThingsBoard tb1);
 
};
#endif
