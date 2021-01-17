#pragma once
#include <string>
#include "Node.h"

using namespace std;

class LinkedList
{
protected:
    Node *head, *tail;

public:

    LinkedList();
    ~LinkedList();

    void Enqueue(char* word);
    void MoveNode(int n);
    void PrintList();
    void ReverseList();
    void WriteFile(string filename);
};

