/* trafficLights.h - header file for the class trafficLights */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

class Piece;
#include "Piece.h"
class GameManager;
#include "GameManager.h"

class ChessBoard {

        public:
		 	ChessBoard();
			void loadState(const char*);
			void submitMove(const char[2], const char[2]);
			void displayPieces();
			void createPiece(char, Position);
			Piece*& operator[](Position);
			Position getKingPosition(Color);
			friend class Pawn;
			friend class King;
			friend class GameManager;
			GameManager gm;
        private:
			Piece* board[8][8] = {}; // Initialize all the pointers to NULL
			Position black_king_pos;
			Position white_king_pos;
			//GameManager gm;
};

#endif
