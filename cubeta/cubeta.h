#ifndef _CUBETA
#define _CUBETA
#include "bomba.h"
#include "notificador.h"


class Cubeta {
    private:
        Bomba bomba;

    public:
        Cubeta();
        Cubeta(Bomba bomba);
        void vierte(bool mas_agua);
};
#endif
