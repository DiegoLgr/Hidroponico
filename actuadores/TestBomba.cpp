#include "TestBomba.h"

// Date constructor
TestBomba::TestBomba(flaot actTimeBomba)
{actTime = actTimeBomba;
 timeleft = 0;
 estado = 0;
}

void TestBomba::act()
{Serial.println("Iniciando bombeo buffer. Tiempo: %d", actleft");
 estado = 1;
 timeleft = actTime;
}

void TestBomba::tick(float timePassed)
{if (estado == 1)
  {
    timeleft -= timePassed;
    if (timeleft <= 0)
     { 
       Serial.println("acabando bombeo buffer");
       estado = 0;
     }
    else
     {
       Serial.println("Sigue bombeo. Tiempo: %d", timeleft); 
     }
  }
}
