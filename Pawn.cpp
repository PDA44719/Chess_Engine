
#include<iostream>
#include "Pawn.h"
using namespace std;

Pawn::Pawn(char type, Position position) : Piece(type, position){}

void Pawn::getType(){
	//cout << colour << " pawn at poisition " << position << endl; 
	if (colour == WHITE)
		cout << "♙";
	else
		cout << "♟︎";
}

//ostream& operator<<(ostream& o, Pawn k){
	//o << "Pawn at position " << position << endl;
//}
