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
			//(*cb)[starting]->getType();
			//cerr << " cannot move from " << starting << " to " << destination << " as there is a ";
			//(*cb)[next_pos]->getType();
			//cerr << " at position " << next_pos;
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
				//cout << "Valid move " << i << " " << valid_move[i] << endl;
				if (m == valid_move[i]){ 
				 	if ((*cb)[p]->returnType() == 'P' || (*cb)[p]->returnType() == 'p'){ // If piece is a pawn
					 	// TODO: EN PASSANT
					 	// TODO: PAWN PROMOTION
					 	// TODO: PUT ALL OF THIS INSIDE THE PAWN CLASS, AND MAYBE MAKE IT A FRIEND CLASS
						// Diagonal move 
						if (m == Move(1, 1) || m == Move(-1, 1) || m == Move(1, -1) || m == Move(-1, -1)) 
							return (*cb)[final_p] && (*cb)[final_p]->getColour() != (*cb)[p]->getColour();

						// If move is double
						if (m == Move(0, 2) || m == Move(0, -2))
							return (p.getRank() == '2' && final_p.getRank() == '4' && !(*cb)[final_p])
									|| (p.getRank() == '7' && final_p.getRank() == '5' && !(*cb)[final_p]);

						// If move is single
						if (m == Move(0, 1) || m == Move(0, -1))
							return !(*cb)[final_p];
					}
					return true;
				}
			}
		}
        //cerr << "The move was invalid" << endl;
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

bool GameManager::isCheckMateOrStaleMate(Position& king_pos){
	Color c = (*cb)[king_pos]->getColour();
	int initial_number_of_checks = checkCounter(king_pos, c);
	
	for (Position p("A8"); p!=("XX"); p.move('1')){
		if ((*cb)[p] && (*cb)[p]->getColour() == c){
			for (Position j("A8"); j!=("XX"); j.move('1')){
				if (j != p){
					Color p_color = (*cb)[p]->getColour();
					if (isMoveValid(p, j)
							&& !sameColorPieceAtDestination(p_color, j) 
							&& !pieceInThePath(p, j, (j-p).getDirection())){

						// Make the move
						Piece* tmp = (*cb)[j];
						(*cb)[j] = (*cb)[p];
						(*cb)[p] = NULL;

						int checks_after_move;
						if ((*cb)[j]->returnType() == 'k')
							checks_after_move = checkCounter(j, c);
						else
							checks_after_move = checkCounter(king_pos, c);

						// Undo the move
						(*cb)[p] = (*cb)[j];
						(*cb)[j] = tmp;

						// If after making the move, there are no checks
						if (checks_after_move == 0){
							cout << "The position that prevented checkmate is: " << p << endl;
							return false;
						}
					}
				}
			}
		}
	}
	if (initial_number_of_checks == 0) { // If there were no checks initially
		cout << "Stalemate" << endl;
		return true; 
	}

	// There was at least one check initially
	cout << c << " is in checkmate" << endl;
	return true; // No valid moves were found
}
