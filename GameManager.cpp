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
				static_cast<King*>((*cb)[Position("E1")])->setHasMoved(false);
				static_cast<Rook*>((*cb)[Position("H1")])->setHasMoved(false);
				break;
			case 'Q':
				static_cast<King*>((*cb)[Position("E1")])->setHasMoved(false);
				static_cast<Rook*>((*cb)[Position("A1")])->setHasMoved(false);
				break;
			case 'k':
				static_cast<King*>((*cb)[Position("E8")])->setHasMoved(false);
				static_cast<Rook*>((*cb)[Position("H8")])->setHasMoved(false);
				break;
			case 'q':
				static_cast<King*>((*cb)[Position("E8")])->setHasMoved(false);
				static_cast<Rook*>((*cb)[Position("A8")])->setHasMoved(false);
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
		if ((*cb)[next_pos] != NULL){
			return true;
		}
		next_pos = next_pos + m;
	}
	return false;
}

bool GameManager::isMoveValid(const Position& p, const Position& final_p){
	Move m = final_p - p;
	if(!sameColorPieceAtDestination((*cb)[p]->getColour(), final_p)){ // I am no longer checking the turn or that Piece* is not NULL here
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

void GameManager::getRookPosition(const Move& m, const Position& king_pos, Position& rook_pos){
	King* king_at_origin = dynamic_cast<King*>((*cb)[king_pos]);
	King* king_at_destination = dynamic_cast<King*>((*cb)[king_pos+m]);
	
	// If king is present at the starting position
	if (king_at_origin){
		if (m == Move(2, 0) || m == Move(-2, 0)){
			if (king_at_origin->getColour() == WHITE)
				rook_pos = m == Move(2,0) ? Position("H1") : Position("A1");
			else
				rook_pos = m == Move(2,0) ? Position("H8") : Position("A8");
		}
	}

	// If king is present at the destination position
	if (king_at_destination && king_pos.getRank() == '8'){
		if (m == Move(2,0) || m==Move(-2,0)){
			if (king_at_destination->getColour() == WHITE)
				rook_pos = m == Move(2,0) ? Position("H1") : Position("A1"); 
			else
				rook_pos = m == Move(2,0) ? Position("H8") : Position("A8");
		}
	}
}

Piece* GameManager::makeMove(const Position& p, const Position& final_p){
	Move m = final_p - p;
	Position initial_rook_pos("XX"); // Get the position of the rook (used for castling moves)
	getRookPosition(m, p, initial_rook_pos);
	
	// If move being attempted is a castling move
	if (initial_rook_pos != Position("XX")){ 
		// Move the King to final_p, store its has_moved state and change it to true
		(*cb)[final_p] = (*cb)[p];
		previous_has_moved_state1 = (*cb)[final_p]->hasMoved();
		(*cb)[final_p]->setHasMoved(true);
		(*cb)[p] = NULL; 

		// Move the rook to its destination, store its has_moved state and change it to true 
		(*cb)[p+m.getDirection()] = (*cb)[initial_rook_pos];
		previous_has_moved_state2 = (*cb)[p+m.getDirection()]->hasMoved();
		(*cb)[p+m.getDirection()]->setHasMoved(true);
		(*cb)[initial_rook_pos] = NULL;
		return NULL;
	}

	// If move is not castling, make the move, store has_moved state and change to true
	Piece* tmp = (*cb)[final_p];
	(*cb)[final_p] = (*cb)[p];
	previous_has_moved_state1 = (*cb)[final_p]->hasMoved();
	(*cb)[final_p]->setHasMoved(true);
	(*cb)[p] = NULL;
	return tmp;
}

void GameManager::undoLastMove(const Position& p, const Position& final_p, Piece* previous){
	Move m = final_p - p;
	Position initial_rook_pos("XX"); // Get the position of the rook (used for castling moves)
	getRookPosition(m, p, initial_rook_pos);
	
	// If last move was a castling move
	if (initial_rook_pos != Position("XX")){ 
		// Move king to original position, and restore its has_moved status
		(*cb)[p] = (*cb)[final_p]; 
		(*cb)[p]->setHasMoved(previous_has_moved_state1);
		(*cb)[final_p] = NULL;

		// Repeat process with the rook
		(*cb)[initial_rook_pos] = (*cb)[p+m.getDirection()]; 
		(*cb)[initial_rook_pos]->setHasMoved(previous_has_moved_state2);
		(*cb)[p+m.getDirection()] = NULL; 
		return;
	}

	// If last move was not castling
	(*cb)[p] = (*cb)[final_p];
	(*cb)[p]->setHasMoved(previous_has_moved_state1);
	(*cb)[final_p] = previous;
}

int GameManager::checkCounter(const Position& king_pos, Color king_color){
	int number_of_checks = 0;
	for (Position p("A8"); p!=Position("XX"); p.move('1')){
		if ((*cb)[p] != NULL && (*cb)[p]->getColour()!=king_color){
			//cout << "The position is " << p << endl;
			Move m = king_pos - p;
			//cout << "The move is " << m << endl;
			if (isMoveValid(p, king_pos))
				number_of_checks++;
		}
	}
	//cout << "\nThe number of checks on the board is: " << number_of_checks << endl;
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
							//cout << "The position that prevented checkmate is: " << p << endl;
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
