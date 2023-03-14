#include "game.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;

Game::Game()
{
    
    Board boardG;
    this->board = &boardG;
    Player player;
    this->player = &player;
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
    int bn;
    cout << "Please enter the board number to load: ";
    cin >> bn;
    this->board->load(bn);
    return true; // feel free to revise this line, depending on your implementation.
}

int Game::loadBoardNumber(int x)
{
    //TODO
    this->board->load(x);
    return 0; // feel free to revise this line, depending on your implementation.
}

void Game::intPlayer(int x, int y, int z)
{
    Position pos(x,y);
    Direction dir = NORTH;
    if(dir == NORTH){
        int s = 0;
        s++;
    }
    cout<<"got here"<< endl;
    if(z == 0)
    {
        this->player->initialisePlayer(&pos,NORTH);
    }
    else if(z == 1)
    {
        this->player->initialisePlayer(&pos,EAST);
    }
    else if(z == 2)
    {
        this->player->initialisePlayer(&pos,SOUTH);
    }
    else if(z == 3)
    {
        this->player->initialisePlayer(&pos,WEST);
    }
    
    cout<<"game IntPlayer"<<endl;
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