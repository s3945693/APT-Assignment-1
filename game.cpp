#include "game.h"
#include <iostream>
using  std::string;
using std::cout;
using std::endl;
using std::cin;

Game::Game()
{
    
    Board boardG;
    this->board = &boardG;
    Player player;

    cout << "You can use the following commands to play the game:" << endl;
    cout << "load <g>\n    g - number of gameboard to load" << endl;
    cout << "init <x>,<y>,<diretion>\n    x:horizontal position of the car on the board (between 0 & 9)" << endl;
    cout << "    y:vertical position of the car on the board (between 0 & 9)" << endl;
    cout << "    direction: direction of the car's movement (north, east, south, west)" << endl;
    cout << "forward (or f)" << endl;
    cout << "turn_left (or l)" << endl;
    cout << "turn_right (or r)" << endl;
    cout << "quit" << endl;
    boardG.pBoard();
    
}

Game::~Game()
{
    // TODO
}


void Game::start()
{
    //TODO
}

bool Game::loadBoard()
{
    //TODO
    
    return false; // feel free to revise this line, depending on your implementation.
}

int Game::loadBoardNumber(int x)
{
    //TODO
    this->board->load(x);
    return 0; // feel free to revise this line, depending on your implementation.
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