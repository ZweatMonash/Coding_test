#include <iostream>
#include <string.h>
#include <fstream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

//Constructor
LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}

//Write to a text file
void LinkedList::WriteFile(string filename)
{
    ofstream myfile;
    myfile.open(filename);

    Node *curr = head;
    while (curr != NULL)
    {
        myfile << curr->data << endl;
        curr = curr->next;
    }

    myfile.close();
}


//Insert a Node at the end of the Linked List
void LinkedList::Enqueue(char* word)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = (char*) malloc(strlen(word) + 1);

    //if a node is created
    if (tmp != NULL)
    {
        tmp->next = NULL;
        strcpy(tmp->data, word);
    }
    else
    {
        return;
    }

    //if there is 0 node in the list
    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

//Print the entire Linked List
void LinkedList::PrintList()
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
    LinkedList::WriteFile("all_output.txt");
}

//Move nth Node to the end of the Linked List
void LinkedList::MoveNode(int n)
{
    Node * curr = head, * prev = NULL;
    int counter = 0;

    while(counter != n)
    {
        prev = curr;
        curr = curr->next;
        counter ++;
    }

    //Check for first and last node
    if(prev == NULL || curr->next == NULL)
    {
        return;
    }

    prev->next = curr->next;
    tail->next = curr;
    tail = curr;
    tail->next = NULL;

    LinkedList::WriteFile("edited_output.txt");

}


//Reverse the order of the entire Linked List
void LinkedList::ReverseList()
{
    Node * curr = head;
    Node * prev = NULL, * next = NULL;

    tail = head;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    LinkedList::WriteFile("reversed_output.txt");
}

//Deconstructor
LinkedList::~LinkedList()
{
    if(head == NULL)
    {
        return;
    }

    Node * curr, *prev;
    prev = head;
    curr = prev->next;
    while(curr != NULL)
    {
        free(prev->data);
        free(prev);
        prev = curr;
        curr = curr->next;
    }

    free(prev->data); //free last node
    free(prev);
}
