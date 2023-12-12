
#include<iostream>
#include "Bishop.h"
using namespace std;

Bishop::Bishop(char type) : Piece(type){}

void Bishop::getSymbol(){
	//cout << colour << " bishop at poisition " << position << endl; 
	if (colour == WHITE)
		cout << "♗";
	else
		cout << "♝";
}

int Bishop::getPotentialMovesSize() {
	return potential_moves_size;
}

Move* Bishop::getPotentialMoves() {
	return &potential_moves[0];
}

const char* Bishop::getType() {
	if (colour == WHITE)
		return "White's Bishop";
	else
		return "Black's Bishop";
}

//ostream& operator<<(ostream& o, Bishop k){
	//o << "Bishop at position " << position << endl;
//}
