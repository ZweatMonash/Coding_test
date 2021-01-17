#include <iostream>
#include "Fifo.h"
#include "LinkedList.h"
#include "Node.h"

//Get element at start of queue
char * Fifo::Front()
{
    return head->data;
}

//Get element at end of queue
char* Fifo::Rear()
{
    return tail->data;
}

//Remove element at front of queue
void Fifo::Dequeue()
{
    Node* tmp = head;
    head = head->next;
    free(tmp->data);
    free(tmp);
}

//Remove 4 element at front of queue
void Fifo::Dequeue4()
{
    Fifo::Dequeue();
    Fifo::Dequeue();
    Fifo::Dequeue();
    Fifo::Dequeue();
    Fifo::WriteFile("queue_output.txt");
}
