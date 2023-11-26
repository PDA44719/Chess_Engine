#include<iostream>
#include "GameManager.h"
#include "Pawn.h"
using namespace std;

GameManager::GameManager(ChessBoard* chess_board) : cb(chess_board){};

void GameManager::setTurn(char color){
    turn = color == 'w' ? WHITE : BLACK;
}

bool GameManager::checkTurn(Piece* to_be_moved) {
    if (to_be_moved->getColour() == turn)
        return true;
    cout << "\nIt is not " << to_be_moved->getColour() << "'s turn to move!\n";
    return false;
}

void GameManager::updateTurn() {
    turn = turn == WHITE ? BLACK : WHITE; // Change the colour of the turn
}
//bool GameManager::checkValidPawnMove(Color pawn_color, Position inital_position, Position final_position){
//    if (pawn_color == WHITE) {
//        if (inital_position.getRank()-'0' == 2, final_position.getFile() == inital_position.getFile()){
//            if (final_position.getRank())
//        }
//    }
//}