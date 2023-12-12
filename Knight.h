#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
	public:

	 	/**
	 	 * @brief Construct a new Knight object
	 	 * 
	 	 * @param type: a char that informs about the type of the piece (i.e., black
		 * knight if 'n', white if 'N')
	 	 */
		Knight(char type);

		/**
		 * @brief Overridden version of Piece's getSymbol, used to display the unicode
		 * symbol of the knight 
		 */
		void getSymbol() override;

		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return const char*: a const char pointer containing the information about
		 * the type of knight
		 */
		const char* getType() override;

		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return int: the size of the array containing the potential moves for the knight
		 */
		int getPotentialMovesSize();

		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return Move*: a pointer to the first Move of the potential_moves array 
		 */
		Move* getPotentialMoves();

	private:

	  	/**
	  	 * @attribute An int containing the size of potential_moves for a Knight object (8)
	  	 */
	 	int potential_moves_size = 8;

		/**
		 * @attribute An array containing the 4 moves that a knight could make. The knight
		 * moves are L-shaped, and this array contains all possible directions of that
		 * L-shaped move
		 */
		Move potential_moves[8] = {
			Move(1,2),
			Move(1,-2),
			Move(-1,2),
			Move(-1,-2),
			Move(2,1),
			Move(2,-1),
			Move(-2,1),
			Move(-2,-1)
		};
};

#endif
