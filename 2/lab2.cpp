/**
 * @file    lab2.cpp
 * @author  Shengcong Zhou
 * @date    2018.May.23
 * @version 1.0
 *
 * @brief <ENSC 251, Lab 2>
 *
 * @section LA03
 *
 * @brief This program prompts for alphabetic first and last name and
 *        convert them into Pig Latin
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and
// followed the Academic Honesty and Integrity related policies as outlined
// in the syllabus. //
// SHENGCONG ZHOU 2018.MAY.23 //
// (STUDENT ID) 301336141

#include <iostream>
#include <string> //    I have used length()

using namespace std;

// Function declaration
bool isNameAlphabetic(string name);
string prompt(string inputValue);
string convertToLowercase(string name);
int vowelOrConsonant(char firsLetter);
string bringFirstToEnd(string name);
string convertPigLatin(string name);

// Global constant
int vowel = 1;
int consonant = 2;

int main()
{
    string first;
    string last;

    first = prompt("first name");
    last = prompt("last name");

    first = convertToLowercase(first);
    last = convertToLowercase(last);

    first = convertPigLatin(first);
    last = convertPigLatin(last);

    cout << "Your name in Pig Latin is:\n";
    cout << first << " " << last << endl << endl;

    return 0;
}

/**
 * @brief This function verify if all characters of name is alphabetic or not
 *
 * @param name is the either first or last name inputted by the user
 * @return bool
 */
bool isNameAlphabetic(string name)
{
    long int lengthName = 0;

    lengthName = name.length();

    // This for loop verify each character of string name is alphabetic or not
    for(int i = 0; i < lengthName; i++)
    {
        if( !isalpha(name[i]))
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief This function prompt for string input
 *
 * @param inputValue is a string telling what to prompt for
 * @return string str
 */
string prompt(string inputValue)
{
    string str;
    int counter = 0;
    bool inputError = true;

    do
    {
        if(counter > 0)
        {
            cerr << "ERROR: incorrect input for " << inputValue << endl
                 << "No numbers nor symbols nor whitespaces allowed\n"
                         "Try again\n";
            cin.clear();
        }
        else
        {
            cout << "Enter your " << inputValue << endl;
        }

        getline(cin, str);
        inputError = !isNameAlphabetic(str);

        counter++;
    }
    while(inputError);

    cout << "Your " << inputValue << " is:" << endl << str << endl << endl;

    return str;
}

/**
 * @brief This function converts a string to all lowercase
 *
 * @param name is the either first or last name inputted by the user
 * @return string lowercaseName
 */
string convertToLowercase(string name)
{
    string lowercaseName (name.length(), '\0');

    // This for loop converts character by character to lowercase
    for(int i = 0; i < name.length(); i++)
    {
        lowercaseName[i] = (char)tolower(name[i]);
    }

    return lowercaseName;
}

/**
 * @brief This function determines if name starts with a vowel or a consonant
 *
 * @param name is the either first or last name inputted by the user
 * @return int 1 if vowel, 2 if consonant
 */
int vowelOrConsonant(char firsLetter)
{
    if(firsLetter == 'a' || firsLetter == 'e' || firsLetter == 'i' ||
            firsLetter == 'o' || firsLetter == 'u')
    {
        return vowel;
    }
    else
    {
        return consonant;
    }
}

/**
 * @brief This function brings the first character of a string to the end
 *
 * @param name is the either first or last name inputted by the user
 * @return string newName
 */
string bringFirstToEnd(string name)
{
    string newName (name.length(), '\0');

    for(int i = 0; i < name.length(); i++)
    {
        if(i == name.length() - 1)
        {
            newName[i] = name[0];
            break;
        }
        newName[i] = name[i + 1];
    }

    return newName;
}

/**
 * @brief This function converts a string into Pig Latin by the following rules
 *      -If the first letter is a vowel then ass "way" to the end
 *      -If the first letter is a consonant then move it to the end and add
 *      "ay" to the end
 *      -Capitalize the first letter after manipulations above
 *
 * @param name is the either first or last name inputted by the user
 * @return string pigLatinName
 */
string convertPigLatin(string name)
{
    string pigLatinName (name.length(), '\0');
    int mode = 0;

    mode = vowelOrConsonant(name[0]);

    if(mode == vowel)
    {
        pigLatinName = name + "way";
    }
    else if(mode == consonant)
    {
        name = bringFirstToEnd(name);
        pigLatinName = name + "ay";
    }

    pigLatinName[0] = (char)toupper(pigLatinName[0]);

    return pigLatinName;
}