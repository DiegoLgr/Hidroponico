#include "TestBomba.h"
#include <Arduino.h>

TestBomba::TestBomba(int actTimeBomba)
{actTime = actTimeBomba;
 timeLeft = 0;
 estado = 0;
}

void TestBomba::act()
{Serial.println("Iniciando bombeo buffer. Tiempo:" +(String)actTime);
 estado = 1;
 timeLeft = actTime;
}

void TestBomba::tick(int timePassed)
{Serial.println((String) timeLeft);
 if (estado == 1)
  {
    timeLeft -= timePassed;
    Serial.println((String) timeLeft);
    if (timeLeft <= 0)
     { 
       Serial.println("acabando bombeo buffer");
       estado = 0;
     }
    else
     {
       Serial.println("Sigue bombeo. Tiempo: " + (String)timeLeft); 
     }
  }
}
