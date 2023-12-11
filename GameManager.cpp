#include<iostream>
#include "ChessBoard.h"
#include "GameManager.h"
#include "Pawn.h"
#include "Position.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"

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

Color GameManager::getTurn() {
	return turn;
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
	// Return true if there is a piece at the destination and it has the same colour
    if ((*cb)[destination] && (*cb)[destination]->getColour() == colour)
        return true;
    return false;
}

bool GameManager::pieceInThePath(Position starting, const Position& destination, const Move& m){
	Position next_pos = starting + m;
	// Loop through each square the piece will "pass through" when making a move
	while (next_pos!=destination){
		// Return true if there is a piece in that square (i.e., there is a piece in the path)
		if ((*cb)[next_pos] != NULL){
			return true;
		}
		next_pos = next_pos + m;
	}
	return false; // No pieces were between starting position and destination
}

bool GameManager::isMoveValid(const Position& p, const Position& final_p, bool after_check){
	Move m = final_p - p;
	Color piece_color = (*cb)[p]->getColour();

	// Move is not valid if there is a piece of the same color at the destination
	if (sameColorPieceAtDestination(piece_color, final_p))
		return false;

	// Loop through the potential valid moves a piece has
	Move* potential_move = (*cb)[p]->getPotentialMoves();
	for (int i=0; i<(*cb)[p]->getPotentialMovesSize(); i++){
		// If move is one of the potential moves, there are no pieces in the path
		// and any additional conditions are met for the move to be valid
		if (m == potential_move[i]
				&& !pieceInThePath(p, final_p, m.getDirection())
				&& (*cb)[p]->additionalConditionsMet(cb, p, m)){ 
			
			if (after_check){
				// Make the move, get the number of checks after it and undo it
				Piece* tmp = makeMove(p, final_p);
				int n_of_checks_after_move = checkCounter(piece_color);
				undoLastMove(p, final_p, tmp);

				// If no checks were present after making the move, it is valid
				if (n_of_checks_after_move == 0)
					return true;

			} else // If the checks after a move do not need to be checked, simply return true
				return true;
		}
	}
	return false;
}

void GameManager::getRookPosition(const Move& m, const Position& king_pos, Position& rook_pos){
	King* king_at_origin = dynamic_cast<King*>((*cb)[king_pos]);
	King* king_at_destination = dynamic_cast<King*>((*cb)[king_pos+m]);
	
	// If king is present at the starting position (i.e., makeMove called this method)
	if (king_at_origin){
		// Determine the position of the rook the king is trying to castle with
		if (m == Move(2, 0) || m == Move(-2, 0)){
			if (king_at_origin->getColour() == WHITE)
				rook_pos = m == Move(2,0) ? Position("H1") : Position("A1");
			else
				rook_pos = m == Move(2,0) ? Position("H8") : Position("A8");
		}
	}

	// Repeat the process if king is at destination (i.e., undoLastMove called this method)
	if (king_at_destination){
		if (m == Move(2,0) || m==Move(-2,0)){
			if (king_at_destination->getColour() == WHITE)
				rook_pos = m == Move(2,0) ? Position("H1") : Position("A1"); 
			else
				rook_pos = m == Move(2,0) ? Position("H8") : Position("A8");
		}
	}
}

void GameManager::castle(const Position& initial_k_pos, const Position& final_k_pos,
						 const Position& initial_r_pos, const Position& final_r_pos, bool undo){

	// Move King and Rook to final position and set inital position to NULL
	(*cb)[final_k_pos] = (*cb)[initial_k_pos];
	(*cb)[initial_k_pos] = NULL; 
	(*cb)[final_r_pos] = (*cb)[initial_r_pos];
	(*cb)[initial_r_pos] = NULL;
	
	// If castling is being undone, set has_moved back to previous value
	if (undo)
		(*cb)[final_r_pos]->setHasMoved(previous_has_moved_state2);

	// If castling is being completed, store previous has_moved value and update to true
	else { 
		previous_has_moved_state2 = (*cb)[final_r_pos]->hasMoved();
		(*cb)[final_r_pos]->setHasMoved(true);
	}
}

