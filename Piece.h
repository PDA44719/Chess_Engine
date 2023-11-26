#ifndef PIECE_H
#define PIECE_H
#include<iostream>
#include "Position.h"

enum Color {
	WHITE,
	BLACK
};

std::ostream& operator << (std::ostream&, Color);
			
class Piece {

        public:
			Piece(char piece_type);
			//void getPosition();
			virtual void getType() = 0;
			virtual Move* getValidMoves() = 0;
			virtual int getValidMovesSize() = 0;
			void setColour();
			Color getColour();
        protected:
			Color colour;
		private:
			char type; // You do not need to access this variable, as you only use it to extract the color

};

#endif
