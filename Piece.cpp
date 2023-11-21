#include<iostream>
#include "Piece.h"
using namespace std;

Piece::Piece(char piece_type): type(piece_type){};

//void Piece::getPosition(){
	//cout << this.(*position) << this.(*position + 1) << endl;
//}

void Piece::getType(){
	cout << this->type << endl;
}
