/**
* @file WordLadder.h
* @author Shengcong Zhou * @Date 2018.Jun.23
* @version 1.0
* @brief This is the interface of class grade
*/
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and
// followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus. //
// _____ Shengcong Zhou ____ _____2018.Jun.23______________ //
// ____ 301336141 ______ //

#ifndef INC_5_WORDLADDER_H
#define INC_5_WORDLADDER_H

#include <string>

using namespace std;

// Global constant
const int WORDS_IN_DICTIONARY = 87314;

class WordLadder
{
public:
    WordLadder();
    void prompt();
    void play();

private:
    string startWord;
    string endWord;
    string nextWord;
    int numMatchingChar;
    int lengthNewList;


    bool inList(string word);
    bool newList();
    void copyFile();
    void chooseNext();

};


#endif //INC_5_WORDLADDER_H
