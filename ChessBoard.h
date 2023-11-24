/* trafficLights.h - header file for the class trafficLights */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Piece.h"

class ChessBoard {

        public:
			void loadState(const char*);
			void submitMove(char[2], char[2]);
			void getInitialPieces();
			void displayPieces();
			void createPiece(int, char, Position);
        private:
			const char *FEN_string;
			Piece *pieces[32];
};

#endif
