#ifndef _CUBETA
#define _CUBETA
#include "../actuadores/bomba.h"
#include "../notificador/notificador.h"


class Cubeta {
    private:
        Bomba bomba;

    public:
        Cubeta();
        Cubeta(Bomba bomba);
        void vierte(bool mas_agua);
};
#endif
