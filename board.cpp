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
    
    
    vector<vector<Cell>> boardGame(11, vector<Cell>(11, EMPTY));
    this->board = &boardGame;
    
 
    for (int i = 0; i<11; i++) {
        for (int j = 0; j<11; j++) {
            
            //boardGame[i][j] = emp;
            if (i == 0 && j == 0){
                boardGame[i][j] = BLOCKED;
            }
            else if (i == 0) {
                boardGame[i][j] = BLOCKED;
            }
            else if (i!= 0 && j == 0) {
                boardGame[i][j] = BLOCKED;
            }
            else {
                boardGame[i][j] = EMPTY;
            }
            //cout << boardGame[i][j] << " ";
        }
        //cout << endl;
    }
    /*
    string boardGameStr[11][11] = { " " };
    for (int s = 0; s <11; s++){
        for (int t =0; t < 11; t++){
            if (s == 0 && t == 0){
                boardGameStr[s][t] = "|   |";
            }
            else if (s == 0) {
                boardGameStr[s][t] = std::to_string(t-1)+" |";
            }
            else if (s != 0 && t == 0) {
                boardGameStr[s][t] = "| "+ std::to_string(s-1)+" |";
            }
            else {
                boardGameStr[s][t] = "  |";
            }
            //cout << boardGameStr[s][t] << " ";  
        }
        //cout << endl;
    }
    */

}

Board::~Board()
{
    // TODO destroy board
}

void Board::load(int boardId)
{
    // TODO
    string boardGameStr[11][11] = { " " };
    
    //todo if baordId isNot valid, loop till valid


    for (int i =1; i<11; i++) {
        for (int j = 1; j<11; j++) {
            if (boardId == 1) {
                if (BOARD_1[i-1][j-1] == BLOCKED) {
                    boardGameStr[i][j] = "*|";
                    //next line creates a seg fault
                    //this->board->at(i).at(j) = BLOCKED;
                }
                else {
                boardGameStr[i][j] = " |";
                }
                
            }
            else if (boardId == 2) {
                if (BOARD_2[i-1][j-1] == BLOCKED) {
                    boardGameStr[i][j] = "*|";
                    //this->board->at(i).at(j) = BLOCKED;
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

    for (int s=0; s<11; s++) {
        for (int t=0; t<11; t++) {
            if (s == 0 && t == 0){
                boardGameStr[s][t] = "| |";
            }
            else if (s == 0) {
                boardGameStr[s][t] = std::to_string(t-1)+"|";
            }
            else if (s != 0 && t == 0) {
                boardGameStr[s][t] = "|"+ std::to_string(s-1)+"|";
            }
            
            cout << boardGameStr[s][t];
        }
        cout << endl;
    }

}

bool Board::placePlayer(Position position)
{
    // TODO
    //this->board->at(position.x+1).at(position.y+1) = PLAYER;
    return false; // feel free to revise this line, depending on your implementation.
}

PlayerMove Board::movePlayerForward(Player* player)
{
    // TODO
    return PLAYER_MOVED;
}

void Board::display(Player* player)
{
    // TODO

}

void Board::pBoard()
{
    // TODO
    string boardGameStr[11][11] = { " " };
    for (int s = 0; s <11; s++){
        for (int t =0; t < 11; t++){
            if (s == 0 && t == 0){
                boardGameStr[s][t] = "| |";
            }
            else if (s == 0) {
                boardGameStr[s][t] = std::to_string(t-1)+"|";
            }
            else if (s != 0 && t == 0) {
                boardGameStr[s][t] = "|"+ std::to_string(s-1)+"|";
            }
            else {
                boardGameStr[s][t] = " |";
            }
            cout << boardGameStr[s][t];  
        }
        cout << endl;
    }
}


