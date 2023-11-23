
#include<iostream>
#include "Rook.h"
using namespace std;

Rook::Rook(char type, char position[2]) : Piece(type, position){}

void Rook::getType(){
	cout << colour << " rook at poisition " << position << endl; 
}

//ostream& operator<<(ostream& o, Rook k){
	//o << "Rook at position " << position << endl;
//}
