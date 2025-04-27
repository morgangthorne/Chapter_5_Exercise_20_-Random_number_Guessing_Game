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
#include <string>

using namespace std;

//Function Prototypes
bool Get_Repeat_Info();
int GetRandomNumber();
int Question_Answer_Validation(int Number);
void Display_Sessions();
void Delete_Sessions();
void Show_Menu();



int main()
{
    int Menu_Choice;

    bool User_Repeat = false;

    while (!User_Repeat) {

        Show_Menu();
        cin >> Menu_Choice;
        cin.ignore();

        switch (Menu_Choice) {
        case 1: {
            Display_Sessions();
            break;
        }

        case 2: {
            string Player_Name;
            cout << "Enter your name: ";
            getline(cin, Player_Name);

            int Number = GetRandomNumber();
            int Attempts = Question_Answer_Validation(Number);

            ofstream outFile("sessions.txt", ios::app);
            if (outFile.is_open()) {
                outFile << Player_Name << " guessed correctly in " << Attempts << " attempts." << endl;
                outFile.close();
                cout << "Session saved!\n";
            }
            else {
                cout << "Error: Could not save session.\n";
            }
            break;
        }
        case 3: {
            Delete_Sessions();
            break;
        }
        case 4: {
            User_Repeat = true;
            cout << "Thank you for using the program." << endl;
            break;
        }

        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }





    }
}

void Show_Menu() {
    cout << "\n--- MAIN MENU ---" << endl;
    cout << "1. Display Existing Sessions" << endl;
    cout << "2. Play a New Session" << endl;
    cout << "3. Delete Previous Sessions" << endl;
    cout << "4. Exit the Program" << endl;
    cout << "Enter your choice: ";
}

//Allows user to choose whether they want to repeat program or end it
bool Get_Repeat_Info() {
    char choice;
    cout << "Would you like to repeat Y/N: ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}

//
int GetRandomNumber() {
    random_device x;
    uniform_int_distribution<int> randomInt(0, 1000);

    int Number = randomInt(x);
    
    cout << "The number is has a range from 0 - 1000" << endl;

    return Number;
}

int Question_Answer_Validation(int Number) {
    int User_Guess;
    int Attempts = 0;

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
        
        Attempts++;

        cout << endl;

    }
    cout << "Correct!" << endl;

    return Attempts;
}

void Display_Sessions() {
    ifstream inFile("sessions.txt");

    if (!inFile) {
        cout << "No sessions found.\n";
        return;
    }

    string line;
    cout << "\n--- Previous Sessions ---" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

// Clear all session records
void Delete_Sessions() {
    ofstream outFile("sessions.txt", ios::trunc);
    if (outFile.is_open()) {
        outFile.close();
        cout << "All sessions have been deleted.\n";
    }
    else {
        cout << "Error: Could not delete sessions.\n";
    }
}