#ifndef PIECE_H
#define PIECE_H

enum Color {
	WHITE,
	BLACK
};

class Piece {

        public:
			Piece(char piece_type, char piece_position[2]);
			//void getPosition();
			void getType();
			void getColour();
        protected:
			char *position;
			char type;
			Color colour;

};

#endif
