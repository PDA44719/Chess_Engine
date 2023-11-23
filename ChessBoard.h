/* trafficLights.h - header file for the class trafficLights */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Piece.h"

class ChessBoard {

        public:
			void loadState(const char*);
			void submitMove(char*, char*);
			void getInitialPieces();
			void displayPieces();
			void createPiece(int, char, char[2]);
        private:
			const char *FEN_string;
			Piece *pieces[32];
};

#endif
