#include<iostream>
#include "Queen.h"
using namespace std;

Queen::Queen(char type) : Piece(type){}

void Queen::getSymbol(){
	if (colour == WHITE)
		cout << "♕";
	else
		cout << "♛";
}

int Queen::getPotentialMovesSize() {
	return potential_moves_size;
}

Move* Queen::getPotentialMoves() {
	return &potential_moves[0];
}

const char* Queen::getType() {
	if (colour == WHITE)
		return "White's Queen";
	else
		return "Black's Queen";
}
