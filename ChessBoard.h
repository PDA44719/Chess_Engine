#ifndef CHESSBOARD_H
#define CHESSBOARD_H
class Piece;
#include "Piece.h"
class GameManager;
#include "GameManager.h"

class ChessBoard {

        public:

			/**
			 * @brief Construct a new ChessBoard object
			 */
		 	ChessBoard();
			
			/**
			 * @brief Destroy the ChessBoard object
			 */
			~ChessBoard();
			
			/**
			 * @brief Load a new board state, given a FEN string represenation of the board.
			 * Note: As the students were told, it is assumed that the given FEN string is
			 * a valid one. An invalid string could lead to code errors
			 * 
			 * @param FEN_string: A pointer to a the first element of a char array
			 * containing the FEN string
			 */
			void loadState(const char* FEN_string);
			
			/**
			 * @brief Submit a move to be made on the board
			 * 
			 * @param initial_position: A char array representing the initial position of
			 * the piece to be moved
			 * @param final_position: A char array representing the final position of
			 * that the piece will be moved to
			 */
			void submitMove(const char initial_position[2], const char final_position[2]);
			
			/**
			 * @brief Display a 2D representation of the current board state. Each piece
			 * will be represented by its unicode symbol 
			 */
			void displayPieces();

			/**
			 * @brief Given a character representing the piece to be created and the
			 * Position where the piece must be placed, create a Piece object at that
			 * location
			 * 
			 * Example: createPiece('R', Position("A8")) will create a white Rook and
			 * place it at board[0][0] (i.e., Position A8)
			 */
			void createPiece(char, Position);

			/**
			 * @brief Define the behaviour of the [] operator for the ChessBoard object.
			 * This overloading is VERY important, as it will be used to retrieve the
			 * Piece pointers from different locations of the board attribute, indexing
			 * with a Position instead of using a pair of integers
			 * 
			 * @param p: The Position object of the Piece pointer to be retrieved
			 * 
			 * @return Piece*&: A reference to the pointer that points to the Piece 
			 * object stored at the given position. If the pointer if NULL, the position
			 * is empty. Otherwise, there is a piece at that square
			 */
			Piece*& operator[](Position p);

			/**
			 * @brief Get the position of the king given the color of the king that is
			 * being looked for
			 * 
			 * @return Position: The position where the king lies 
			 */
			Position getKingPosition(Color);

			// Made Pawn a friend class of ChessBoard
			friend class Pawn;

			// Made King a friend class of ChessBoard
			friend class King;

			// Made GameManager a friend class of ChessBoard
			friend class GameManager;

        private:
		 
		 	/**
		 	 * @attribute A 2D array of Piece pointers pointing to the Pieces
			 * stored at each position of the chessboard.
			 * 
			 * If an element is NULL, it means that there is no Piece at that
			 * position/square. Otherwise, there is a piece at that position
		 	 */
			Piece* board[8][8] = {}; // Initialize all the pointers to NULL
			
			/**
			 * @attribute The position of the black king on the board
			 */
			Position black_king_pos;
			
			/**
			 * @attribute The position of the white king on the board 
			 */
			Position white_king_pos;
			
			/**
			 * @brief An instance of the GameManager class, which will store the logic
			 * for determining the validity of moves, making moves, looking for checks...
			 */
			GameManager gm;
};

#endif
