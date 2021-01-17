#pragma once
#include "LinkedList.h"

class Fifo: public LinkedList
{
public:

    char * Front();
    char * Rear();
    void Dequeue();
    void Dequeue4();

};

