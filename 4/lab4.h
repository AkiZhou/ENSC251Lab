/**
 * @file lab4.h
 * @author Shengcong Zhou * @Date 2018.Jun.8
 * @version 1.0
 * @section This is the interface for the class Pairs.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and
// followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus. //
// _____ Shengcong Zhou ____ _____2018.May.30______________ //
// ____ 301336141 ______ //

#ifndef ENSC251_LAB4_LAB4_H
#define ENSC251_LAB4_LAB4_H

#include <iostream>

using namespace std;

class Pairs
{
public:
    Pairs();

    Pairs(int first);

    Pairs(int first, int second);

    // Overloading unary operators
    Pairs operator+(Pairs second);
    Pairs operator-(Pairs second);
    Pairs operator*(Pairs second);

    // Other members and friends
    friend istream& operator>>(istream& ins, Pairs& second);
    friend ostream& operator<<(ostream& outs, const Pairs& second);
    friend void prompt(Pairs& first,  Pairs& second);
    friend void displayAns(Pairs& first,  Pairs& second);

private:
    int f;
    int s;
};

#endif //ENSC251_LAB4_LAB4_H