
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
	return 0;
}

Move* Bishop::getValidMoves() {
	return NULL;
}

//ostream& operator<<(ostream& o, Bishop k){
	//o << "Bishop at position " << position << endl;
//}
