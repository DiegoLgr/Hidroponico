#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
  public Sensor(int temperatura, int ec, int ph, int nivel_reservorio)
  {
    Temperatura=temperatura;
    Ec=ec;
    Ph=ph;
    Nivel_reservorio=nivel_reservorio;
  }
  
  private:
    int temperatura;
    int ec;
    int ph;
    int nivel_reservorio;

  public:
    void set_temperatura(int temperatura);
    void set_EC(int ec);
    void set_nivel_reservorio(int nivel_reservorio);
    void set_PH(int ph);
    void actualizar_thingsboard(int temperatura, int ec, int ph, int nivel_reservorio);
    
};
#endif
