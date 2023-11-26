
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
	return 0;
}

Move* Rook::getValidMoves() {
	return NULL;
}

//ostream& operator<<(ostream& o, Rook k){
	//o << "Rook at position " << position << endl;
//}
