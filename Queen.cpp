
#include<iostream>
#include "Queen.h"
using namespace std;

Queen::Queen(char type) : Piece(type){}

void Queen::getType(){
	//cout << colour << " queen at poisition " << position << endl; 
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

//ostream& operator<<(ostream& o, Queen k){
	//o << "Queen at position " << position << endl;
//}

const char* Queen::returnType() {
	if (colour == WHITE)
		return "White's Queen";
	else
		return "Black's Queen";
}