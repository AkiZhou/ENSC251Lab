/**
* @file WordLadder.cpp
* @author Shengcong Zhou * @Date 2018.Jun.28
* @version 1.0
* @brief This is a program that converts 24-hour notation to 12-hour notation
*/
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and
// followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus. //
// _____ Shengcong Zhou ____ _____2018.Jun.28______________ //
// ____ 301336141 ______ //

#include <iostream>
#include <string>
#include "TimeFormatMistake.h"

using namespace std;

int main()
{

    string time;
    char choice = 'y';
    bool error = true;
    int counter = 0;

    while(choice == 'y')
    {
        try
        {
            cout << "Enter time in 24-hour notation:\n";
            cin >> time;
            if(isIllegalTime(time))
            {
                throw TimeFormatMistake(time);
            }

            cout << "That is the same as\n";
            time12hrNotation(time);

            error = true;
            counter = 0;
            while(error)
            {
                if(counter > 0)
                {
                    cerr << "ERROR: invalid choice\nTry again\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
                else
                {
                    cout << "Again?(y/n)\n";
                }

                cin >> choice;
                if(choice == 'y' || choice == 'n')
                {
                    error = false;
                }
                counter++;
            }
        }
        catch(TimeFormatMistake e)
        {
            cerr << e.getMessage();
            cin.clear();
            cin.ignore(1000,'\n');
            choice = 'y';
        }
    }

    cout << "End of program\n";

    return 0;
}