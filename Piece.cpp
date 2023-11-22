#include<iostream>
#include "Piece.h"
using namespace std;

Piece::Piece(char piece_type, char piece_position[2]): type(piece_type), position(&piece_position[0]) {};

//void Piece::getPosition(){
	//cout << this.(*position) << this.(*position + 1) << endl;
//}

void Piece::getType(){
	cout << this->type << " at poisition " << position << endl;
}
