#include "Buffer.h"
#include "TestBomba.h"
// Date constructor
Buffer::Buffer(TestBomba bomba)
{
 bomba_reservorio = bomba;
}

void Buffer::falta_agua()
{bomba_reservorio.act();
}

void Buffer::check(int nivel)
{
 if (nivel == 0)
   falta_agua();
}
