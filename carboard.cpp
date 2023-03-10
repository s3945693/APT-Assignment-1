//#include "game.h"
//#include "helper.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::exit;

void showStudentInformation(){
    // TODO
    cout << "_ _ _ _ __ _ __ _ _ _ _ _ _ _ __ _ _ _ _ _  _  " << endl;
    cout << "Name: replace iwith name" << endl;
    cout << "No: REPLACE THIS WITH ID" << endl;
    cout << "Email: REPLACE THIS WITH EMAIL" << endl;
}

int mainMenu(){
    cout << "Welcome to Car Board" << endl;
    cout << "_ _ _ _ _ _ _ _ _ _ _" << endl;
    cout << "1. Play game" << endl;
    cout << "2. Show student's information" << endl;
    cout << "3. Exit" << endl;
    cout << "\nPlease enter your choice: ";
    int choice;
    cin >> choice;
    return choice;
}

void exit(){
    // TODO
    exit(0);
}
int main()
{
    /**
     * TODO: here's the main function. You can write the "main menu" loop/code
     * here or you can make separate functions - up to you.
     */
    int choice;
    choice = mainMenu();
    while (choice != 3){
        while ((choice > 3) && (choice < 1)){
            //todo
            cout << "Invalid choice. Please try again. " << endl;
            cin >> choice;
        }
        if (choice == 3){
            exit();
        };
        if (choice == 2){
            showStudentInformation();
            exit();
        }
        if (choice == 1){
            //Game game;
            //game.start();
            cout << "Game is not implemented yet" << endl;
            exit();
        }
    }
    std::cout << "Good bye!\n\n";

    return EXIT_SUCCESS;
}
