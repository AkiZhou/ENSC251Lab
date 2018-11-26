/**
 * @file Book.h
 * @author Shengcong Zhou * @Date 2018.Jul.9
 * @version 1.0
 * @section This is the interface file for the class Book.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and
// followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus. //
// _____ Shengcong Zhou ____ _____2018.Jul.9______________ //
// ____ 301336141 ______ //

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book
{
public:
    Book();
    Book(string& theTitle, string& theAuthor, string& theDate);

    string getTitle() const;
    string getAuthor() const;
    string getDate() const;

    friend bool operator <(const Book& book1, const Book& book2);

private:
    string title;
    string author;
    string datePublished;
};

int promptChoice();
void addBook(vector<Book>& BookLibrary);
void dispBook(vector<Book>& BookLibrary);
void SortBook(vector<Book>& BookLibrary);

#endif //BOOK_H
