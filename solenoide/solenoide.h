#ifndef _SOLENOIDE
#define _SOLENOIDE
#include <iostream>


class Solenoide {
    private: 
        int ms;

    public:
        Solenoide(void){}
        void encender(void){
            printf("sol on\n");
        }
        void encender(int ms){
            this->ms = ms;
            this->encender();
        }
        void apagar(void){
            printf("sol off\n");
        }
        void tick(int ms){
            this->ms -= ms;
            if (this->ms <= 0){ this->apagar(); }
        }
};


#endif
