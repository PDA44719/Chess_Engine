#include<iostream>
#include "ChessBoard.h"
#include "GameManager.h"
#include "Pawn.h"
#include "Position.h"
#include "King.h"
#include "Rook.h"

using namespace std;

GameManager::GameManager(ChessBoard* chess_board) : cb(chess_board){};

void GameManager::setTurn(char color){
    turn = color == 'w' ? WHITE : BLACK;
}

bool GameManager::checkTurn(Piece* to_be_moved) {
    if (to_be_moved->getColour() == turn)
        return true;
    return false;
}

void GameManager::updateTurn() {
    turn = turn == WHITE ? BLACK : WHITE; // Change the colour of the turn
}

void GameManager::setCastlingInformation(const char* castling_char) const {
	// FIXME: MIGHT WANT TO DO DYNAMIC CAST TO ENSURE THE KING AND QUEEN ARE WHERE THEY ARE SUPPOSED TO
	while (*castling_char != '\n'){
		switch(*castling_char){
			case 'K':
				static_cast<King*>((*cb)[Position("E1")])->setHasNotMoved();
				static_cast<Rook*>((*cb)[Position("H1")])->setHasNotMoved();
				break;
			case 'Q':
				static_cast<King*>((*cb)[Position("E1")])->setHasNotMoved();
				static_cast<Rook*>((*cb)[Position("A1")])->setHasNotMoved();
				break;
			case 'k':
				static_cast<King*>((*cb)[Position("E8")])->setHasNotMoved();
				static_cast<Rook*>((*cb)[Position("H8")])->setHasNotMoved();
				break;
			case 'q':
				static_cast<King*>((*cb)[Position("E8")])->setHasNotMoved();
				static_cast<Rook*>((*cb)[Position("A8")])->setHasNotMoved();
				break;
			default: // If char is not one of the required ones
				return;
		}
		castling_char++;
	}
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
			Move* valid_move = (*cb)[p]->getValidMoves();
			for (int i=0; i<(*cb)[p]->getValidMovesSize(); i++){
				if (m == valid_move[i]
						&& !pieceInThePath(p, final_p, m.getDirection())
						&& (*cb)[p]->additionalConditionsMet(cb, p, m)){ 
					return true;
				}
			}
		}
		return false;
	}
	cout << "No pieces were found in that position" << endl;
    return false;
}

Piece* GameManager::makeMove(const Position& p, const Position& final_p){
	Move m = final_p - p;
	Position initial_rook_pos("XX"); // Position of the rook (only used for casling moves)
	(*cb)[p]->setHasMoved(); // Specify that the piece will move
	
	// If move is castling, get the initial position of the rook 
	if (m == Move(2, 0) && dynamic_cast<King*>((*cb)[p])) // King side castling
		initial_rook_pos = (*cb)[p]->getColour() == WHITE ? Position("H1") : Position("H8");
	if (m == Move(-2, 0) && dynamic_cast<King*>((*cb)[p])) // Queen side castling
		initial_rook_pos = (*cb)[p]->getColour() == WHITE ? Position("A1") : Position("A8");

	if (initial_rook_pos != Position("XX")){ // Castling move to be made
		// Move the King to final_p
		(*cb)[final_p] = (*cb)[p];
		(*cb)[p] = NULL; 

		// Move the rook to its destination and specify it has moved
		(*cb)[p+m.getDirection()] = (*cb)[initial_rook_pos];
		(*cb)[initial_rook_pos] = NULL;
		(*cb)[p+m.getDirection()]->setHasMoved();
		return NULL;
	}

	// If move is not castling
	Piece* tmp = (*cb)[final_p];
	(*cb)[final_p] = (*cb)[p];
	(*cb)[p] = NULL;
	return tmp;
}

int GameManager::checkCounter(const Position& king_pos, Color king_color){
	int number_of_checks = 0;
	for (Position p("A8"); p!=Position("XX"); p.move('1')){
		if ((*cb)[p] != NULL && (*cb)[p]->getColour()!=king_color){
			cout << "The position is " << p << endl;
			Move m = king_pos - p;
			cout << "The move is " << m << endl;
			if (isMoveValid(p, king_pos))
				number_of_checks++;
		}
	}
	cout << "\nThe number of checks on the board is: " << number_of_checks << endl;
	return number_of_checks;
}

bool GameManager::isCheckMateOrStaleMate(Color king_color){
	Position king_pos = cb->getKingPosition(king_color);
	int initial_number_of_checks = checkCounter(king_pos, king_color);
	
	for (Position p("A8"); p!=("XX"); p.move('1')){
		if ((*cb)[p] && (*cb)[p]->getColour() == king_color){
			for (Position j("A8"); j!=("XX"); j.move('1')){
				if (j != p){
					//Color p_color = (*cb)[p]->getColour();
					if (isMoveValid(p, j)){ 
						// Make the move. No need to worry about castling here. If the other potentially valid
						// moves are not allowed for the King, castling will also not be valid
						Piece* tmp = (*cb)[j];
						(*cb)[j] = (*cb)[p];
						(*cb)[p] = NULL;

						int checks_after_move;
						if (dynamic_cast<King*>((*cb)[j])) // Piece that moved is a King
							checks_after_move = checkCounter(j, king_color);
						else
							checks_after_move = checkCounter(king_pos, king_color);

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
	cout << king_color << " is in checkmate" << endl;
	return true; // No valid moves were found
}
