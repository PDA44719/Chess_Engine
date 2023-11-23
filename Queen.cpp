
#include<iostream>
#include "Queen.h"
using namespace std;

Queen::Queen(char type, char position[2]) : Piece(type, position){}

void Queen::getType(){
	cout << colour << " queen at poisition " << position << endl; 
}

//ostream& operator<<(ostream& o, Queen k){
	//o << "Queen at position " << position << endl;
//}
