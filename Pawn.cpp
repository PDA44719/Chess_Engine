#include<iostream>
#include "Pawn.h"
#include "Move.h"
using namespace std;
class ChessBoard;

Pawn::Pawn(char type) : Piece(type){
	// Multiply the potential moves by -1 if the pawn is black, as they 
	// move from higher ranks to lower ranks (i.e., negative moves)
	if (colour == BLACK){
		for (int i=0; i<potential_moves_size; i++)
			potential_moves[i]*(-1);
	}
}

void Pawn::getSymbol(){
	if (colour == WHITE)
		cout << "♙";
	else
		cout << "♟︎";
}

int Pawn::getPotentialMovesSize() {
	return potential_moves_size;
}

Move* Pawn::getPotentialMoves() {
	return &potential_moves[0];
}

const char* Pawn::getType(){
	if (colour == WHITE)
		return "White's Pawn";
	else
		return "Black's Pawn";
}

bool Pawn::additionalConditionsMet(ChessBoard* cb, Position p, Move m){
	Position final_p = p + m; // Final position

	// If move is diagonal, there must be an opposing player piece at final_p
	if (m == Move(1, 1) || m == Move(-1, 1) || m == Move(1, -1) || m == Move(-1, -1)) 
		return (*cb)[final_p] && (*cb)[final_p]->getColour() != (*cb)[p]->getColour();

	// If move is double vertical, pawn must be at starting position and no pieces at final_p
	if (m == Move(0, 2) || m == Move(0, -2))
		return (p.getRank() == '2' && final_p.getRank() == '4' && !(*cb)[final_p])
				|| (p.getRank() == '7' && final_p.getRank() == '5' && !(*cb)[final_p]);

	// If move is single vertical, no pieces can be at final position
	if (m == Move(0, 1) || m == Move(0, -1))
		return !(*cb)[final_p];

	return false; // This return statement prevents a warning, but it should never be reached
}
