/**
 * @file lab3_b.cpp
 * @author Shengcong Zhou * @Date 2018.May.30
 * @version 1.0
 * @brief
 * This program demonstrates a car's speed
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and
// followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus. //
// _____ Shengcong Zhou ____ _____2018.May.30______________ //
// ____ 301336141 ______ //

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief This class defines information about a car
 */
class Car
{
public:
    Car(int year, string maker);

    // Accessor declaration
    int getYearModel();
    string getMake();
    int getSpeed();

    void accelerate();
    void brake();

private:
    int yearModel;
    string make;
    int speed;

};

/**
 * @brief Main function
 * @return 0
 */
int main()
{
    Car teslaModelS(2018, "Tesla Motors");

    for(int i = 0; i < 5; i++)
    {
        teslaModelS.accelerate();
        cout << "Current speed is: " << teslaModelS.getSpeed() << endl;
    }

    for(int i = 0; i < 5; i++)
    {
        teslaModelS.brake();
        cout << "Current speed is: " << teslaModelS.getSpeed() << endl;
    }
    cout << endl;
    return 0;
}

// Constructor definition
Car::Car(int year, string maker)
{
    yearModel = year;
    make = maker;
    speed = 0;
}

// Accessor definitions
int Car::getYearModel()
{
    return yearModel;
}
string Car::getMake()
{
    return make;
}
int Car::getSpeed()
{
    return speed;
}

/**
 * @brief This function adds 5 to speed each time when called
 *
 * @return void
 */
void Car::accelerate()
{
    speed = speed + 5;
}

/**
 * @brief This function subtracts 5 to speed each time when called
 *
 * @return void
 */
void Car::brake()
{
    speed = speed - 5;
}