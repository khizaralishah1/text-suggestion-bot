#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <unistd.h>
using namespace std;

int main()
{
    initscr();

    for(int i=0; i<50; ++i)
    {
        move(1,5);
        addch(i);
        move(5,5);
        addch(i);
        refresh();
        usleep(500000);
        clear();
    }


    return 0;
}