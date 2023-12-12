#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
	public:

	 	/**
	 	 * @brief Construct a new King object
	 	 * 
	 	 * @param type: a char that informs about the type of the piece (i.e., black
		 * king if 'k', white if 'K')
	 	 */
		King(char type);

		/**
		 * @brief Overridden version of Piece's getSymbol, used to display the unicode
		 * symbol of the king 
		 */
		void getSymbol() override;

		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return const char*: a const char pointer containing the information about
		 * the type of king
		 */
		const char* getType() override;

		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return int: the size of the array containing the potential moves for the king 
		 */
		int getPotentialMovesSize() override;

		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return Move*: a pointer to the first Move of the potential_moves array 
		 */
		Move* getPotentialMoves() override;

		/**
		 * @brief Overridden method from Piece. In this case, this method will be used to
		 * check if all conditions for a Castling move have been met
		 * 
		 * @param cb: The ChessBoard object where the game is being played
		 * @param p: The initial Position of the King
		 * @param m: The Move to be completed by the king
		 * 	
		 * @return true: if the additional conditions for a valid king move have been met 
		 * @return false: if the conditions were not met 
		 */
		bool additionalConditionsMet(ChessBoard* cb, Position p, Move m);

		// Made GameManager a friend class of King
		friend class GameManager;

	private:

	  	/**
	  	 * @attribute An int containing the size of potential_moves for a King object (10)
	  	 */
		int potential_moves_size = 10;

		/**
		 * @attribute An array containing the 10 moves that a king could make. The king
		 * can alway advance by one square, whether diagonal, vertical or horizontal.
		 * Addionally, it can also make a horizontal move of two squares (in the case
		 * where it is trying to castle)
		 */
		Move potential_moves[10] = {
			// vertical moves
			Move(0,1),
			Move(0,-1),
			// Horizontal moves
			Move(1,0),
			Move(-1,0),

			// Diagonal moves
			Move(1,1),
			Move(-1,-1),
			Move(1,-1),
			Move(-1,1),
			
			// Castling moves
			Move(2,0),
			Move(-2,0)
		};
};

#endif
