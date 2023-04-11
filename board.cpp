#include "board.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::exit;
using std::vector;

const vector<vector<Cell>> Board::BOARD_1 =
{
    { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

const vector<vector<Cell>> Board::BOARD_2 =
{
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

Board::Board()
{
    // TODO
    
    boardDimension = new int(11);
    board = new vector<vector<Cell>>(*boardDimension, vector<Cell>(*boardDimension, EMPTY));
    //cout << "This is boardGame ref in class::board init: "<< board << endl;
    //cout << this->board << endl;
    for (int i = 0; i<*boardDimension; i++) {
        for (int j = 0; j<*boardDimension; j++) {
            
            //boardGame[i][j] = emp;
            if (i == 0 && j == 0){
                (*board)[i][j] = BLOCKED;
            }
            else if (i == 0) {
                (*board)[i][j] = BLOCKED;
            }
            else if (i!= 0 && j == 0) {
                (*board)[i][j] = BLOCKED;
            }
            else {
                (*board)[i][j] = EMPTY;
            }
            //cout << (*board)[i][j] << " ";
        }
        //cout << endl;
    }
}

Board::~Board()
{
    delete board;
    delete boardDimension;
}

void Board::resizeBoard(int row, double prob) {

    //deleteing previous board and boardDimension
    delete board;
    delete boardDimension;

    //creating new board and boardDimension based on the value row
    boardDimension = new int(row+1);
    board = new vector<vector<Cell>>(*boardDimension, vector<Cell>(*boardDimension, EMPTY));

    //math for how many roadblocks to assign
    int randomCells = (row*row)*prob;

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, row); // define the range
    //cout << "got here " << endl;

    //assigning roadblocks randomly
    for(int n=randomCells; n>0; n--){
        int i = distr(gen);
        int j = distr(gen);
        //cout<< "N: " << n << endl;
        //cout << "i: " << i << " j: " << j << endl;
        
        // if road was already blocked, repeat the loop value again
        if ((*board)[i][j] == BLOCKED){
            n++;
        }

        (*board)[i][j] = BLOCKED;
    }
        
    //printing a board with no player
    pBoard();

}

void Board::load(int boardId)
{
    // deleting previous board and boardDimension
    delete board;
    delete boardDimension;

    // creating new board and boardDimension 
    boardDimension = new int(11);
    board = new vector<vector<Cell>>(*boardDimension, vector<Cell>(*boardDimension, EMPTY));
    string boardGameStr[*boardDimension][*boardDimension] = { " " };
    
    //ensuring the number rows/columns cant be accessed by car
    for (int i = 0; i<*boardDimension; i++){
        for (int j = 0; j<1; j++){
            (*board)[i][j] = BLOCKED;
        }
    }
    for (int i = 0; i <1; i++){
        for (int j = 0; j<*boardDimension; j++){
            (*board)[i][j] = BLOCKED;
        }
    }

    //assigning roadblocks based on boardId
    for (int i =1; i<*boardDimension; i++) {
        for (int j = 1; j<*boardDimension; j++) {
            if (boardId == 1) {
                if (BOARD_1[i-1][j-1] == BLOCKED) {
                    boardGameStr[i][j] = "*|";

                    (*board)[i][j] = BLOCKED;
                }
                else {
                boardGameStr[i][j] = " |";
                }
                
            }
            else if (boardId == 2) {
                if (BOARD_2[i-1][j-1] == BLOCKED) {
                    boardGameStr[i][j] = "*|";
                    (*board)[i][j] = BLOCKED;
                }
                else {
                boardGameStr[i][j] = " |";
                }
            
            }
            else {
                cout << "Invalid board ID" << endl;
                //exit(1);
            }
         
        }

    }
    //printing a board with no player
    pBoard();

}

bool Board::placePlayer(Position position)
{
    
    bool toReturn;
    //checking if given position is within dimensions of the board
    if (position.x >0 && position.x <*boardDimension && position.y >0 && position.y <*boardDimension) {
        if ((*board)[position.x][position.y] == BLOCKED) {
            cout << "Can't place player here." << endl;
            toReturn = false;
        }
        else {
            (*board)[position.x][position.y] = PLAYER;
            toReturn = true;
        }
    }
    //if position is out of bounds
    else {
        cout << "Out of bounds area." << endl;
        toReturn = false;
    }
    return toReturn;
}

PlayerMove Board::movePlayerForward(Player* player)
{
    /*
     * checking if the player is at the edge of the board or if the road is blocked
     * if not the player is moved forward
     * applies to all directions
    */
    if (player->direction == EAST){
        if (player->position.y+1 >*boardDimension-1){
            cout << "\nThe car is at the edge of the board and cannot move further in that direction" << endl;
        }

        else if ((*board)[player->position.x][player->position.y+1] == BLOCKED) {
            cout << "\nCannot move forward as road is blocked" << endl;
        }

        else {
            (*board)[player->position.x][player->position.y+1] = PLAYER;
            (*board)[player->position.x][player->position.y] = EMPTY;
            player->position.y = player->position.y+1;
            player->moves++;
        }
    }
    else if (player->direction == WEST){
        if (player->position.y-1 <1){
            cout << "\nThe car is at the edge of the board and cannot move further in that direction" << endl;
        }
        else if ((*board)[player->position.x][player->position.y-1] == BLOCKED) {
            cout << "\nCannot move forward as road is blocked" << endl;
        }
        else {
            (*board)[player->position.x][player->position.y-1] = PLAYER;
            (*board)[player->position.x][player->position.y] = EMPTY;
            player->position.y = player->position.y-1;
            player->moves++;
        }
    }
    else if (player->direction == SOUTH){
        //cout <<"this is executing: " << player->position.x+1 << endl;
        if (player->position.x+1 >*boardDimension-1){
            cout << "\nThe car is at the edge of the board and cannot move further in that direction" << endl;
        }
        else if ((*board)[player->position.x+1][player->position.y] == BLOCKED) {
            cout << "\nCannot move forward as road is blocked" << endl;
        }

        else {
            (*board)[player->position.x+1][player->position.y] = PLAYER;
            (*board)[player->position.x][player->position.y] = EMPTY;
            player->position.x = player->position.x+1;
            player->moves++;
            
        }
    }
    else if (player->direction == NORTH){
        if (player->position.x-1 <1){
            cout << "\nThe car is at the edge of the board and cannot move further in that direction" << endl;
        }
        else if ((*board)[player->position.x-1][player->position.y] == BLOCKED) {
            cout << "\nCannot move forward as road is blocked" << endl;
        }
        else {
            (*board)[player->position.x-1][player->position.y] = PLAYER;
            (*board)[player->position.x][player->position.y] = EMPTY;
            player->position.x = player->position.x-1;
            player->moves++;
        }
    }

    return PLAYER_MOVED;
}

void Board::display(Player* player)
{
    // TODO
    string boardGameStr[*boardDimension][*boardDimension] = { " " };
   
    for (int i =1; i<*boardDimension; i++) {
        for (int j = 1; j<*boardDimension; j++) {
                
                if ((*board)[i][j] == BLOCKED) {
                    boardGameStr[i][j] = "*|";
                    //next line creates a seg fault
                    //this->board->at(i).at(j) = BLOCKED;
                }
                else if ((*board)[i][j] == PLAYER) {

                    //boardGameStr[i][j] = "P|";
                    if (player->direction == NORTH) {
                        boardGameStr[i][j] = DIRECTION_ARROW_OUTPUT_NORTH;
                    }
                    else if (player->direction == SOUTH) {
                        boardGameStr[i][j] = DIRECTION_ARROW_OUTPUT_SOUTH;
                    }
                    else if (player->direction == EAST) {
                        boardGameStr[i][j] = DIRECTION_ARROW_OUTPUT_EAST;
                    }
                    else if (player->direction == WEST) {
                        boardGameStr[i][j] = DIRECTION_ARROW_OUTPUT_WEST;
                    }
                }
                else {
                boardGameStr[i][j] = " |";
                }
         
        }

    }

    for (int s=0; s<*boardDimension; s++) {
        for (int t=0; t<*boardDimension; t++) {
            if (s == 0 && t == 0){
                boardGameStr[s][t] = "| |";
            }
            else if (s == 0) {
                if (t>10){
                    boardGameStr[s][t] = std::to_string(t-11)+"|";
                }
                else{
                boardGameStr[s][t] = std::to_string(t-1)+"|";
                }
            }
            else if (s != 0 && t == 0) {
                if (s>10){
                    boardGameStr[s][t] = "|"+ std::to_string(s-11)+"|";
                    }
                else{
                    boardGameStr[s][t] = "|"+ std::to_string(s-1)+"|";
                    }
            }  
            
            cout << boardGameStr[s][t];
        }
        cout << endl;
    }

}


void Board::pBoard(){
    string boardGameStr[*boardDimension][*boardDimension] = { " " };
    
    for (int i =1; i<*boardDimension; i++) {
        for (int j = 1; j<*boardDimension; j++) {
                if ((*board)[i][j] == BLOCKED) {
                    boardGameStr[i][j] = "*|";
                }
                else if ((*board)[i][j] != PLAYER) {
                    boardGameStr[i][j] = " |";
                }
         
        }

    }

    for (int s=0; s<*boardDimension; s++) {
        for (int t=0; t<*boardDimension; t++) {
            if (s == 0 && t == 0){
                boardGameStr[s][t] = "| |";
            }
            else if (s == 0) {
                if (t>10){
                    boardGameStr[s][t] = std::to_string(t-11)+"|";
                }
                else{
                boardGameStr[s][t] = std::to_string(t-1)+"|";
                }
            }
            else if (s != 0 && t == 0) {
                if (s>10){
                    boardGameStr[s][t] = "|"+ std::to_string(s-11)+"|";
                    }
                else{
                    boardGameStr[s][t] = "|"+ std::to_string(s-1)+"|";
                    }
            }
            
            cout << boardGameStr[s][t];
        }
        cout << endl;
    }
}




