
#include<iostream>
#include "Knight.h"
using namespace std;

Knight::Knight(char type) : Piece(type){}

void Knight::getSymbol(){
	//cout << colour << " knight at poisition " << position << endl; 
	if (colour == WHITE)
		cout << "♘";
	else
		cout << "♞";
}

int Knight::getPotentialMovesSize(){
	return potential_moves_size;
}

Move* Knight::getPotentialMoves(){
	return &potential_moves[0];
}

const char* Knight::getType(){
	if (colour == WHITE)
		return "White's Knight";
	else
		return "Black's Knight";
}
//ostream& operator<<(ostream& o, King k){
	//o << "King at position " << position << endl;
//}
