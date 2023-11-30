#include "Move.h"
#include<iostream>
using namespace std;

Move::Move(int f_move, int r_move) : file_move(f_move), rank_move(r_move){}

ostream& operator << (ostream& o, const Move& m){
    o << m.file_move << "|" << m.rank_move;
    return o;
}

bool Move::operator==(const Move& m) const {
    if (m.file_move == 100 && m.rank_move == 100){ // diagonal move
        return getAbsolute(file_move) == getAbsolute(rank_move);
    }
    if (m.file_move == 100) // horizontal move
        return rank_move == 0;  // ensure that you are only moving horizontally
    if (m.rank_move == 100) // vertical move
        return file_move == 0; // Ensure you are only moving vertically
    return file_move == m.file_move && rank_move == m.rank_move;

}

void Move::operator*(const int& multiplier){
    file_move *= multiplier;
    rank_move *= multiplier;
}

// This move will return the increment of an overall move (i.e., for a move)
Move Move::getDirection(){
    if (file_move == rank_move) // diagonal move
        return Move(file_move/getAbsolute(file_move), rank_move/getAbsolute(rank_move));
    if (rank_move == 0 && file_move != 0) // horizontal move
        return Move(file_move/getAbsolute(file_move), 0);
    if (file_move == 0 && rank_move != 0) // vertical move
        return Move(0, rank_move/getAbsolute(rank_move));
    else // This would be a knight move
        return *this;

}

int Move::getAbsolute(int i){
    return i<0 ? -i : i; 
}