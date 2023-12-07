
#include<iostream>
#include "Rook.h"
using namespace std;

Rook::Rook(char type) : Piece(type){}

void Rook::getType(){
	//cout << colour << " rook at poisition " << position << endl; 
	if (colour == WHITE)
		cout << "♖";
	else
		cout << "♜";
}

int Rook::getValidMovesSize() {
	return valid_moves_size;
}

Move* Rook::getValidMoves() {
	return &valid_moves[0];
}

char Rook::returnType(){
	if (colour == WHITE)
		return 'R';
	else
		return 'r';
}

bool Rook::hasMoved(){
	return has_moved;
}

//ostream& operator<<(ostream& o, Rook k){
	//o << "Rook at position " << position << endl;
//}
