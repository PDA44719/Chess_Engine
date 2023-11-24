#ifndef PIECE_H
#define PIECE_H
#include<iostream>

enum Color {
	WHITE,
	BLACK
};

std::ostream& operator << (std::ostream&, Color);
			
class Piece {

        public:
			Piece(char piece_type, char piece_position[2]);
			//void getPosition();
			virtual void getType() = 0;
			void getColour();
			char* getPosition();
			void updatePosition(char*);
        protected:
			char *position;
			Color colour;
		private:
			char type; // You do not need to access this variable, as you only use it to extract the color

};

#endif
