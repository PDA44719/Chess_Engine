#include<iostream>
#include "Piece.h"
using namespace std;

Piece::Piece(char piece_type){
    this->setColour(piece_type);
}

Piece::~Piece(){}

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

void Piece::setColour(char piece_type){
    if (piece_type >= 'A' && piece_type <= 'Z') // piece_type is uppercase
        colour = WHITE;
    else // piece_type is lowercase
        colour = BLACK;
}

Color Piece::getColour(){
    return colour;
}

bool Piece::additionalConditionsMet(ChessBoard*, Position, Move){
    return true; // Default behaviour of the virtual method
}

bool Piece::hasMoved(){
    return has_moved;
}

void Piece::setHasMoved(bool value){
    has_moved = value;
}
