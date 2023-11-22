#ifndef PIECE_H
#define PIECE_H

class Piece {

        public:
			Piece(char piece_type, char piece_position[2]);
			//void getPosition();
			void getType();
        private:
			char *position;
			char type;

};

#endif
