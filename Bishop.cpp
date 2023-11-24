
#include<iostream>
#include "Bishop.h"
using namespace std;

Bishop::Bishop(char type, Position position) : Piece(type, position){}

void Bishop::getType(){
	//cout << colour << " bishop at poisition " << position << endl; 
	if (colour == WHITE)
		cout << "♗";
	else
		cout << "♝";
}

//ostream& operator<<(ostream& o, Bishop k){
	//o << "Bishop at position " << position << endl;
//}
