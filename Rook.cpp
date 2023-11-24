
#include<iostream>
#include "Rook.h"
using namespace std;

Rook::Rook(char type, Position position) : Piece(type, position){}

void Rook::getType(){
	//cout << colour << " rook at poisition " << position << endl; 
	if (colour == WHITE)
		cout << "♖";
	else
		cout << "♜";
}

//ostream& operator<<(ostream& o, Rook k){
	//o << "Rook at position " << position << endl;
//}
