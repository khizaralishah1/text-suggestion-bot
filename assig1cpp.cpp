#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <string>
#include <unistd.h>
//#include "list.h"
using namespace std;

extern string login();
extern void welcome(string);
extern void learnMessage();
extern string askQuestion(string);
extern void insertWord(string);
extern void giveHints(char);

int main()
{
    initscr();
    
    // welcome(login());
    // learnMessage();

    insertWord(askQuestion("How are you feeling today? "));

    
    

    endwin();

    return 0;
}