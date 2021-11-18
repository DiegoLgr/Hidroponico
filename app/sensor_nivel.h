#ifndef _SENSOR_NIVEL
#define _SENSOR_NIVEL

#include <iostream>


class Sensor_nivel{
    private:
	int niveles[20] { 0, 0, 0, 1, 1, 1, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 , 0 };
	int i_niveles = 0;
    public:
        bool alto;
        Sensor_nivel(){ this->alto = false; }
        Sensor_nivel(bool alto){
            this->alto = alto;
        }
        bool read(void){
            int nivel = this->niveles[this->i_niveles ++];

	    if(this->alto){
		    std::cout << "Sensor: Bajo lellendo " << nivel << "\n";
	    } else {
		    std::cout << "Sensor: Alto lellendo " << nivel << "\n";
	    }
            if (this->alto && nivel == 2){
	    std::cout << "Sensor: ¡¡ Alto !! " << "\n";
                return true;
            } else if (!(this->alto) && nivel == 0) {
		    std::cout << "Sensor: ¡¡ Bajo !! " << "\n";
                return true;
            } else {
                return false;
            }
        }
};
#endif
