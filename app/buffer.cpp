#include "buffer.h"



Buffer::Buffer(Bomba bomba, Sensor_nivel snb, Sensor_nivel sna)
        : bomba{bomba},
        sensor_nivel_bajo{snb},
        sensor_nivel_alto{sna}
{
    this->check_nivel();
}


void Buffer::tick(int nivel) {
    this->check_nivel();

    switch (this->estado){
        case (RELLENANDO):
            if (this->nivel_alto){
                bomba.of();
                this->estado = BASE;
            }
            break;
        case(BASE): 
            if (this->nivel_bajo){
                bomba.on();
                this->estado = RELLENANDO;
            }
            break;
    }
}

void Buffer::check_nivel(void){
    this->nivel_bajo = this->sensor_nivel_bajo.read();
    this->nivel_alto = this->sensor_nivel_alto.read();
}
