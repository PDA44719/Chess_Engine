#include<iostream>
#include "King.h"
#include "Rook.h"
using namespace std;

King::King(char type) : Piece(type){}

void King::getType(){
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

const char* King::returnType(){
	//cout << colour << " king at poisition " << position << endl; 
	if (colour == WHITE)
		return "White's King";
	else
		return "Black's King";
}

bool King::additionalConditionsMet(ChessBoard* cb, Position p, Move m){
	Position final_p = p + m;
	// King is attempting to Castle
	if (m == Move(2,0) || m == Move(-2,0)){ 
		Position initial_rook_pos;
		Position initial_king_pos;
		if (this->colour == WHITE){
			initial_rook_pos = m == Move(2,0) ? Position("H1") : Position("A1"); 
			initial_king_pos = Position("E1");
		} else { // King is black
			initial_rook_pos =  m == Move(2,0) ? Position("H8") : Position("A8"); 
			initial_king_pos = Position("E8");
		}
		if (p != initial_king_pos) // King must be at its initial position
			return false;

		// Rook must be at its initial position
		if (!(*cb)[initial_rook_pos] || !dynamic_cast<Rook*>((*cb)[initial_rook_pos])) 
			return false;

		// Both the King and the Rook cannot have moved
		if (static_cast<King*>((*cb)[p])->hasMoved() || static_cast<Rook*>((*cb)[initial_rook_pos])->hasMoved())
			return false;

		// No pieces can be in the path 
		if (cb->gm.pieceInThePath(p, initial_rook_pos, m.getDirection()))
			return false;

		// None of the positions that the King will pass through can be under attack
		for (Position i = p; i != final_p+m.getDirection(); i = i+m.getDirection()){
			// Go through all the squares on the board
			for (Position j("A8"); j!=("XX"); j.move('1')){
				// If there is a piece of the opposite color that can move to a position the king will pass through
				if ((*cb)[j] && (*cb)[j]->getColour() != (*cb)[p]->getColour() && cb->gm.isMoveValid(j, i, false))
					return false;
			}
		}
	}
	return true;
}

//ostream& operator<<(ostream& o, Knight k){
	//o << "Knight at position " << position << endl;
//}
