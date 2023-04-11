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

/*
 * I create a while loop for the main menu which checks for valid input and based on 
 * input will either start the game or show student information or quit the game.
 * If the player chooses 2 it will show studnt information, this is done by calling a method.
 * If the player chooses 1 it will start the game, this is done by calling initialising the game
 * class, which will then call the initPlayerLoop method, and 
 * then based on user input and validation the game will start by calling game.start().
 * The initplayer loop contains the game main menu logic. such as the commands
 * for loading the board.
 * For any input I separate the values by whitespace using splitstring
 * and check if it contains a valid command in the first index of the vector.
 * If it does I then check if size of the vector (2) is right for the command.
 * and then check if the values are valid. For commands like init, I split the
 * other index by commas and check if the size is right and if the values are valid.
 * It everything is right I call upon the command functions.
 * 
 * for load I call upon the loadBoardnumber which loads the desginated board.
 * for init i call the intPlayer, which assigns coordinates and direction to the player
 * and assigns the board with a player in the designated coordinates. 
 * for generate I call the generateBoard method which generates a board with random blocks.
 * when the user succesfully enteres init, the game starts. The game logic is within game.start()
 * Within this I again check for valid input and then proceed to display the right information
 * based on player input.
 * 
 * Issues I encountered.
 * while testing the board for printing i wanted to include different text, solve this
 * by baking a string variant of the board and then printing that.
 * Input validation was another problem I didn't know how to solve, how I eventaully solved it 
 * was by utilizing the splitstring method and checking if indexes are right.
 * I also didnt undestand how to utilize some of private methods as intended, 
 * so i just create public variants to solve this.
 * 
 * Potential improvements to startup code. 
 * Check for end of file error in get line. 
 * change some of the private methods to public.
 * Include methods for main menu text and student information text.
 * 
*/ 
//will show student information
void showStudentInformation();

//will show the main menu and ensure valid input
int mainMenu();
void exit();

//g++ -Wall -Werror -std=c++14 -O -o test board.cpp carboard.cpp game.cpp helper.cpp player.cpp
// ./test

int main()
{

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

                cout << "\nTotal player moves: " << game.getPlayerMoves() << endl;
                
                //cout << "end of init" << endl;
                command = "quit";
            }

        }
        choice = mainMenu();
    }

    cout <<"Goodbye!"<<endl;
    return EXIT_SUCCESS;
}

void showStudentInformation(){
    // TODO
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    cout << "Name: Brendon Rodrigues" << endl;
    cout << "No: s3945693" << endl;
    cout << "Email: s3945693@student.rmit.edu.au" << endl;
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
}



int mainMenu(){
    string inp;
    bool firstTime = true;
    while (inp.length() != 1 || isdigit(inp[0]) == false) {
        if (!firstTime){
            cout << "\nInvalid input.\n";
        }
        cout<<endl;
        cout << "Welcome to Car Board" << endl;
        cout << "_ _ _ _ _ _ _ _ _ _ _" << endl;
        cout << "1. Play game" << endl;
        cout << "2. Show student information" << endl;
        cout << "3. Exit" << endl;
        cout << "_ _ _ _ _ _ _ _ _ _ _\n" << endl;
        cout << "Please enter your choice: ";
        Helper::readInput(inp);
        firstTime = false;
    }
    int choice = stoi(inp);
    //cout << "returning value" << endl;
    return choice;
}


void exit(){
    // TODO
    exit(0);
}


