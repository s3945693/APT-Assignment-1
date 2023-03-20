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
    //cout << "turnDirection" << turnDirection << endl;
    if (turnDirection == TURN_LEFT){
        //cout<< "turn left" << endl;
        if (this->direction == NORTH){
            this->direction = WEST;
        }
        else if (this->direction == WEST){
            this->direction = SOUTH;
        }
        else if (this->direction == SOUTH){
            this->direction = EAST;
        }
        else if (this->direction == EAST){
            this->direction = NORTH;
        }
    }
    else{
        //cout<< "turn right" << endl;
        if (this->direction == NORTH){
            this->direction = EAST;
        }
        else if (this->direction == EAST){
            this->direction = SOUTH;
        }
        else if (this->direction == SOUTH){
            this->direction = WEST;
        }
        else if (this->direction == WEST){
            this->direction = NORTH;
        }
    }
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
