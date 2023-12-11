#include<iostream>
#include "Piece.h"
using namespace std;

Piece::Piece(char piece_type){
    this->setColour(piece_type);
}

Piece::~Piece(){}

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

void Piece::setColour(char type){
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

void Piece::setHasMoved(bool value){
    has_moved = value;
}
