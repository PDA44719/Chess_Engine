#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include<iostream>
#include "Piece.h"
#include "Position.h"

class ChessBoard;

class GameManager {
        public:
            GameManager(ChessBoard*);
            void setTurn(char);
            bool checkTurn(Piece*); // Determine whose turn it is to move 
            //bool checkValidPawnMove(Color, Position);
		private:
            ChessBoard* cb;
            Color turn; 
};

#endif
