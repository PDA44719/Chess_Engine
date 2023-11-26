
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
	return 0;
}

Move* King::getValidMoves() {
	return NULL;
}

//ostream& operator<<(ostream& o, Knight k){
	//o << "Knight at position " << position << endl;
//}
