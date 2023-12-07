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
            void updateTurn();
            bool sameColorPieceAtDestination(Color, Position);
            //bool checkValidPawnMove(Color, Position);
            bool pieceInThePath(Position, const Position&, const Move&);
            bool isMoveValid(const Position&, const Position&);
            int checkCounter(const Position&, Color);
            bool isCheckMateOrStaleMate(Color);
      private:
            ChessBoard* cb;
            Color turn; 
};

#endif
