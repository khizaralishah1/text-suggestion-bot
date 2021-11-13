#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <unistd.h>
using namespace std;

extern void showString(int, int, string);

void insertWord(string val)
{
    fstream myFile("words.txt", ios::in | ios::out);
    //ofstream seek2("words.txt", ios::out | ios::app);

    string word;
    int count;
    int before, after;

    while ( ! myFile.eof() )
    {
        before = myFile.tellg();
        if(before != 0)
            ++before;
        
        myFile >> word >> count; 
        after = myFile.tellg();

        if(word == val)
        {
            myFile.seekg(before - after, ios::cur);
            myFile << word << " " << ++count;
            myFile.close();
            return;
        }
        else if ( word == "l" ) 
            break;
    }

    myFile.seekg(before - after, ios::cur);
    myFile << val << " " << 1 << endl << "l " << 0 << endl;
    myFile.close();
}

void showFrequentWords(char ch, int place)
{
    string freqWords[3] = {"empty", "empty", "empty"};
    int highest1=3, highest2=2, highest3=1;

    string word; int count;

    fstream myFile("words.txt", ios::app);

    while( 1 )
    {
        myFile >> word >> count;
        if(word == "l")
            break;
        if(word[place] == ch)
        {
            if(count >= highest1)
            {
                freqWords[0] = word;
                highest1 = count;
            }
            else if(count >= highest2)
            {
                freqWords[1] = word;
                highest2 = count;
            }
            else if(count >= highest3)
            {
                freqWords[2] = word;
                highest3 = count;
            }
        }     
    }

    myFile.close();

    string fullStr = freqWords[0]+"\t"+freqWords[1]+"\t"+freqWords[2];

    showString(1, 1, fullStr);
}

