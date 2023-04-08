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
    delete board;
    delete boardDimension;

    boardDimension = new int(row+1);
    board = new vector<vector<Cell>>(*boardDimension, vector<Cell>(*boardDimension, EMPTY));

    int randomCells = (row*row)*prob;

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, row); // define the range
    //cout << "got here " << endl;
    for(int n=randomCells; n>0; n--){
        int i = distr(gen);
        int j = distr(gen);
        cout<< "N: " << n << endl;
        cout << "i: " << i << " j: " << j << endl;
        if ((*board)[i][j] == BLOCKED){
            n++;
        }
        (*board)[i][j] = BLOCKED;
        
    }
        

   pBoardNoPlayer();


}

void Board::load(int boardId)
{
    // TODO
    delete board;
    board = new vector<vector<Cell>>(*boardDimension, vector<Cell>(*boardDimension, EMPTY));
    string boardGameStr[*boardDimension][*boardDimension] = { " " };
    
    //todo if baordId isNot valid, loop till valid
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

    for (int i =1; i<*boardDimension; i++) {
        for (int j = 1; j<*boardDimension; j++) {
            if (boardId == 1) {
                if (BOARD_1[i-1][j-1] == BLOCKED) {
                    boardGameStr[i][j] = "*|";
                    //next line creates a seg fault
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
                exit(1);
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

bool Board::placePlayer(Position position)
{
    bool toReturn;
    if (position.x >0 && position.x <*boardDimension && position.y >0 && position.y <*boardDimension) {
        if ((*board)[position.x][position.y] == BLOCKED) {
            cout << "cant place player here" << endl;
            toReturn = false;
        }
        else {
            (*board)[position.x][position.y] = PLAYER;
            toReturn = true;
        }
    }
    else {
        cout << "out of bounds area" << endl;
        toReturn = false;
    }
    return toReturn;

 // feel free to revise this line, depending on your implementation.
}

PlayerMove Board::movePlayerForward(Player* player)
{
    // TODO
    //cout << "in move player forward class::board" << endl;
    //cout << "player direction: " << (*player).direction << endl;
    //cout << "player position x: " << (*player).position.x << " position y: " << (*player).position.y << endl;
    
    if (player->direction == EAST){
        if (player->position.y+1 >*boardDimension-1){
            cout << "out of bounds area" << endl;
        }

        else if ((*board)[player->position.x][player->position.y+1] == BLOCKED) {
            cout << "player hit wall" << endl;
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
            cout << "out of bounds area" << endl;
        }
        else if ((*board)[player->position.x][player->position.y-1] == BLOCKED) {
            cout << "player hit wall" << endl;
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
            cout << "out of bounds area" << endl;
        }
        else if ((*board)[player->position.x+1][player->position.y] == BLOCKED) {
            cout << "player hit wall" << endl;
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
            cout << "out of bounds area" << endl;
        }
        else if ((*board)[player->position.x-1][player->position.y] == BLOCKED) {
            cout << "player hit wall" << endl;
        }
        else {
            (*board)[player->position.x-1][player->position.y] = PLAYER;
            (*board)[player->position.x][player->position.y] = EMPTY;
            player->position.x = player->position.x-1;
            player->moves++;
        }
    }


    //cout << "in end of move player forward class::board" << endl;
    //cout << "player direction: " << (*player).direction << endl;
    //cout << "player position x: " << (*player).position.x << " position y: " << (*player).position.y << endl;
    return PLAYER_MOVED;
}

void Board::display(Player* player)
{
    // TODO
    string boardGameStr[*boardDimension][*boardDimension] = { " " };
    //todo if baordId isNot valid, loop till valid
   
    //cout << "created test in board.cpp" << endl;
    //cout << "assignt *board to test" << endl;
    //Player t1;
    
    //t1 = *player;
    //test[t1.position.x][t1.position.y] = PLAYER;
    //cout<< "printing board address in baord::class" << board << endl;
    for (int i =1; i<*boardDimension; i++) {
        for (int j = 1; j<*boardDimension; j++) {
                
                if ((*board)[i][j] == BLOCKED) {
                    boardGameStr[i][j] = "*|";
                    //next line creates a seg fault
                    //this->board->at(i).at(j) = BLOCKED;
                }
                else if ((*board)[i][j] == PLAYER) {

                    boardGameStr[i][j] = "P|";
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

void Board::pBoard()
{
    // TODO
    string boardGameStr[*boardDimension][*boardDimension] = { " " };
    for (int s = 0; s <*boardDimension; s++){
        for (int t =0; t < *boardDimension; t++){
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
            else {
                boardGameStr[s][t] = " |";
            }
            cout << boardGameStr[s][t];  
        }
        cout << endl;
    }
}

void Board::pBoardNoPlayer(){
    string boardGameStr[*boardDimension][*boardDimension] = { " " };
    //todo if baordId isNot valid, loop till valid
   
    //cout << "created test in board.cpp" << endl;
    //cout << "assignt *board to test" << endl;
    //Player t1;
    
    //t1 = *player;
    //test[t1.position.x][t1.position.y] = PLAYER;
    //cout<< "printing board address in baord::class" << board << endl;
    for (int i =1; i<*boardDimension; i++) {
        for (int j = 1; j<*boardDimension; j++) {
                if ((*board)[i][j] == BLOCKED) {
                    boardGameStr[i][j] = "*|";
                    //next line creates a seg fault
                    //this->board->at(i).at(j) = BLOCKED;
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




