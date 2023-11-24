#include<iostream>
#include "Piece.h"
using namespace std;

Piece::Piece(char piece_type, Position pos): type(piece_type), position(pos) {
	this->getColour();
}

Position Piece::getPosition(){
	return position;
}

void Piece::updatePosition(Position new_position) {
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
