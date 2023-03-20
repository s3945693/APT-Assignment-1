#include "game.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;

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
    //delete player;
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
    //b4 initialising player, check if board position is empty

   // cout<<"got here b4 if"<< endl;
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
    
    //cout<<"game IntPlayer complete"<<endl;
    //cout<< "attempting to place a player" << endl;
    //cout <<  "in game.cpp intPlayer: this.board "<< this->board << endl;
    (*board).placePlayer(pos);
    //cout << "testing b.display" << endl;
    (*board).display(player);
    return 0;
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