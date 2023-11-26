#include<iostream>
#include "Pawn.h"
#include "Move.h"
using namespace std;

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

//ostream& operator<<(ostream& o, Pawn k){
	//o << "Pawn at position " << position << endl;
//}
