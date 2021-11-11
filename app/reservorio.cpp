#include "reservorio.h"

Reservorio::Reservorio(){
            this->cubeta = cubeta;
            this->notificador = Interfaz();
            this->sensor_nivel_alto = Sensor_nivel();
            this->sensor_nivel_bajo = Sensor_nivel();
}
Reservorio::Reservorio(Sensor_nivel sensor_nivel_bajo, Sensor_nivel sensor_nivel_alto, Cubeta_auxiliar cubeta, Interface notificador){
            this->cubeta = cubeta;
            this->notificador = notificador;
            this->sensor_nivel_alto = sensor_nivel_alto;
            this->sensor_nivel_bajo = sensor_nivel_bajo;
}

void Reservorio::tick(int ms){
    this->check_nivel();

    switch (this->estado){
        case (Estados.rellenando):
            if (this->nivel_alto){
                cubeta.vierte(false);
                this->state = Estados.base;
            }
            break;
        default: 
            if (this->nivel_bajo){
                cubeta.vierte(true);
                this->state = Estados.rellenando;
                this->notificador.nivel_reservorio_bajo();
            }
    }
}

void Reservorio::check_nivel(void){
    if (this->sensor_nivel_alto.read()){
        this->nivel_alto = true;
        this->nivel_bajo = false;
    }
    if (this->sensor_nivel_bajo.read()){
        this->nivel_alto = false;
        this->nivel_bajo = true;
    } else {
        this->nivel_alto = false;
        this->nivel_bajo = false;
    }
}
