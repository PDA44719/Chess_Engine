
#include<iostream>
#include "Knight.h"
using namespace std;

Knight::Knight(char type) : Piece(type){}

void Knight::getType(){
	//cout << colour << " knight at poisition " << position << endl; 
	if (colour == WHITE)
		cout << "♘";
	else
		cout << "♞";
}

int Knight::getValidMovesSize(){
	return valid_moves_size;
}

Move* Knight::getValidMoves(){
	return &valid_moves[0];
}

//ostream& operator<<(ostream& o, King k){
	//o << "King at position " << position << endl;
//}
