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

                cout << "\nHit enter to continue." << endl;
                cin.clear();
                cin.ignore(10000,'\n');

                cout << "Select to load<g> or quit the game: ";
                getline(cin, command);
                //cout <<"made it here" << endl;
                cout << endl;
                //ensuring command is valid
                //cout<< "command was: " <<command<<endl;
                //cout<<"shouldve printed command" << endl;
                vector<string> loadVector;
                
                Helper::splitString(command, loadVector, " ");
                //cout << "splitString worked" << endl;
                bool valid = true;
                while (valid){
                    //cout<< "command was: " <<command<<endl;
                    if (loadVector.size() == 1){
                        //cout<< "size 1 command was: " <<command<<endl;
                        if (loadVector[0] == "quit"){
                            valid = false;
                            command = "quit";
                        }
                    }
                    
                    else if (loadVector.size() == 2){
                        //cout<< "size 2 command was: " <<command<<endl;
                        if (loadVector[0] == "load"){
                            if (Helper::isNumber(loadVector[1])){
                                //cout << "made it into isNumber" << endl;
                                //cout << "loadVector[1] was: " << loadVector[1] <<"d" << endl;
                                if (stoi(loadVector[1]) == 1 || stoi(loadVector[1]) == 2){
                                    //cout << "made it into stoi" << endl;
                                    valid = false;
                                    game.loadBoardNumber(stoi(loadVector[1]));
                                    cout << endl;
                                }
                            }
                        }
                    }
                    if (valid == true){

                        game.displayVoidBoard();
                        cout << "\nInvalid command. Select to load<g> or quit the game: ";
                        getline(cin, command);
                        cout << endl;
                        Helper::splitString(command, loadVector, " ");
                    }
                }
                //cout << "out of while loop" << endl;
                //cout << "command was: " <<command<<endl;
                if (command != "quit"){
        
                    //initializing player
                    cout << "Hit enter to continue." << endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout << "Select either:" << endl;
                    cout << "1. Load <g>" << endl;
                    cout << "2. Init <x>,<y>,<direction>" << endl;
                    cout << "3. Quit" << endl;
                    cout << "Enter your choice: ";
                    string startPos;
                    getline(cin, startPos);
                    cout << endl;
                    vector<string> startPosVec;                    
                    ///*
                    Helper::splitString(startPos, startPosVec, " ");
                    //cout << "splitString worked" << endl;
                    bool valid1 = true;
                    bool valid2 = false;
                    while (valid1){
                        //cout<< "command was: " <<command<<endl;
                        if (startPosVec.size() == 1){
                            //cout<< "size 1 command was: " <<command<<endl;
                            if (startPosVec[0] == "quit"){
                                valid1 = false;
                                command = "quit";
                                valid2 = true;
                            }
                        }
                        
                        else if (startPosVec.size() == 2){
                            //cout<< "size 2 command was: " <<command<<endl;
                            if (startPosVec[0] == "load"){
                                if (Helper::isNumber(startPosVec[1])){
                                    //cout << "made it into isNumber" << endl;
                                    //cout << "loadVector[1] was: " << loadVector[1] <<"d" << endl;
                                    if (stoi(startPosVec[1]) == 1 || stoi(startPosVec[1]) == 2){
                                        //cout << "made it into stoi" << endl;

                                        //cout << "got here" <<endl;
                                        game.loadBoardNumber(stoi(startPosVec[1]));
                                        valid2 = true;
                                        //cout <<"got here" <<endl;
                                        //valid1 = false;
                                    }
                                }
                            }

                            if (startPosVec[0] == "init"){

                                Helper::splitString(startPosVec[1], startPosVec, ",");
                                if (startPosVec.size() == 3){
                                    if (Helper::isNumber(startPosVec[0]) && Helper::isNumber(startPosVec[1])){
                                        if (startPosVec[2] == "N" || startPosVec[2] == "E" || startPosVec[2] == "S" || startPosVec[2] == "W"){

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
                                            valid1 = false;
                                            valid2 = true;
                                        }
                                    }
                                }
                            }

                        }
                        
                        if (valid1 == true){

                            if (valid2 == false){
                            cout << "\nInvalid command.";
                            }
                            cout << endl;
                            if (valid2 == false){
                            game.displayNoPlayer();
                            }
                            cout << "Select either:" << endl;
                            cout << "1. Load <g>" << endl;
                            cout << "2. Init <x>,<y>,<direction>" << endl;
                            cout << "3. Quit" << endl;
                            cout << "Enter your choice: ";
                            getline(cin, startPos);
                            cout << endl;
                            Helper::splitString(startPos, startPosVec, " ");
                            valid2 = false;
                        }
                    }
                    //intPlayer(startPos, startPosVec);
                    //*/
                    if (command != "quit"){
                        
                        game.start();

                    }
                    cout << "end of init" << endl;
                    command = "quit";
                    //*/
                    //game.~Game();
                }
            
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
