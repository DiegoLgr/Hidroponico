#include "bomba.h"
//#include <Arduino.h>

Bomba::Bomba(int pin){ this->pin = pin; }

void Bomba::on(){
    //digital.write(pin, HIGHT);
    printf("bomba on\n");
}

void Bomba::of(){
    //digital.write(pin, LOW);
    printf("bomba of\n");
}
