#include<iostream>
#include "King.h"
#include "Rook.h"
using namespace std;

King::King(char type) : Piece(type){}

void King::getSymbol(){
	if (colour == WHITE)
		cout << "♔";
	else
		cout << "♚";
}

int King::getPotentialMovesSize() {
	return potential_moves_size;
}

Move* King::getPotentialMoves() {
	return &potential_moves[0];
}

const char* King::getType(){
	if (colour == WHITE)
		return "White's King";
	else
		return "Black's King";
}

bool King::additionalConditionsMet(ChessBoard* cb, Position p, Move m){
	Position final_p = p + m; // Final position

	// King is attempting to Castle
	if (m == Move(2,0) || m == Move(-2,0)){ 
		// Get the initial position of both the rook and the king
		Position initial_rook_pos;
		Position initial_king_pos;
		if (this->colour == WHITE){ // King is white
			initial_rook_pos = m == Move(2,0) ? Position("H1") : Position("A1"); 
			initial_king_pos = Position("E1");
		} else { // King is black
			initial_rook_pos =  m == Move(2,0) ? Position("H8") : Position("A8"); 
			initial_king_pos = Position("E8");
		}

		// King must be at its initial position
		if (p != initial_king_pos) 
			return false;

		// Rook must be at its initial position
		if (!(*cb)[initial_rook_pos] || !dynamic_cast<Rook*>((*cb)[initial_rook_pos])) 
			return false;

		// Both the King and the Rook cannot have previously moved during the game
		if (static_cast<King*>((*cb)[p])->hasMoved() || static_cast<Rook*>((*cb)[initial_rook_pos])->hasMoved())
			return false;

		// No pieces can be in the castling path
		if (cb->gm.pieceInThePath(p, initial_rook_pos, m.getDirection()))
			return false;

		// None of the positions that the King will pass through can be under attack
		for (Position i = p; i != final_p+m.getDirection(); i = i+m.getDirection()){
			// Go through all the squares on the board
			for (Position j("A8"); j!=("XX"); j.move('1')){
				// If there is a an opposing piece that can move to a position the king will pass through
				if ((*cb)[j] && (*cb)[j]->getColour() != (*cb)[p]->getColour() && cb->gm.isMoveValid(j, i, false))
					return false;
			}
		}
	}
	return true; // If this statement was reached, that means all the conditions were met
}
