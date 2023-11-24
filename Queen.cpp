
#include<iostream>
#include "Queen.h"
using namespace std;

Queen::Queen(char type, Position position) : Piece(type, position){}

void Queen::getType(){
	//cout << colour << " queen at poisition " << position << endl; 
	if (colour == WHITE)
		cout << "♕";
	else
		cout << "♛";
}

//ostream& operator<<(ostream& o, Queen k){
	//o << "Queen at position " << position << endl;
//}
