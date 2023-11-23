
#include<iostream>
#include "King.h"
using namespace std;

King::King(char type, char position[2]) : Piece(type, position){}

void King::getType(){
	cout << colour << " king at poisition " << position << endl; 
}

//ostream& operator<<(ostream& o, Knight k){
	//o << "Knight at position " << position << endl;
//}
