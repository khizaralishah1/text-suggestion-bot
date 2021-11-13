#ifndef F2F0578F_2238_487E_B224_3124D4A7B680
#define F2F0578F_2238_487E_B224_3124D4A7B680
#include <iostream>
#include <string>
using namespace std;

class node
{
private:
    string data;
    int frequency;
    node* next;

    static node* head, *last;
    static node* traverse;

public:
    node(string val) { data = val; frequency = 1; next = nullptr; }

    static void insert(string);
    static bool exists(string);
    
};

#endif /* F2F0578F_2238_487E_B224_3124D4A7B680 */
