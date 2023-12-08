
#include<iostream>
#include "King.h"
#include "Rook.h"
using namespace std;

King::King(char type) : Piece(type){}

void King::getType(){
	//cout << colour << " king at poisition " << position << endl; 
	if (colour == WHITE)
		cout << "♔";
	else
		cout << "♚";
}

int King::getValidMovesSize() {
	return valid_moves_size;
}

Move* King::getValidMoves() {
	return &valid_moves[0];
}

char King::returnType(){
	//cout << colour << " king at poisition " << position << endl; 
	if (colour == WHITE)
		return 'K';
	else
		return 'k';
}

bool King::hasMoved(){
	return has_moved;
}

bool King::additionalConditionsMet(ChessBoard* cb, Position p, Move m){
	Position final_p = p + m;
	// King is attempting to Castle
	if (m == Move(2,0) || m == Move(-2,0)){ 
		Position rook_pos = m == Move(2,0) ? Position("H1") : Position("A1");
		if (p != Position("E1")) // King must be at initial position
			return false;

		// Rook must be at the corner
		if (!(*cb)[rook_pos] || (*cb)[rook_pos]->returnType()!= 'R') 
			return false;

		// Both the King and the Rook cannot have moved
		if (static_cast<King*>((*cb)[p])->hasMoved() || static_cast<Rook*>((*cb)[rook_pos])->hasMoved())
			return false;

		// No pieces can be in the path 
		if (cb->gm.pieceInThePath(p, rook_pos, m.getDirection()))
			return false;

		// None of the pieces that the King will pass through can be under attack
		for (Position i = p; i != final_p+m.getDirection(); i = i+m.getDirection()){
			for (Position j("A8"); j!=("XX"); j.move('1')){
				if ((*cb)[j] && (*cb)[j]->getColour() != (*cb)[p]->getColour() && cb->gm.isMoveValid(j, i))
					return false;
			}
		}
	}
	return true;
}

//ostream& operator<<(ostream& o, Knight k){
	//o << "Knight at position " << position << endl;
//}
