
#include<iostream>
#include "Bishop.h"
using namespace std;

Bishop::Bishop(char type) : Piece(type){}

void Bishop::getType(){
	//cout << colour << " bishop at poisition " << position << endl; 
	if (colour == WHITE)
		cout << "♗";
	else
		cout << "♝";
}

int Bishop::getValidMovesSize() {
	return valid_moves_size;
}

Move* Bishop::getValidMoves() {
	return &valid_moves[0];
}

char Bishop::returnType() {
	if (colour == WHITE)
		return 'B';
	else
		return 'b';
}

//ostream& operator<<(ostream& o, Bishop k){
	//o << "Bishop at position " << position << endl;
//}
