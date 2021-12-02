#include "reservorio.h"



Reservorio::Reservorio(Cubeta cubeta, Sensor_nivel snb, Sensor_nivel sna, Notificador notificador)
        : cubeta{cubeta}, sensor_nivel_bajo{snb}, sensor_nivel_alto{sna}, notificador{notificador}
{
    this->check_nivel();
}


void Reservorio::tick(int ms){
    this->check_nivel();

    switch (this->estado){
        case (RELLENANDO):
            if (this->nivel_alto){
                cubeta.vierte(false);
                this->estado = BASE;
            }
            break;
        default: 
            if (this->nivel_bajo){
                cubeta.vierte(true);
                this->estado = RELLENANDO;
                this->notificador.nivel_reservorio_bajo();
            }
    }
}

void Reservorio::check_nivel(void){
    this->nivel_alto = this->sensor_nivel_alto.read();
    this->nivel_bajo = this->sensor_nivel_bajo.read();
}
