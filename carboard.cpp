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
using std::getline;
//add eof error, init 9,9 just doiestn work, implement f for forward

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
            string command = " ";

            while (command != "quit"){
                
                Game game;
                
     
                
                game.initPlayerLoop(command);
                
         
                if (command != "quit"){
                    game.start();
                }
                cout << "Player moves: " << game.getPlayerMoves() << endl;
                //cout << "end of init" << endl;
                command = "quit";
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
    cout << "Name: Brendon Rodrigues" << endl;
    cout << "No: s3945693" << endl;
    cout << "Email: s3945693@student.rmit.edu.au" << endl;
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
        cout << "\nInvalid choice. Please try again. \n";
        cout<<endl;
        cout << "Welcome to Car Board" << endl;
        cout << "_ _ _ _ _ _ _ _ _ _ _" << endl;
        cout << "1. Play game" << endl;
        cout << "2. Show student's information" << endl;
        cout << "3. Exit" << endl;
        cout << "_ _ _ _ _ _ _ _ _ _ _\n" << endl;
        cout << "Please enter your choice: ";
        choice = stoi(mainMenuCheck());
    }
    return choice;
}

string mainMenuCheck(){
    string inp;
    getline(cin, inp);
    while (inp.length() != 1 || isdigit(inp[0]) == false) {
        cout << "\nInvalid choice. Please try again: \n";
        cout<<endl;
        cout << "Welcome to Car Board" << endl;
        cout << "_ _ _ _ _ _ _ _ _ _ _" << endl;
        cout << "1. Play game" << endl;
        cout << "2. Show student's information" << endl;
        cout << "3. Exit" << endl;
        cout << "_ _ _ _ _ _ _ _ _ _ _\n" << endl;
        cout << "Please enter your choice: ";
        getline(cin, inp);
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
