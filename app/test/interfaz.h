#ifndef _INTERFAZ
#define _INTERFAZ
#include <stdio.h>



class Notificador {
    public:
        Notificador(){}
        void nivel_reservorio_bajo(void){
            printf("Alerta nivel bajo\n");
        }
};
#endif