Piece* GameManager::makeMove(const Position& p, const Position& final_p){
	Move m = final_p - p;
	Position initial_rook_pos("XX"); // Get the position of the rook (used for castling moves)
	getRookPosition(m, p, initial_rook_pos);

	// If king is the piece that is being moved, update its position
	King* king_at_origin = dynamic_cast<King*>((*cb)[p]);
	if (king_at_origin)
		updateKingPosition((*cb)[p], final_p);
	
	// Store the initial has_moved value, in case the move needs to be undone afterwards
	previous_has_moved_state1 = (*cb)[p]->hasMoved();
	(*cb)[p]->setHasMoved(true); // Change has_moved to true, to indicate the piece will move

	// If move being attempted is a castling move
	if (initial_rook_pos != Position("XX")){ 
		castle(p, final_p, initial_rook_pos, p+m.getDirection(), false);
		//// Move the King to final_p, store its has_moved state and change it to true
		//(*cb)[final_p] = (*cb)[p];
		//(*cb)[p] = NULL; 

		//// Move the rook to its destination, store its has_moved state and change it to true 
		//(*cb)[p+m.getDirection()] = (*cb)[initial_rook_pos];
		//previous_has_moved_state2 = (*cb)[p+m.getDirection()]->hasMoved();
		//(*cb)[p+m.getDirection()]->setHasMoved(true);
		//(*cb)[initial_rook_pos] = NULL;
		return NULL;
	}

	// If move is not castling, make the move, store has_moved state and change to true
	Piece* tmp = (*cb)[final_p];
	(*cb)[final_p] = (*cb)[p];
	(*cb)[p] = NULL;
	return tmp;
}

void GameManager::undoLastMove(const Position& p, const Position& final_p, Piece* previous){
	Move m = final_p - p;
	Position initial_rook_pos("XX"); // Get the position of the rook (used for castling moves)
	getRookPosition(m, p, initial_rook_pos);

	King* king_at_final_p = dynamic_cast<King*>((*cb)[final_p]);

	// Return the position of the king to the original position
	if (king_at_final_p)
		updateKingPosition((*cb)[final_p], p);

	// Return has moved state to previous state
	(*cb)[final_p]->setHasMoved(previous_has_moved_state1);
	
	// If last move was a castling move
	if (initial_rook_pos != Position("XX")){ 
		castle(final_p, p, p+m.getDirection(), initial_rook_pos, true);
		//// Move king to original position, and restore its has_moved status
		//(*cb)[p] = (*cb)[final_p]; 
		//(*cb)[final_p] = NULL;

		//// Repeat process with the rook
		//(*cb)[initial_rook_pos] = (*cb)[p+m.getDirection()]; 
		//(*cb)[initial_rook_pos]->setHasMoved(previous_has_moved_state2);
		//(*cb)[p+m.getDirection()] = NULL; 
		return;
	}

	// If last move was not castling
	(*cb)[p] = (*cb)[final_p];
	(*cb)[final_p] = previous;
}

void GameManager::updateKingPosition(Piece* king, Position new_position){
	if (king->getColour() == WHITE)
		cb->white_king_pos = new_position;
	else
		cb->black_king_pos = new_position;
}

int GameManager::checkCounter(Color king_color){
	int number_of_checks = 0;
	Position king_pos = cb->getKingPosition(king_color);

	// Loop through all the squares on the board
	for (Position p("A8"); p!=Position("XX"); p.move('1')){
		// If there is an opposing piece that can take the king
		if ((*cb)[p] != NULL && (*cb)[p]->getColour()!=king_color){
			if (isMoveValid(p, king_pos, false)){ 
				number_of_checks++; // Increase counter
			}
		}
	}

	return number_of_checks;
}

bool GameManager::isCheckMateOrStaleMate(Color king_color){
	// Get the initial number of checks
	int initial_number_of_checks = checkCounter(king_color);
	
	// Loop through all squares on the board
	for (Position p("A8"); p!=("XX"); p.move('1')){
		// If there is a piece of the same color as the king
		if ((*cb)[p] && (*cb)[p]->getColour() == king_color){
			// Try to move the piece to another square
			for (Position j("A8"); j!=("XX"); j.move('1')){
				if (j != p){
					// If there was a valid move that led to no checks
					if (isMoveValid(p, j, true)){ 
						return false;
					}
				}
			}
		}
	}
	
	// If no valid moves can be made, there is either checkmate or stalemate
	if (initial_number_of_checks == 0) { // Stalemate 
		cout << king_color << " is in stalemate" << endl;
		return true; 
	}
	// There was at least one check initially
	cout << king_color << " is in checkmate" << endl;
	return true; 
}
