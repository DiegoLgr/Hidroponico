#ifndef _CUBETA
#define _CUBETA
#include "solenoide.h"


class Cubeta_auxiliar {
    private:
        Solenoide solenoide;

    public:
        Cubeta_auxiliar();
        Cubeta_auxiliar(Solenoide solenoide);
        void vierte(bool mas_agua);
};
#endif
