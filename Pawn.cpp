
#include<iostream>
#include "Pawn.h"
using namespace std;

Pawn::Pawn(char type) : Piece(type){}

void Pawn::getType(){
	//cout << colour << " pawn at poisition " << position << endl; 
	if (colour == WHITE)
		cout << "♙";
	else
		cout << "♟︎";
}

int Pawn::getValidMovesSize() {
	return 0;
}

Move* Pawn::getValidMoves() {
	return NULL;
}

//ostream& operator<<(ostream& o, Pawn k){
	//o << "Pawn at position " << position << endl;
//}
