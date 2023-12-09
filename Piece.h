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
			//void getPosition();
			virtual void getType() = 0;
			virtual const char* returnType() = 0;
			virtual Move* getValidMoves() = 0;
			virtual int getValidMovesSize() = 0;
			virtual bool additionalConditionsMet(ChessBoard*, Position, Move);
			void setColour();
			Color getColour();
			bool hasMoved();
			void setHasMoved(bool);

        protected:
			Color colour;
			bool has_moved = true;
		private:
			char type; // You do not need to access this variable, as you only use it to extract the color

};

#endif
