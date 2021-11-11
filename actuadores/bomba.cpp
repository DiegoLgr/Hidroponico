Bomba::Bomba(int pin){ this.pin = pin; }

Bomba::void bombea_agua(){ digital.write(pin, HIGHT); }

Bomba::void no_bombea_agua(){ digital.write(pin, LOW); }
