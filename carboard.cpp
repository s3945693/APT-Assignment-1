#include "game.h"
#include "helper.h"
#include "board.h"
#include "helper.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::exit;
using std::vector;


void showStudentInformation();
int mainMenu();
void exit();
void printBlock();
//g++ -Wall -Werror -std=c++14 -O -o test board.cpp carboard.cpp game.cpp helper.cpp player.cpp
// ./test

int main()
{
    /**
     * TODO: here's the main function. You can write the "main menu" loop/code
     * here or you can make separate functions - up to you.
     */
    
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
                Game game;
                //exit();
                cout << endl;
                string command;
                cout << "Select to load a board or quit the game: ";
                cin >> command;
                cout << endl;
                if (command == "load" || command == "g"){
                    int boardNumber;
                    cout << "Enter the board number: ";
                    cin >> boardNumber;
                    cout << endl;
                    game.loadBoardNumber(boardNumber);
                    //game.start();
                    cout << endl;
                    cout << "Please select a starting position using init <x>,<y>,<direction> command: ";
                    string startPos;
                    cin >> startPos;
                    cout << endl;

                    
                    vector<string> startPosVec;
                    Helper::splitString(startPos,startPosVec,",");
                    int x = stoi(startPosVec[0]);
                    int y = stoi(startPosVec[1]);
                    x+=1;
                    x-=1;
                    y+=1;
                    y-=1;
                    string direction = startPosVec[2];
                    ///*
                    if (direction == "N"){
                        game.intPlayer(x,y,0);
                        cout<< "made it into init" << endl;
                    }
                    if (direction == "E"){
                        game.intPlayer(x,y,1);
                    }
                    if (direction == "S"){
                        game.intPlayer(x,y,2);
                    }
                    if (direction == "W"){
                        game.intPlayer(x,y,3);
                    }
                    //*/
                }
        }
        *choicePtr = mainMenu();
    }
    //Board board;
    //board.load(1);
    //board.pBoard();

    cout <<"Exiting..."<<endl;
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
    cout<<endl;
    cout << "Welcome to Car Board" << endl;
    cout << "_ _ _ _ _ _ _ _ _ _ _" << endl;
    cout << "1. Play game" << endl;
    cout << "2. Show student's information" << endl;
    cout << "3. Exit" << endl;
    cout << "_ _ _ _ _ _ _ _ _ _ _\n" << endl;
    cout << "\nPlease enter your choice: ";
    int choice;
    cin >> choice;
    cout <<endl;
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
