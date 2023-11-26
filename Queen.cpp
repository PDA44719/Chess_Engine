
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

int Queen::getValidMovesSize() {
	return 0;
}

Move* Queen::getValidMoves() {
	return NULL;
}

//ostream& operator<<(ostream& o, Queen k){
	//o << "Queen at position " << position << endl;
//}
