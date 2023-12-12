#include "Move.h"
#include<iostream>
using namespace std;

Move::Move(int f_move, int r_move) : file_move(f_move), rank_move(r_move){}

ostream& operator << (ostream& o, const Move& m){
    o << m.file_move << "|" << m.rank_move;
    return o;
}

bool Move::operator==(const Move& m) const {
    // Check if a move is diagonal by ensuring that the absolute
    // value of the file and the rank moves is the same
    if (m.file_move == 100 && m.rank_move == 100){ 
        return getAbsolute(file_move) == getAbsolute(rank_move);
    }

    // Check if a move is horizontal by ensuring the rank move is 0
    if (m.file_move == 100)
        return rank_move == 0; 

    // Check if a move is vertical by ensuring the file move is 0
    if (m.rank_move == 100) 
        return file_move == 0; 
    
    // For any other move, just ensure the file and rank moves are the same
    return file_move == m.file_move && rank_move == m.rank_move;
}

void Move::operator*(const int& multiplier){
    file_move *= multiplier;
    rank_move *= multiplier;
}

Move Move::getDirection(){
    if (getAbsolute(file_move) == getAbsolute(rank_move)) // diagonal move
        return Move(file_move/getAbsolute(file_move), rank_move/getAbsolute(rank_move));
    if (rank_move == 0 && file_move != 0) // horizontal move
        return Move(file_move/getAbsolute(file_move), 0);
    if (file_move == 0 && rank_move != 0) // vertical move
        return Move(0, rank_move/getAbsolute(rank_move));
    else // Knight move
        return *this;
}

int Move::getAbsolute(int i){
    return i<0 ? -i : i; 
}