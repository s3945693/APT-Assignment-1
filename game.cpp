#include "game.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::exit;
using std::vector;
using std::getline;

Game::Game()
{
    board = new Board();
    
    player = new Player();
    //cout << "this is this.board in game: " <<this->board << endl;
    cout << "You can use the following commands to play the game:" << endl;
    cout << "load <g>\n    g - number of gameboard to load" << endl;
    cout << "init <x>,<y>,<diretion>\n    x:horizontal position of the car on the board (between 0 & 9)" << endl;
    cout << "    y:vertical position of the car on the board (between 0 & 9)" << endl;
    cout << "    direction: direction of the car's movement (north, east, south, west)" << endl;
    cout << "forward (or f)" << endl;
    cout << "turn_left (or l)" << endl;
    cout << "turn_right (or r)" << endl;
    cout << "quit" << endl;
    board->pBoard();
    
}

Game::~Game()
{
    //board->~Board();
    delete board;
    delete player;
}


void Game::start()
{
    //TODO
    string gamer;
    cout << "enter forward, turn_left, turn_right, r, l, or quit: ";
    getline(cin, gamer);
    while (gamer != "quit"){
        if (gamer == "forward" || gamer == "turn_left" || gamer == "turn_right " || gamer == "r" || gamer == "l"){
            if (gamer == "turn_left" || gamer == "l"){
                //cout << "should turn left" << endl;
                (*player).turnDirection(TURN_LEFT);
            }
            else if (gamer == "turn_right" || gamer == "r"){
                //cout << "should turn right" << endl;
                (*player).turnDirection(TURN_RIGHT);
            }
            else if (gamer == "forward" || gamer == "f"){
                //cout <<"go forword" << endl;
                (*board).movePlayerForward(player);
            }
            (*board).display(player);
            
            cout << "enter next command: ";
            getline(cin, gamer);
            
        }
        else{
            cout << "Invalid command. Please enter a valid command: ";
            getline(cin, gamer);
        }
    }
}

bool Game::loadBoard()
{
    //TODO
    int bn;
    cout << "Please enter the board number to load: ";
    cin >> bn;
    this->board->load(bn);
    return true; // feel free to revise this line, depending on your implementation.
}

void Game::loadBoardNumber(int x)
{
    //TODO
    this->board->load(x);
     // feel free to revise this line, depending on your implementation.
}

int Game::intPlayer(int x, int y, int z)
{
    Position pos(x,y);

    if(z == 0)
    {    
        (*player).initialisePlayer(&pos,NORTH);
    }
    else if(z == 1)
    {
        (*player).initialisePlayer(&pos,EAST);
    }
    else if(z == 2)
    {
        (*player).initialisePlayer(&pos,SOUTH);
    }
    else if(z == 3)
    {
        (*player).initialisePlayer(&pos,WEST);
    }

    (*board).placePlayer(pos);
    //cout << "testing b.display" << endl;
    (*board).display(player);
    return 0;
}

void Game::loadBoardLoop(string& command){
    cout << "Select to load<g> or quit the game: ";
    getline(cin, command);
    //cout <<"made it here" << endl;
    cout << endl;

    vector<string> loadVector;
    
    Helper::splitString(command, loadVector, " ");
    bool valid = true;
    while (valid){
        if (loadVector.size() == 1){
            if (loadVector[0] == "quit"){
                valid = false;
                command = "quit";
            }
        }
        
        else if (loadVector.size() == 2){
            if (loadVector[0] == "load"){
                if (Helper::isNumber(loadVector[1])){
                    if (stoi(loadVector[1]) == 1 || stoi(loadVector[1]) == 2){
                        valid = false;
                        loadBoardNumber(stoi(loadVector[1]));
                        cout << endl;
                    }
                }
            }
        }
        if (valid == true){

            Game::displayVoidBoard();
            cout << "\nInvalid command. Select to load<g> or quit the game: ";
            getline(cin, command);
            cout << endl;
            Helper::splitString(command, loadVector, " ");
        }
    }
}

void Game::initPlayerLoop(string& command){
    
    cout << "Select either:" << endl;
    cout << "1. Load <g>" << endl;
    cout << "2. Init <x>,<y>,<direction>" << endl;
    cout << "3. Generate " << endl;
    cout << "3. Quit" << endl;
    cout << "Enter your choice: ";
    string startPos;
    getline(cin, command);
    cout << endl;
    vector<string> startPosVec;                    
    ///*
    Helper::splitString(command, startPosVec, " ");
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
                        loadBoardNumber(stoi(startPosVec[1]));
                        valid2 = true;
                        //cout <<"got here" <<endl;
                        //valid1 = false;
                    }
                }
            }
            if (startPosVec[0] == "generate"){
                Helper::splitString(startPosVec[1], startPosVec, ",");
                if (startPosVec.size() == 2){
                    if (Helper::isNumber(startPosVec[0])){
                        int x = stoi(startPosVec[0]);
                        if (x <= 20 && x >= 10){
                            string temp = startPosVec[1];
                            Helper::splitString(startPosVec[1], startPosVec, ".");
                            if(startPosVec.size() == 2){
                                if (startPosVec[0] == "0" && Helper::isNumber(startPosVec[0]) && Helper::isNumber(startPosVec[1])){
                                    double y = stod(temp);
                                    cout << "y was: " << y << endl;
                                    //we create a parse in a create board.
                                    board->resizeBoard(x,y);
                                    //valid1 = false;
                                    valid2 = true;
                                }
                            }
                        }

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
                            if (board->placePlayer(Position(x,y)) == true){
                                
                                if (direction == "N"){
                                    // check if valid position for board due to out of bounds
                                    intPlayer(x,y,0);
                                    
                                }
                                if (direction == "E"){
                                    intPlayer(x,y,1);
                                }
                                if (direction == "S"){
                                    intPlayer(x,y,2);
                                }
                                if (direction == "W"){
                                    intPlayer(x,y,3);
                                }
                                valid1 = false;
                                valid2 = true;
                            }
                            
                        }
                    }
                }
            }

        }
        
        if (valid1 == true){

            if (valid2 == false){
            cout << "\nInvalid command.\n";
            }
            cout << endl;
            if (valid2 == false){
            displayNoPlayer();
            }
            cout << "Select either:" << endl;
            cout << "1. Load <g>" << endl;
            cout << "2. Init <x>,<y>,<direction>" << endl;
            cout << "3. Generate " << endl;
            cout << "3. Quit" << endl;
            cout << "Enter your choice: ";
            getline(cin, command);
            cout << endl;
            Helper::splitString(command, startPosVec, " ");
            valid2 = false;
        }
    }
}

int Game::getPlayerMoves(){
    return player->moves;
}

bool Game::initializePlayer()
{
    //TODO
    return false; // feel free to revise this line.
}

void Game::play()
{
    //TODO

}

void Game::displayNoPlayer()
{
    //TODO
    this->board->pBoardNoPlayer();
}

void Game::displayVoidBoard()
{
    //TODO
    this->board->pBoard();
}