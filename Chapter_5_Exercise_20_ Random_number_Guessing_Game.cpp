/*
Filename: Chapter_5_Exercise_20_ Random_number_Guessing_Game.cpp
Programmer: Morgan Thorne
Date: April 2025
Requirements:
-generate a random number that asks user to guess what number it is
-if users guess is too hiht the program should respond with too high
-same for if the guess is too low
-Program should use a loop that repeats until the correct guess is answered.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

//Function Prototypes
bool Get_Repeat_Info();
int GetRandomNumber();
void Question_Answer_Validation(int Number);



int main()
{
   
    bool User_Repeat;

    do {

        
        
        int Number = GetRandomNumber();

        Question_Answer_Validation(Number);

        User_Repeat = Get_Repeat_Info();
    

    }    

    while (User_Repeat); {
        cout << "Thank you for using the program";
        return 0;
    }

}

//Allows user to choose whether they want to repeat program or end it
bool Get_Repeat_Info() {
    char choice;
    cout << "Would you like to repeat Y/N: ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}

//Creates random number from 0 - 1000
int GetRandomNumber() {
    random_device x;
    uniform_int_distribution<int> randomInt(0, 1000);

    int Number = randomInt(x);
    
    cout << "The number is has a range from 0 - 1000" << endl;

    return Number;
}

//Uses while loop to loop if incoreect and to terminate if the guess is correct
void Question_Answer_Validation(int Number) {
    int User_Guess;
    
    cout << "Guess the number: ";
    
    cin >> User_Guess;
    
    while (User_Guess != Number) {
        if (User_Guess < Number) {
            cout << "Too low! Enter: ";
        }
        else {
            cout << "Too high! Enter: ";
        }
        
        cin >> User_Guess;
        
        cout << endl;

    }
    cout << "Correct!" << endl;
}




