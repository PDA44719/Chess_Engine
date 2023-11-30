#include<iostream>
#include "GameManager.h"
#include "ChessBoard.h"
#include "Pawn.h"
#include "Position.h"
using namespace std;

GameManager::GameManager(ChessBoard* chess_board) : cb(chess_board){};

void GameManager::setTurn(char color){
    turn = color == 'w' ? WHITE : BLACK;
}

bool GameManager::checkTurn(Piece* to_be_moved) {
    if (to_be_moved->getColour() == turn)
        return true;
    cerr << "\nIt is not " << to_be_moved->getColour() << "'s turn to move!\n";
    return false;
}

void GameManager::updateTurn() {
    turn = turn == WHITE ? BLACK : WHITE; // Change the colour of the turn
}

bool GameManager::sameColorPieceAtDestination(Position starting, Position destination) {
    if ((*cb)[destination] && (*cb)[destination]->getColour() == (*cb)[starting]->getColour()){
		(*cb)[starting]->getType();
        cerr << " cannot move from " << starting << " to "  << destination << " as ";
		(*cb)[destination]->getType();
		cerr << " is already present at that position" << endl;
        return true;
    }
    return false;
}

bool GameManager::pieceInThePath(Position starting, const Position& destination, const Move& m){
	Position next_pos = starting + m;
	while (next_pos!=destination){
		cout << next_pos << endl;
		if ((*cb)[next_pos] != NULL){
			(*cb)[starting]->getType();
			cerr << " cannot move from " << starting << " to " << destination << " as there is a ";
			(*cb)[next_pos]->getType();
			cerr << " at position " << next_pos;
			return true;
		}
		next_pos = next_pos + m;
	}
	return false;
}

bool GameManager::isMoveValid(const Position& p, const Position& final_p){
	Move m = final_p - p;
	if ((*cb)[p]){
		if(checkTurn((*cb)[p]) && !sameColorPieceAtDestination(p, final_p)){
			// cb would be the checkValidMove method
			Move* valid_move = (*cb)[p]->getValidMoves();
			// Print the valid moves
			cout << endl << endl;
			cout << (*cb)[p]->getValidMovesSize() << endl;
			for (int i=0; i<(*cb)[p]->getValidMovesSize(); i++){
				if (m == valid_move[i]) 
					return true;
			}
		}
        cerr << "The move was invalid" << endl;
		return false;
	}
	cout << "No pieces were found in that position" << endl;
    return false;
}
