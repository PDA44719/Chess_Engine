/* trafficLights.h - header file for the class trafficLights */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Piece.h"
#include "GameManager.h"

class ChessBoard {

        public:
		 	ChessBoard();
			void loadState(const char*);
			void submitMove(char[2], char[2]);
			void getInitialBoard(const char*);
			void displayPieces();
			void createPiece(char, Position);
        private:
			Piece* board[8][8] = {}; // Initialize all the pointers to NULL
			GameManager gm;
};

#endif
