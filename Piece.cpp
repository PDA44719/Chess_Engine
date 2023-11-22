#include<iostream>
#include "Piece.h"
using namespace std;

Piece::Piece(char piece_type, char piece_position[2]): type(piece_type), position(&piece_position[0]) {
	this->getColour();
}

//void Piece::getPosition(){
	//cout << this.(*position) << this.(*position + 1) << endl;
//}


// Define the behaviour of ostream << when dealing with the Color enum
ostream& operator<<(ostream &o, Color color){
        switch(color){
                case WHITE:
                        o << "white";
                        break;
                default: // BLACK
                        o << "black";
                        break;
        }
        return o;
}

void Piece::getType(){
	cout << this->type << " at poisition " << position; 
	cout << " with colour " << colour << endl;
}

void Piece::getColour(){
	if (type >= 'A' && type >= 'Z') // type is uppercase
		colour = WHITE;
	else
		colour = BLACK;
}
