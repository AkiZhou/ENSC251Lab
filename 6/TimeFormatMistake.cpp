/**
* @file WordLadder.cpp
* @author Shengcong Zhou * @Date 2018.Jun.28
* @version 1.0
* @brief This is the implementation of class TimeFormatMistake
*/
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and
// followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus. //
// _____ Shengcong Zhou ____ _____2018.Jun.28______________ //
// ____ 301336141 ______ //

#include "TimeFormatMistake.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

TimeFormatMistake::TimeFormatMistake()
{
    // Left blank intentionally
}

TimeFormatMistake::TimeFormatMistake(string wrongInput)
{
    message = "There is no such time as " + wrongInput +
                "\nFollow the exact format e.g. 08:05\nTry again\n";

}

string TimeFormatMistake::getMessage() const
{
    return message;
}

/**
 * @brief This function checks for the violation of the input
 *
 * @param input
 * @return true if any input is illegal
 */
bool isIllegalTime(string input)
{
    int length = 0;
    int hour = 0;
    int minute = 0;

    length = static_cast<int>(input.length());

    // Check for the right format
    if(length != 5)
    {
        return true;
    }

    // Check for illegal input
    for(int i = 0; i < length; i++)
    {
        if(i == 2) // must be ":"
        {
            if(input[i] != ':')
            {
                return true;
            }
            else
            {
                continue;
            }
        }
        else if(! isdigit(input[i]))
        {
            return true;
        }
    }

    // Check for illegal time
    stringstream convert(input);
    convert >> hour;
    convert.ignore(10,':');
    convert >> minute;

    if(hour > 24 || hour < 0 || minute > 60 || minute < 0)
    {
        return true;
    }

    return false;
}

/**
 * @brief This function converts then print 24-hour to 12-hour notation
 *
 * @param time
 */
void time12hrNotation(string time)
{
    int hour = 0;
    int minute = 0;
    char stateMeridian[2] = {'A', 'M'};

    stringstream convert(time);
    convert >> hour;
    convert.ignore(10,':');
    convert >> minute;

    if(hour == 24)
    {
        hour -= 12;
    }
    else if(hour == 0)
    {
        hour = 12;
    }
    else if(hour == 12)
    {
        stateMeridian[0] = 'P';
    }
    else if(hour > 12)
    {
        hour -= 12;
        stateMeridian[0] = 'P';
    }

    printf("%02d:%02d %s\n", hour, minute, stateMeridian);
}