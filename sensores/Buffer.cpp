#include "Buffer.h"

// Date constructor
Buffer::Buffer(float valmax, float valmin, Bomba bomba)
{nivel_agua = 0;   
 valor_max = valmax;
 valor_min = valmin;
 bomba_reservorio = bomba;
}

void Buffer::falta_agua()
{bomba.bombea_agua();
}

void Buffer::sobra_agua()
{bomba.no_bombea_agua();
}

void Buffer::check(float nivel)
{nivel_agua = nivel;
 if (nivel < nivel_agua)
   falta_agua();
 else if (nivel >nivel_agua)
   sobra_agua();
}
