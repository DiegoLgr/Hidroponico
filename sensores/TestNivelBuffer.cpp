#include "TestNivelBuffer.h"

// Date constructor
TestNivelBuffer::TestNivelBuffer(int pinNivelBuffer)
{
  pin = pinNivelBuffer;
}

int NivelBuffer::read()
{
  return random(2);
}
