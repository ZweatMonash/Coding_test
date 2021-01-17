#include <iostream>
#include <string.h>
#include <sstream>

#include "LinkedList.h"
#include "Fifo.h"

using namespace std;

int main()
{
    string str;
    int a, n;
    cout << "1. Input a custom sentence" << endl;
    cout << "2. Use default sentence" << endl;

    cin>>a;
    while (a < 1 || a > 2)
    {
        cout << "Invalid entry! Please enter a valid value: ";
        cin >> a;
    }

    if(a == 1)
    {
        getline(cin, str);
    }
    else
    {
        str = "never gonna give you up never gonna let you down never gonna run around and desert you";
    }

    cout << "Enter number n" << endl;
    cin >> n;

    stringstream ss(str);
    string word;

    Fifo str_list;

    while (ss >> word)
    {
        char* char_arr = &word[0];
        str_list.Enqueue(char_arr);
    }

    //Test
    str_list.PrintList();
    str_list.MoveNode(n);
    str_list.ReverseList();
    str_list.Dequeue4();


    return 0;
}
