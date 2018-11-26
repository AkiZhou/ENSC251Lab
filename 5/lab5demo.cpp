/**
* @file lab5demo.cpp
* @author Shengcong Zhou * @Date 2018.Jun.23
* @version 1.0
* @brief This is the driver program to test class WordLadder
*/
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and
// followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus. //
// _____ Shengcong Zhou ____ _____2018.Jun.23______________ //
// ____ 301336141 ______ //

#include <iostream>
#include "WordLadder.h"

int main()
{
    bool end = false;

    do{
        WordLadder newGame;

        newGame.prompt();
        newGame.play();

        cout << "\nHit '1' to exit, any other key to continue\n";
        cin >> end;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << endl;
            continue;
        }
        cout << endl;
    }while(! end);

    remove("newWords.txt");
    remove("copyList.txt");
    return 0;
}