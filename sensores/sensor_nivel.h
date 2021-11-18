#ifndef _SENSOR_NIVEL
#define _SENSOR_NIVEL

#include <array>
#include <iostream>


class Sensor_nivel{
    public:
        std::array<int,20> niveles;
        int idx;
        bool alto;
        Sensor_nivel(bool a)
            :niveles{ 0, 0, 0, 1, 1, 1, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 , 0 }
        {
            alto = a;
            idx = 0;
        }

        Sensor_nivel(Sensor_nivel& sn)
            :niveles{ 0, 0, 0, 1, 1, 1, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 , 0 }
        {
            alto = sn.alto;
            idx = sn.idx;
        }

        Sensor_nivel(Sensor_nivel&& sn)
            :niveles{ 0, 0, 0, 1, 1, 1, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 , 0 }
        {
            idx = 4;
            this->alto = sn.alto;
        }

        
        bool read(void){
            int nivel = niveles[idx];
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
    
            return true;
    }
};
#endif
