/**
 * @file Book.cpp
 * @author Shengcong Zhou * @Date 2018.Jul.9
 * @version 1.0
 * @section This is the implementation file for the class Book.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and
// followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus. //
// _____ Shengcong Zhou ____ _____2018.Jul.9______________ //
// ____ 301336141 ______ //

#include "Book.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// Constructors
Book::Book()
{
    // Blank intended
}

Book::Book(string& theTitle, string& theAuthor, string& theDate)
{
    title = theTitle;
    author = theAuthor;
    datePublished = theDate;
}

// Accessors
string Book::getAuthor() const
{
    return author;
}

string Book::getDate() const
{
    return datePublished;
}

string Book::getTitle() const
{
    return title;
}

bool operator <(const Book& book1, const Book& book2)
{
    return (book1.author < book2.author);
}

/**
 * @brief This function prompts the user for a choice of what to do
 *
 * @return choice
 */
int promptChoice()
{
    int choice = 0;
    int counter = 0;

    cout << "Select from the following choices:\n"
            "1. Add new book\n2.Print listing sorted by author\n3.Quit\n";
    do
    {
        if(counter > 0)
        {
            cerr << "ERROR: invalid input\nTry again\n";
            cin.clear();
            cin.ignore(10000,'\n');
        }

        cin >> choice;

        counter++;
    }
    while(cin.fail() || choice < 1 || choice > 3);

    return choice;
}

