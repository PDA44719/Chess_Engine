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
			Piece(char piece_type, Position pos);
			//void getPosition();
			virtual void getType() = 0;
			void getColour();
			Position getPosition();
			void updatePosition(Position);
        protected:
			Position position;
			Color colour;
		private:
			char type; // You do not need to access this variable, as you only use it to extract the color

};

#endif
