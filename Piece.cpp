#include<iostream>
#include "Piece.h"
using namespace std;

Piece::Piece(char piece_type): type(piece_type) {
    this->setColour();
}

//Position Piece::getPosition(){
//	return position;
//}

//void Piece::updatePosition(Position new_position) {
//	position = new_position;
//}

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


void Piece::setColour(){
    if (type >= 'A' && type <= 'Z') // type is uppercase
        colour = WHITE;
    else
        colour = BLACK;
}

Color Piece::getColour(){
    return colour;
}

bool Piece::additionalConditionsMet(ChessBoard*, Position, Move){
    return true;
}

bool Piece::hasMoved(){
    return has_moved;
}

void Piece::setHasNotMoved(){
    has_moved = false;
}

void Piece::setHasMoved(){
    has_moved = true;
}