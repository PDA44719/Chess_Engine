
#include<iostream>
#include "Rook.h"
using namespace std;

Rook::Rook(char type) : Piece(type){}

void Rook::getSymbol(){
	//cout << colour << " rook at poisition " << position << endl; 
	if (colour == WHITE)
		cout << "♖";
	else
		cout << "♜";
}

int Rook::getPotentialMovesSize() {
	return potential_moves_size;
}

Move* Rook::getPotentialMoves() {
	return &potential_moves[0];
}

const char* Rook::getType(){
	if (colour == WHITE)
		return "White's Rook";
	else
		return "Black's Rook";
}

//ostream& operator<<(ostream& o, Rook k){
	//o << "Rook at position " << position << endl;
//}
