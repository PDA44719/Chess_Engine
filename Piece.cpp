#include<iostream>
#include "Piece.h"
using namespace std;

Piece::Piece(char piece_type, char piece_position[2]): type(piece_type), position(&piece_position[0]) {
	this->getColour();
}

char* Piece::getPosition(){
	return position;
}

void Piece::updatePosition(char* new_position) {
	position = new_position;
}

// Define the behaviour of ostream << when dealing with the Color enum
ostream& operator<<(ostream &o, Color color){
        switch(color){
                case WHITE:
                        o << "White";
                        break;
                default: // BLACK
                        o << "Black";
                        break;
        }
        return o;
}


void Piece::getColour(){
	if (type >= 'A' && type <= 'Z') // type is uppercase
		colour = WHITE;
	else
		colour = BLACK;
}
