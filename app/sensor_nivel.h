#ifndef _SENSOR_NIVEL
#define _SENSOR_NIVEL


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
            int nivel = niveles[i_niveles ++];
            if (this->alto && nivel == 2){
                return true;
            } else if (!(this->alto) && nivel == 0) {
                return true;
            } else {
                return false;
            }
        }
};
#endif
