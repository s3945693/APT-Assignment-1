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

int Game::intPlayer(int x, int y, int z)
{
    Position pos(x,y);
    Player test = *player;
    cout<<"got here b4 if"<< endl;
    if(z == 0)
    {    
        test.initialisePlayer(&pos,NORTH);
    }
    else if(z == 1)
    {
        test.initialisePlayer(&pos,EAST);
    }
    else if(z == 2)
    {
        test.initialisePlayer(&pos,SOUTH);
    }
    else if(z == 3)
    {
        test.initialisePlayer(&pos,WEST);
    }
    
    cout<<"game IntPlayer complete"<<endl;
    Board b = *board;
    cout<< "attempting to place a player" << endl;
    b.placePlayer(pos);
    cout << "testing b.display" << endl;
    b.display(&test);
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