/**
* @file WordLadder.cpp
* @author Shengcong Zhou * @Date 2018.Jun.28
* @version 1.0
* @brief This is the interface of class WordLadder
*/
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and
// followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus. //
// _____ Shengcong Zhou ____ _____2018.Jun.28______________ //
// ____ 301336141 ______ //

#ifndef TIMEFORMATMISTAKE_H
#define TIMEFORMATMISTAKE_H
#include <iostream>
#include <string>

using namespace std;

class TimeFormatMistake
{
public:
    TimeFormatMistake();
    TimeFormatMistake(string wrongInput);
    string getMessage() const;

private:
    string message;
};

bool isIllegalTime(string input);
void time12hrNotation(string time);

#endif //TIMEFORMATMISTAKE_H
