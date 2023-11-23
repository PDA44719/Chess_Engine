
#include<iostream>
#include "Knight.h"
using namespace std;

Knight::Knight(char type, char position[2]) : Piece(type, position){}

void Knight::getType(){
	cout << colour << " knight at poisition " << position << endl; 
}

//ostream& operator<<(ostream& o, King k){
	//o << "King at position " << position << endl;
//}
