#include "NivelBuffer.h"

// Date constructor
NivelBuffer::NivelBuffer(int pinNivelBuffer)
{
  pin = pinNivelBuffer;
}

int NivelBuffer::read()
{
  digitalRead(pin);
}
