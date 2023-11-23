
#include<iostream>
#include "Bishop.h"
using namespace std;

Bishop::Bishop(char type, char position[2]) : Piece(type, position){}

void Bishop::getType(){
	cout << colour << " bishop at poisition " << position << endl; 
}

//ostream& operator<<(ostream& o, Bishop k){
	//o << "Bishop at position " << position << endl;
//}
