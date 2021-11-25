#ifndef SENSORTB_H
#define SENSORTB_H

class SensorTB
{
 private:
    ThingsBoard tb0;

 public:
    void actualizar_thingsboard(int turbidez, int ec, int ph, int nivel_reservorio);
    SensorTB()=default;
    SensorTB(ThingsBoard tb1);
};
#endif
