#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <string>
#include <unistd.h>
using namespace std;

string name, greetings;

string login();
void welcome(string);
void learnMessage();
string askQuestion();
void showString(int, int, string);
extern void showFrequentWords(char, int);
void spaces(int, int, int);

void spaces(int x, int y, int num)
{
    move(x, y);
    for(int i=0; i<num; ++i)
        printw(" ");
}

void showString(int x, int y, string q)
{
    char tp[q.length()+1];
    strcpy(tp, q.c_str());
    move(x, y);
    printw(tp);
    //refresh();
}

string askQuestion(string q)
{
    string answer;
    clear();

    int ch = 65;
    int place = 0;

    while(ch != '\n')
    {
        showString(5, 5, q);
        move(5, 33+place);
        ch = getch();
        refresh();
        answer.push_back(ch);
        //showString(5, 33+place, answer);
        //spaces(1, 1, 40);
        showFrequentWords(ch, place);
        refresh();
        ++place;
        usleep(500000);
        //clear();
    }
 
    return answer;
}

void learnMessage()
{
    clear();
    mvprintw(2, 20, "I will learn from your behavior");
    refresh();
    sleep(2);
}

string login()
{
    move(5,20);
    printw("Enter a name: ");
  
    int ch = getch();

    while(ch != '\n')
    {
        name.push_back(ch);
        ch = getch();
    }

    clear();
    greetings = "Welcome, " + name + "!";
    return greetings;
}

void welcome(string greetings)
{
    clear();
    
    int len = greetings.length();
    move(5,20);

    int i = 0;

    while(len)
    {   
        addch(greetings[i++]);
        refresh();
        usleep(100000);
        --len;
    }

    usleep(500000);
    clear();
}
