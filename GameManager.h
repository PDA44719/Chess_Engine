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
            Color getTurn();
            void setCastlingInformation(const char*) const;
            bool sameColorPieceAtDestination(Color, Position);
            //bool checkValidPawnMove(Color, Position);
            bool pieceInThePath(Position, const Position&, const Move&);
            bool isMoveValid(const Position&, const Position&, bool);
            Piece* makeMove(const Position&, const Position&);
            void undoLastMove(const Position&, const Position&, Piece*);
            void updateKingPosition(Piece*, Position);
            int checkCounter(Color);
            bool isCheckMateOrStaleMate(Color);
      private:
            void getRookPosition(const Move&, const Position&, Position&);
            ChessBoard* cb;
            Color turn; 
            bool previous_has_moved_state1;
            bool previous_has_moved_state2;
};

#endif
