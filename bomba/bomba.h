#ifndef _BOMBA_H
#define _BOMBA_H

#include <iostream>



class Bomba {
    private:
        int pin;

    public:
        Bomba(int pin);
        void on();
        void of();
};

#endif
