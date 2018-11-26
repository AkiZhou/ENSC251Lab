/**
 * @file lab7demo.cpp
 * @author Shengcong Zhou * @Date 2018.Jul.9
 * @version 1.0
 * @section This is the driver program for the class Book
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and
// followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus. //
// _____ Shengcong Zhou ____ _____2018.Jul.9______________ //
// ____ 301336141 ______ //

#include "Book.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<Book> BookLibrary;
    int choice = 0;
    string newTitle;
    string newAuthor;
    string newDate;
    int size = 0;

    do
    {
        choice = promptChoice();
        cout << endl;

        if(choice == 1) {
            cin.ignore();
            cout << "Enter title:\n";
            getline(cin, newTitle);
            cout << "Enter author:\n";
            getline(cin, newAuthor);
            cout << "Enter the date:\n";
            getline(cin,newDate);
            cout << endl;

            Book newBook(newTitle, newAuthor, newDate);

            BookLibrary.push_back(newBook);

        }
        else if(choice == 2)
        {
                size = static_cast<int>(BookLibrary.size());

                if(BookLibrary.empty())
                {
                    cerr << "ERROR: there is no book in the database\n\n";
                    continue;
                }

                sort(BookLibrary.begin(), BookLibrary.end());

                cout << "The books entered so far, sorted alphabetically by author are:\n";

                for(int i = 0; i < size; i++)
                {
                    cout << "\t" << BookLibrary[i].getAuthor() << ". "
                         << BookLibrary[i].getTitle() << ". "
                         <<BookLibrary[i].getDate() << "." << endl;
                }

                cout << endl;
        }
    }
    while(choice != 3);

    return 0;
}