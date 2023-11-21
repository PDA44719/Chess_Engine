/* trafficLights.h - header file for the class trafficLights */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Piece.h"

class ChessBoard {

        public:
			void loadState(char*);
			void submitMove(char*, char*);
			void displayPositions();
        private:
			char* FEN_string;
			Piece *pieces[16];


};

#endif
