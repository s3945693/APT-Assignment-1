#include "player.h"
#include <iostream>
using std::cout;
using std::string;
using std::endl;
Position::Position()
{
    //TODO
}


Position::Position(int x, int y)
{
    //TODO
    this->x = x;
    this->y = y;
}

Player::Player()
{
    //TODO
}

void Player::initialisePlayer(Position* position, Direction direction)
{
    //TODO
    this->position = *position;
    this->direction = direction;
    cout << "Player initialised at position (" << this->position.x << "," << this->position.y << ") facing " << this->direction << endl;
}

void Player::turnDirection(TurnDirection turnDirection)
{
    //TODO
}

Position Player::getNextForwardPosition()
{
    //TODO

    return this->position;
}

void Player::updatePosition(Position position)
{
    //TODO
}

void Player::displayDirection()
{
    //TODO
}
