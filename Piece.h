#ifndef PIECE_H
#define PIECE_H
#include<iostream>

enum Color {
	WHITE,
	BLACK
};

#include "Position.h"
class ChessBoard;
#include "ChessBoard.h"


std::ostream& operator << (std::ostream&, Color);
			
class Piece {

        public:
			Piece(char piece_type);
			virtual ~Piece();
			virtual void getType() = 0;
			virtual const char* returnType() = 0;
			virtual Move* getPotentialMoves() = 0;
			virtual int getPotentialMovesSize() = 0;
			virtual bool additionalConditionsMet(ChessBoard*, Position, Move);
			void setColour(char);
			Color getColour();
			bool hasMoved();
			void setHasMoved(bool);

        protected:
			Color colour;
			bool has_moved = true;

};

#endif
