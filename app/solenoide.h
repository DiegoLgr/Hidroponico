#ifndef _SOLENOIDE
#define _SOLENOIDE
#include <iostream>


class Solenoide {
    public:
        Solenoide(void){}
        void on(void){
            printf("sol on\n");
        }
        void off(void){
            printf("sol off\n");
        }

};
#endif
