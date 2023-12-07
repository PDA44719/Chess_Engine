
#include<iostream>
#include "King.h"
using namespace std;

King::King(char type) : Piece(type){}

void King::getType(){
	//cout << colour << " king at poisition " << position << endl; 
	if (colour == WHITE)
		cout << "♔";
	else
		cout << "♚";
}

int King::getValidMovesSize() {
	return valid_moves_size;
}

Move* King::getValidMoves() {
	return &valid_moves[0];
}

char King::returnType(){
	//cout << colour << " king at poisition " << position << endl; 
	if (colour == WHITE)
		return 'K';
	else
		return 'k';
}
//ostream& operator<<(ostream& o, Knight k){
	//o << "Knight at position " << position << endl;
//}
