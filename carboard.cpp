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
void intPlayer(string t, vector<string>& s);

string mainMenuCheck();
//g++ -Wall -Werror -std=c++14 -O -o test board.cpp carboard.cpp game.cpp helper.cpp player.cpp
// ./test

int main()
{
    /**
     * TODO: here's the main function. You can write the "main menu" loop/code
     * here or you can make separate functions - up to you.
     */
        // choice becomes a string
    // check if lenght of choice is > 1, if so, then it is invalid
    // if lenght of choice is 1, then check if it is an int and if it is 1, 2, or 3
    // continue

    int choice;
    choice = mainMenu();
   
    //cout<<"before main while loop"  << endl;
    while (choice != 3){
        //cout << "in main while loop" << endl;
        if (choice == 2){
                showStudentInformation();
                //exit();
        }
        if (choice == 1){
                Game game;

                cout << endl;
                string command;
                cout << "Select to load a board or quit the game: ";
                cin >> command;
                cout << endl;
                //ensuring command is valid
                while (command != "q" && command != "quit" && command != "load" && command != "g"){
                    cout << "Invalid command. Please enter a valid command: ";
                    cin >> command;
                    cout << endl;
                }
                if (command == "load" || command == "g"){
                    cout << "Please select a board number (1 or 2): ";
                    string bNumber = mainMenuCheck();
                    int boardNumber = stoi(bNumber);

                    //ensuring board number is valid
                    while (boardNumber != 1 && boardNumber != 2){
                        cout << "Invalid board number. Please enter a valid board number: ";
                        bNumber = mainMenuCheck();
                        boardNumber = stoi(bNumber);
                    }

                    //loading board
                    game.loadBoardNumber(boardNumber);
                    cout << endl;

                    //initializing player
                    cout << "Please select a starting position using init <x>,<y>,<direction> command: ";
                    string startPos;
                    cin >> startPos;
                    cout << endl;
                    vector<string> startPosVec;                    
                    ///*
                    intPlayer(startPos, startPosVec);
                    //*/

                    int x = stoi(startPosVec[0]);
                    int y = stoi(startPosVec[1]);
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
                    //game.~Game();
                }
                else if (command == "quit" || command == "q"){
                    exit();
                }

        }
        choice = mainMenu();
    }

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
    cout << "Please enter your choice: ";
    int choice = stoi(mainMenuCheck());
    while (choice >3 || choice <1){
        cout << "Invalid choice. Please try again. ";
        choice = stoi(mainMenuCheck());
    }
    return choice;
}

string mainMenuCheck(){
    string inp;
    cin >> inp;
    while (inp.length() != 1 || isdigit(inp[0]) == false) {
        cout << "Invalid choice. Please try again: ";
        cin >> inp;
    }
    //cout << "returning value" << endl;
    return inp;
}

void intPlayer(string x, vector<string>& s){
    // TODO
    Helper::splitString(x,s,",");
    //cout <<"b4 while loop x: "<< s[0] << ". y: " << s[1] << ". direction: " << s[2] << endl;

    while(Helper::isNumber(s[0]) == false || Helper::isNumber(s[1]) == false){
            
            //cout << "x was: " << s[0] << ". y was: " << s[1] << " direction was: " << s[2] << endl;
            //cout << "x was: " << Helper::isNumber(s[0]) << ". y was: " << Helper::isNumber(s[1]) << " direction was: " << s[2] << endl;
            cout << "Invalid starting position. Please enter a valid starting position x or y: ";
            cin >> x;
            cout << endl;
            Helper::splitString(x,s,",");
    }

    while (s[2] != "N" && s[2] != "E" && s[2] != "S" && s[2] != "W"){
        cout << "the direction entered was false: " << s[2] << endl;
        cout << "Invalid starting position. Please enter a valid starting position direction: ";
        cin >> s[2];
        cout << endl;
    }

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
