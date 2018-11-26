/**
 * @file lab1.cpp
 * @author Shengcong Zhou
 * @Date   5/15/2018
 * @Version 1.0
 * @This program will ask for the day, starting time and duration for calls and calculate the cost for each calls and the total cost until the user has chosen to terminate
 */
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus. //
// SHENGCONG ZHOU 2018.MAY.15 //
// (STUDENT ID) 301336141

#include <iostream>

using namespace std;

int main() {
    char day[2] = "";
    int intDay = 0; //Used for assigning the day
    int hourStarted = 0; //In 24 hour notation
    int minStarted = 0; //In 24 hour notation
    int callDuration = 0; //In minute
    bool inputError = false;
    bool done = false; //Used to see if the user has inputted all the calls
    int counter= 0;
    double rate = 0;
    double cost = 0;

    //Run loop while the user is not done inputting calls
    while(!done){

        /////////////////////////////////////////////////////////////////////////////////////////////
        //Prompt for the day of week
        counter = 0; //Reset counter

        do{
            if(counter > 0){
                cerr << "ERROR: incorrect input for day of week\nTry again\n";
                cin.clear(); cin.ignore(100,'\n');
            }
            else{
                cout << "Enter the day of week when the call started\n";
            }

            cin >> day;

            counter++;

            //Assign the day and verify if the word is meaningful
            inputError = false;
            if((day[0] == 'M' || day[0] == 'm') && (day[1] == 'O' || day[1] == 'o')){
                intDay = 1;
            }
            else if((day[0] == 'T' || day[0] == 't') && (day[1] == 'U' || day[1] == 'u')){
                intDay = 2;
            }
            else if((day[0] == 'W' || day[0] == 'w') && (day[1] == 'E' || day[1] == 'e')){
                intDay = 3;
            }
            else if((day[0] == 'T' || day[0] == 't') && (day[1] == 'H' || day[1] == 'h')){
                intDay = 4;
            }
            else if((day[0] == 'F' || day[0] == 'f') && (day[1] == 'R' || day[1] == 'r')){
                intDay = 5;
            }
            else if((day[0] == 'S' || day[0] == 's') && (day[1] == 'A' || day[1] == 'a')){
                intDay = 6;
            }
            else if((day[0] == 'S' || day[0] == 's') && (day[1] == 'U' || day[1] == 'u')){
                intDay = 7;
            }
            else{
                inputError = true;
            }

        }while(cin.fail() || inputError);

        /////////////////////////////////////////////////////////////////////////////////////////////
        //Prompt for the time when call started
        counter = 0; //Reset counter

        do{
            if(counter > 0){
                cerr << "ERROR: incorrect input for time started\nTry again\n";
                cin.clear(); cin.ignore(100,'\n');
            }
            else{
                cout << "Enter the time when call started in 24-hour notation (hour:minute)\n";
            }

            cin >> hourStarted;
            cin.ignore(10,':');
            cin >> minStarted;

            counter++;

        }while(cin.fail());
        /////////////////////////////////////////////////////////////////////////////////////////////
        //Prompt fot the length of call
        counter = 0; //Reset counter

        do{
            if(counter > 0){
                cerr << "ERROR: incorrect input for length of call\nTry again\n";
                cin.clear(); cin.ignore(100,'\n');
            }
            else{
                cout << "Enter the length of call in min\n";
            }

            cin >> callDuration;

            counter++;

        }while(cin.fail());
        /////////////////////////////////////////////////////////////////////////////////////////////
        //Calculate the cost of this call

        //If the call was made on weekends then the rate = 0.15/min
        //If the call was made between Monday - Friday check on the time to verify the rate
        if(intDay >= 1 && intDay <=5){

            if(hourStarted >= 8 && hourStarted <= 18){
                rate = 0.40;
            }
            else{
                rate = 0.25;
            }

        }
        else if(intDay == 6 || intDay == 7){
            rate = 0.15;
        }

        cost = cost + rate * callDuration;

        cout << endl << "The cost for this call is: $" << rate * callDuration << endl;
        cout << "The total cost is for all the calls is: $" << cost <<endl <<endl;
        /////////////////////////////////////////////////////////////////////////////////////////////
        //Check if the user has inputted every calls
        //Repeat if not done
        cout << "Enter 1 if you are done\nPress any key and then enter to continue\n";
        cin >> done;
        if(done != 1){
            done = false;
            cin.clear(); cin.ignore(100,'\n');
        }
    }

    return 0;
}
