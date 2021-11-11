#include "TestNivelBuffer.h"
#include <Arduino.h>
// Date constructor
TestNivelBuffer::TestNivelBuffer(int pinNivelBuffer)
{
  pin = pinNivelBuffer;
}

int TestNivelBuffer::read()
{
  return random(2);
}
