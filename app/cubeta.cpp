#include "cubeta.h"


Cubeta_auxiliar::Cubeta_auxiliar(Solenoide solenoide){ this->solenoide = solenoide; }

Cubeta_auxiliar::Cubeta_auxiliar(void){ this->solenoide = solenoide; }

void Cubeta_auxiliar::vierte(bool mas_agua){
    if (mas_agua){
        solenoide.encender();
    } else {
        solenoide.apagar();
    }
}
