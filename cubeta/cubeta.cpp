#include "cubeta.h"


Cubeta::Cubeta(Bomba bomba): bomba{bomba}{ }

void Cubeta::vierte(bool mas_agua){
    if (mas_agua){
        bomba.on();
    } else {
        bomba.of();
    }
}
