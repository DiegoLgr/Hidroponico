#include "bomba.h"
#include <Arduino.h>

Bomba::Bomba(int pin){ this->pin = pin; }

void Bomba::on(){
    digitalWrite(pin, HIGH);
    Serial.println("bomba on\n");
}

void Bomba::of(){
    digitalWrite(pin, LOW);
    Serial.println("bomba off\n");
}
