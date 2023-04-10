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
    cout << "You can use the following commands to play the game:\n" << endl;
    cout << "load <g>\n    g - number of gameboard to load" << endl;
    cout << "init <x>,<y>,<diretion>\n    x: horizontal position of the car on the board (between 0 & 9)" << endl;
    cout << "    y: vertical position of the car on the board (between 0 & 9)" << endl;
    cout << "    direction: direction of the car's movement (north, east, south, west)" << endl;
    cout << "generate <d>,<p>" << endl;
    cout << "    d: the dimension of the game board to be generated" << endl;
    cout << "    p: the probability of the blocks on board to be generated randomly" << endl;
    cout << "forward (or f)" << endl;
    cout << "turn_left (or l)" << endl;
    cout << "turn_right (or r)" << endl;
    cout << "quit\n" << endl;
    board->pBoard();
    cout<< endl;
    
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
    cout << "\nEnter a command: " << endl;
    cout << " enter forward (or f)\n" <<" turn_left (or l)" << endl;
    cout << " turn_right (or r)\n"<<" quit" << endl;
    getline(cin, gamer);
    while (gamer != "quit"){
        if (gamer == "forward" || gamer == "turn_left" || gamer == "turn_right " || gamer == "r" || gamer == "l" || gamer == "f"){
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
            cout << endl;
            (*board).display(player);
            
            cout << "\nEnter a command: " << endl;
            cout << " enter forward (or f)\n" <<" turn_left (or l)" << endl;
            cout << " turn_right (or r)\n"<<" quit" << endl;
            getline(cin, gamer);
            
        }
        else{
            cout << "\nInvalid command.\n" << endl;
            (*board).display(player);
            
            cout << "\nEnter a command: ";
            cout << " enter forward of (f)\n" <<" turn_left (or l)" << endl;
            cout << " turn_right (or r)\n"<<" quit" << endl;
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

int Game::intPlayer(int x, int y, Direction z)
{
    Position pos(x,y);
    bool playerSet = false;
    if(z == NORTH)
    {    
        (*player).initialisePlayer(&pos,NORTH);
        playerSet = true;
    }
    else if(z == EAST)
    {
        (*player).initialisePlayer(&pos,EAST);
        playerSet = true;
    }
    else if(z == SOUTH)
    {
        (*player).initialisePlayer(&pos,SOUTH);
        playerSet = true;
    }
    else if(z == WEST)
    {
        (*player).initialisePlayer(&pos,WEST);
        playerSet = true;
    }

    if (playerSet){
        (*board).placePlayer(pos);
        (*board).display(player);
        
    }
    return playerSet;
    
}



void Game::initPlayerLoop(string& command){
    bool firstLoad = false;
    cout << "Select either:" << endl;
    cout << " load <g>" << endl;
    if (firstLoad){
        cout << " init <x>,<y>,<direction>" << endl;
        cout << " generate <d>,<p> " << endl;
    }
    cout << " quit" << endl;
    cout << "Enter your choice: ";
    string startPos;
    getline(cin, command);
    if (std::cin.eof()==1) {
        std::cin.clear();
        std::cin.ignore();
        exit(0);
    }
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
                        firstLoad = true;
                        //cout <<"got here" <<endl;
                        //valid1 = false;
                    }
                }
            }
            if (firstLoad){
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
                                        //cout << "y was: " << y << endl;
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

                            int x = stoi(startPosVec[0]);
                            int y = stoi(startPosVec[1]);
                            string direction = startPosVec[2];
                            ///*
                            if (board->placePlayer(Position(x,y)) == true){
                                bool playerSet = false;
                                if (direction == "north"){
                                    // check if valid position for board due to out of bounds
                                    intPlayer(x,y,NORTH);
                                    playerSet = true;
                                }
                                if (direction == "eest"){
                                    intPlayer(x,y,EAST);
                                    playerSet = true;
                                }
                                if (direction == "south"){
                                    intPlayer(x,y,SOUTH);
                                    playerSet = true;
                                }
                                if (direction == "west"){
                                    intPlayer(x,y,WEST);
                                    playerSet = true;
                                }
                                if (playerSet){
                                    valid1 = false;
                                    valid2 = true;
                                }
                            }
                                
                        }
                    }
                }
            }

        }
        
        if (valid1 == true){

            if (valid2 == false){
                cout << "Invalid command.\n" << endl;
                displayNoPlayer();
                
            }
            
            cout << endl;
            cout << "Select either:" << endl;
            cout << " load <g>" << endl;

            if (firstLoad){
                cout << " init <x>,<y>,<direction>" << endl;
                cout << " generate <d>,<p>" << endl;
            }

            cout << " quit" << endl;
            cout << "Enter your choice: ";
            getline(cin, command);
            if (std::cin.eof()==1) {
                std::cin.clear();
                std::cin.ignore();
                exit(0);
            }
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