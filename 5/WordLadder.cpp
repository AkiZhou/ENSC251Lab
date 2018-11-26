/**
* @file WordLadder.cpp
* @author Shengcong Zhou * @Date 2018.Jun.23
* @version 1.0
* @brief This is the implementation of class WordLadder
*/
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and
// followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus. //
// _____ Shengcong Zhou ____ _____2018.Jun.23______________ //
// ____ 301336141 ______ //

#include <iostream>
#include <fstream>
#include <string>
#include "WordLadder.h"

using namespace std;

WordLadder::WordLadder()
{
    startWord = '\n';
    endWord = '\n';
    nextWord = '\n';
    numMatchingChar = 0;
    lengthNewList = 0;
}

/**
 * @brief This function prompts for the start word and end word
 */
void WordLadder::prompt()
{
    int counter = 0;
    cout << "Hi, welcome to Word Ladder\n";

    do
    {
        if(counter > 0)
        {
            cout << "Well, your word isn't in my dictionary\nTry again\n\n";
        }

        cout << "Enter the first word for the game: ";
        cin >> startWord;

        if(cin.fail())
        {
            cerr << "ERROR: invalid input\nTry again\n\n";
        }

        counter++;
    }
    while(! inList(startWord));

    counter = 0;
    do
    {
        if(counter > 0)
        {
            cout << "Well, your word isn't in my dictionary\nTry again\n\n";
        }

        cout << "Enter the second word for the game: ";
        cin >> endWord;

        if(cin.fail())
        {
            cerr << "ERROR: invalid input\nTry again\n\n";
        }

        counter++;
        if(startWord == endWord)
        {
            cout << "You chose the same words, game completed\n";
        }
    }
    while(! inList(endWord));

    return;
}

/**
 * @brief This function checks if a word is in the dictionary
 *
 * @param word is the user inputted word
 * @return true if it is in the dictionary
 */
bool WordLadder::inList(string word)
{
    string listWord;

    ifstream list;
    list.open("words.txt");
    if(list.fail())
    {
        cerr << "ERROR: failed opening the original dictionary\nTerminating\n";
        exit(0);
    }

    while(! list.eof())
    {
        list >> listWord;

        if(word == listWord)
        {
            return true;
        }
    }

    list.close();
    return false;
}

/**
 * @brief This function prepares word ladder program, mainly narrows down the
 *        dictionary for efficiency
 */
void WordLadder::play()
{
    string listWord;

    if(startWord.length() != endWord.length())
    {
        cout << "Your words have different length, the game fails\n";
        return;
    }

    // Shrink the dictionary
    // Open input file
    ifstream originalList;
    originalList.open("words.txt");
    if(originalList.fail())
    {
        cerr << "ERROR: failed opening the original dictionary\nTerminating\n";
        exit(0);
    }

    // Create new file
    ofstream newList;
    remove("newWords.txt");
    newList.open("newWords.txt");
    if(newList.fail())
    {
        cerr << "ERROR: failed creating a new dictionary\nTerminating\n";
        exit(0);
    }

    // Word has to be the same length and kick out the start word
    for(int i = 0; i < WORDS_IN_DICTIONARY; i++)
    {
        originalList >> listWord;

        if(startWord.length() == listWord.length())
        {
            newList << listWord << endl;
            lengthNewList++;
        }
    }

    // Close files
    originalList.close();
    newList.close();

    // Repeat similar processes until end word
    cout << "Here is the word chain from " << startWord << " to " << endWord
         << endl << endl;
    nextWord = startWord;
    chooseNext();

    return;
}

/**
 * @brief This is a recursive function with 2 base cases:
 *        end of game, game fails. Otherwise it will keep calling itself for
 *        the next word
 *
 */
void WordLadder::chooseNext()
{
    if(nextWord == endWord)
    {
        cout << nextWord << endl;
        return;
    }
    else
    {
        cout << nextWord << endl;
        startWord = nextWord;

        // If no more words to choose, it means the game fails
        if(! newList())
        {
            return;
        }
        chooseNext();
    }
}

/**
 * @brief This function refines the dictionary and chooses a new word
 *
 * @return bool true when there is further choices otherwise false
 */
bool WordLadder::newList()
{
    copyFile();

    string listWord;
    int lengthOldList = lengthNewList;
    lengthNewList = 0;
    numMatchingChar = 0;
    int matchingChar = 0;
    int difference = 0;

    bool isNext = false;

    // Determine matching character of start and end
    for(int i = 0; i < static_cast<int>(startWord.length()); i++)
    {
        if(startWord[i] == endWord[i])
        {
            numMatchingChar++;
        }
    }

    // Open input file
    ifstream copyList;
    copyList.open("copyList.txt");
    if(copyList.fail())
    {
        cerr << "ERROR: failed opening the original dictionary\nTerminating\n";
        exit(0);
    }

    // Create new file
    ofstream newList;
    remove("newWords.txt");
    newList.open("newWords.txt");
    if(newList.fail())
    {
        cerr << "ERROR: failed creating a new dictionary\nTerminating\n";
        exit(0);
    }

    // Refine the list and choose nextWord
    for(int i = 0; i < lengthOldList; i++)
    {
        copyList >> listWord;
        matchingChar = 0;
        difference = 0;

        // Kick out the start word
        if(listWord != startWord)
        {
            for(int j = 0; j < static_cast<int>(startWord.length()); j++)
            {
                // Determine difference char
                if(startWord[j] != listWord[j])
                {
                    difference++;
                }
                // Determine matching char
                if(endWord[j] == listWord[j])
                {
                    matchingChar++;
                }
            }

            newList << listWord << endl;
            lengthNewList++;
        }

        // Choose next word
        if(difference == 1)
        {
            // Kick out bad choices
            if(matchingChar > numMatchingChar)
            {
                nextWord = listWord;
                isNext = true;
            }
        }
    }

    if(! isNext)
    {
        cout << "No more path, the game fails\n";
        return false;
    }

    return true;
}

/**
 * @brief This function copies newWords.txt to copyList.txt
 */
void WordLadder::copyFile()
{
    string listWord;

    // Open original file
    ifstream originalList;
    originalList.open("newWords.txt");
    if(originalList.fail())
    {
        cerr << "ERROR: failed opening the original dictionary for copy\n"
                "Terminating\n";
        exit(0);
    }

    // Create copy file
    ofstream copyList;
    remove("copyList.txt");
    copyList.open("copyList.txt");
    if(copyList.fail())
    {
        cerr << "ERROR: failed creating a copy dictionary\nTerminating\n";
        exit(0);
    }

    // Copy the content
    for(int i = 0; i < lengthNewList; i++)
    {
        originalList >> listWord;
        copyList << listWord << endl;
    }
}
