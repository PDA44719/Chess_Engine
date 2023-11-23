
#include<iostream>
#include "Pawn.h"
using namespace std;

Pawn::Pawn(char type, char position[2]) : Piece(type, position){}

void Pawn::getType(){
	cout << colour << " pawn at poisition " << position << endl; 
}

//ostream& operator<<(ostream& o, Pawn k){
	//o << "Pawn at position " << position << endl;
//}
