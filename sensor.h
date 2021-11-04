#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
  private:
    int temperatura;
    int EC;
    int PH;
    int nivel_reservorio;

  public:
    void set_temperatura(int temperatura);
    void set_EC(int ec);
    void set_nivel_reservorio(int nivel_reservorio);
    void set_PH(int ph);
    void actualizar_thingsboard(int temperatura, int ec, int ph, int nivel_reservorio);
};
#endif
