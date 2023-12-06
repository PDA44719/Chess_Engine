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

bool GameManager::sameColorPieceAtDestination(Color colour, Position destination) {
    if ((*cb)[destination] && (*cb)[destination]->getColour() == colour){
		//(*cb)[starting]->getType();
  		//cerr << " cannot move from " << starting << " to "  << destination << " as ";
		//(*cb)[destination]->getType();
		//cerr << " is already present at that position" << endl;
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
		if(!sameColorPieceAtDestination((*cb)[p]->getColour(), final_p)){ // I am no longer checking the turn here
			// cb would be the checkValidMove method
			Move* valid_move = (*cb)[p]->getValidMoves();
			for (int i=0; i<(*cb)[p]->getValidMovesSize(); i++){
				cout << "Valid move " << i << " " << valid_move[i] << endl;
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

int GameManager::checkCounter(const Position& king_pos, Color king_color){
	int number_of_checks = 0;
	for (Position p("A8"); p!=Position("XX"); p.move('1')){
		if ((*cb)[p] != NULL && (*cb)[p]->getColour()!=king_color){
			cout << "The position is " << p << endl;
			Move m = king_pos - p;
			cout << "The move is " << m << endl;
			if (isMoveValid(p, king_pos) && !pieceInThePath(p, king_pos, m.getDirection()))
				number_of_checks++;
		}
	}
	cout << "\nThe number of checks on the board is: " << number_of_checks << endl;
	return number_of_checks;
}

bool GameManager::isCheckMate(const int& number_of_checks, Position& king_pos){
	Move *valid_move = (*cb)[king_pos]->getValidMoves(); 
	int n_moves = (*cb)[king_pos]->getValidMovesSize();
	Color c = (*cb)[king_pos]->getColour();
	// delete (*cb)[king_pos]; // Delete the King (UNCOMMENT THIS AT SOME POINT)
	//(*cb)[king_pos] = NULL; // Set that pointer to NULL
	
	// Try to find a valid move where there are no checks
	for (int i=0; i<n_moves; i++){
		Position new_king_pos = king_pos + valid_move[i];
		if (new_king_pos.isValid() && !sameColorPieceAtDestination(c, new_king_pos)){
			// Make move and store the piece at the new king pos in another variable
			Piece* piece_at_new_king_pos = (*cb)[new_king_pos];
			(*cb)[new_king_pos] = (*cb)[king_pos];
			(*cb)[king_pos] = NULL;

			cout << new_king_pos << endl;
			int n_of_checks = checkCounter(new_king_pos, c);
			// Return pieces to the original position
			(*cb)[king_pos] = (*cb)[new_king_pos]; 
			(*cb)[new_king_pos] = piece_at_new_king_pos; 

			if (n_of_checks == 0){
				return false;
			}
		}
	}
	//if (number_of_checks > 1) {
	return true;
	//}
}
