/**
 * @file lab4.cpp
 * @author Shengcong Zhou * @Date 2018.Jun.8
 * @version 1.0
 * @section This is the implementation file for the class Pairs.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and
// followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus. //
// _____ Shengcong Zhou ____ _____2018.May.30______________ //
// ____ 301336141 ______ //

#include <iostream>
#include <string>
#include "lab4.h"

using namespace std;

// Constructor definitions
Pairs::Pairs()
{
    f = 0;
    s = 0;
}

Pairs::Pairs(int first)
{
    f = first;
    s = 0;
}

Pairs::Pairs(int first, int second)
{
    f = first;
    s = second;
}

// Overloaded operator definitions
istream& operator>>(istream& ins, Pairs& second)
{
    int counter = 0;
    char test = '\0';
    bool inputError = false;

    do
    {
        if(counter >0)
        {
            cerr << "ERROR: wrong input format\nPairs has to be in the form"
                    "(x,y)\nIt's ok to have whitespaces before x or y, "
                    "but not after\nTry again\n";
            ins.clear();
            ins.ignore(10000,'\n');
        }
        counter++;

        // Check the format
        cin.get(test);
        if(test != '(')
        {
            inputError = true;
            continue;
        }

        ins >> second.f;

        // Check the format
        cin.get(test);
        if(test != ',')
        {
            inputError = true;
            continue;
        }

        ins >> second.s;

        // Check the format
        cin.get(test);
        if(test != ')')
        {
            inputError = true;
            continue;
        }

        inputError = false;
    }
    while(ins.fail() || inputError);

    return ins;
}

ostream& operator<<(ostream& outs, const Pairs& second)
{
    outs << "(" << second.f << "," << second.s << ")";

    return outs;
}

Pairs Pairs::operator+(Pairs second)
{
    Pairs ans;
    ans.f = f + second.f;
    ans.s = s + second.s;
    return ans;
}

Pairs Pairs::operator-(Pairs second)
{
    Pairs ans;
    ans.f = f - second.f;
    ans.s = s - second.s;
    return ans;
}

Pairs Pairs::operator*(Pairs second)
{
    Pairs ans;
    ans.f = f * second.f;
    ans.s = s * second.f;
    return ans;
}

/**
 * @brief This function prompts for two pairs of numbers
 * @param first is the 1st pair
 * @param second is the 2nd pair
 * @return void
 */
void prompt(Pairs& first, Pairs& second)
{
    string test = "\n";
    int counter = 0;

    do
    {
        if(counter > 0)
        {
            cerr << "ERROR: Try again\n";
            cin.clear();
            cin.ignore(10000,'\n');
        }

        cout << "Enter first pair\n";
        cin >> first;

        // Check for garbage input
        getline(cin,test);
        if(test[0] != '\n' && test[0] != ' ' && test[0] != '\0')
        {
            cerr << "Ignoring invalid part of input\n";
        }

        cout << "Enter second pair\n";
        cin >> second;

        // Check for garbage input
        getline(cin,test);
        if(test[0] != '\n' && test[0] != ' ' && test[0] != '\0')
        {
            cerr << "Ignoring invalid part of input\n";
        }
        counter++;
    }
    while(cin.fail());

}

/**
 * @brief This function will display the answers
 * @param first is the 1st pair
 * @param second is the 2nd pair
 * @return void
 */
void displayAns(Pairs& first,  Pairs& second)
{
    cout << "Addition rule: (a, b) + (c, d) = (a + c, b + d)\nans = "
         << first + second << endl << endl;
    cout << "Subtraction rule: (a, b) - (c, d) = (a - c, b - d)\nans = "
         << first - second << endl << endl;
    cout << "Multiplication rule: (a, b) * (c, d) = (a * c, b * c)\nans = "
         << first * second << endl << endl;
}