#include<iostream>
#include "Pawn.h"
#include "Move.h"
using namespace std;
class ChessBoard;

Pawn::Pawn(char type) : Piece(type){
	if (colour == BLACK){
		for (int i=0; i<valid_moves_size; i++)
			valid_moves[i]*(-1);
	}
}

void Pawn::getType(){
	//cout << colour << " pawn at poisition " << position << endl; 
	if (colour == WHITE)
		cout << "♙";
	else
		cout << "♟︎";
}

int Pawn::getValidMovesSize() {
	return valid_moves_size;
}

Move* Pawn::getValidMoves() {
	return &valid_moves[0];
}

char Pawn::returnType(){
	if (colour == WHITE)
		return 'P';
	else
		return 'p';
}

bool Pawn::additionalConditionsMet(ChessBoard* cb, Position p, Move m){
	Position final_p = p + m; // Final position

	// If move is diagonal, there must be an opposing player piece at final_p
	if (m == Move(1, 1) || m == Move(-1, 1) || m == Move(1, -1) || m == Move(-1, -1)) 
		return (*cb)[final_p] && (*cb)[final_p]->getColour() != (*cb)[p]->getColour();

	// If move is double, pawn must be at starting position and no pieces at final_p
	if (m == Move(0, 2) || m == Move(0, -2))
		return (p.getRank() == '2' && final_p.getRank() == '4' && !(*cb)[final_p])
				|| (p.getRank() == '7' && final_p.getRank() == '5' && !(*cb)[final_p]);

	// If move is single, no pieces can be at final position
	if (m == Move(0, 1) || m == Move(0, -1))
		return !(*cb)[final_p];

	return false; // This return statement is only here to prevent a warning, but it should never be reached
}

//ostream& operator<<(ostream& o, Pawn k){
	//o << "Pawn at position " << position << endl;
//}
