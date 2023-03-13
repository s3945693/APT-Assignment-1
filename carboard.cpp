#include "game.h"
#include "helper.h"
#include "board.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::exit;

void showStudentInformation();
int mainMenu();
void exit();
void printBlock();

int main()
{
    /**
     * TODO: here's the main function. You can write the "main menu" loop/code
     * here or you can make separate functions - up to you.
     */
    cout << "Welcome to Car Board" << endl;
    cout << "_ _ _ _ _ _ _ _ _ _ _\n" << endl;
    cout << "1. Play game" << endl;
    cout << "2. Show student's information" << endl;
    cout << "3. Exit" << endl;
    int choice;
    choice = mainMenu();
    int* choicePtr = &choice;
    while (*choicePtr != 3){
        while ((*choicePtr > 3) || (*choicePtr < 1)){
                //todo
                cout << "Invalid choice. Please try again. ";
                cin >> *choicePtr;
        }
        if (*choicePtr == 2){
                showStudentInformation();
                //exit();
        }
        if (*choicePtr == 1){
                //Game game;
                //game.start();
                cout << "Game is not implemented yet\n" << endl;
                //exit();
        }
        *choicePtr = mainMenu();
    }
    //Board board;
    //board.pBoard();
    return EXIT_SUCCESS;
}

void showStudentInformation(){
    // TODO
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    cout << "Name: replace iwith name" << endl;
    cout << "No: REPLACE THIS WITH ID" << endl;
    cout << "Email: REPLACE THIS WITH EMAIL" << endl;
}

int mainMenu(){
    cout << "_ _ _ _ _ _ _ _ _ _ _\n" << endl;
    cout << "\nPlease enter your choice: ";
    int choice;
    cin >> choice;
    return choice;
}

void exit(){
    // TODO
    exit(0);
}

void printBlock(){
    cout << "You can use the commands to play the game" << endl;
    cout << "load <g>" << endl;
    cout << " g: number of teh game board ro load" << endl;
    cout << "init <x>,<y> <direction>" << endl;
    cout << " x: horizontal position of the car btwn 0-9" << endl;
    cout << " y: vertical position of the car btwn 0-9" << endl;
    cout << " direction: direction of the car (N, S, E, W)" << endl;
    cout << "forward (or f)" << endl;
    cout << "turn left (or l)" << endl;
    cout << "turn right (or r)" << endl;
    cout << "quit (or q)" << endl;
}
