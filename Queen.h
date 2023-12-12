#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
	public:

	 	/**
	 	 * @brief Construct a new Queen object
	 	 * 
	 	 * @param type: a char that informs about the type of the piece (i.e., black
		 * queen if 'Q', white if 'Q')
	 	 */
		Queen(char type);

		/**
		 * @brief Overridden version of Piece's getSymbol, used to display the unicode
		 * symbol of the queen 
		 */
		void getSymbol() override;

		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return const char*: a const char pointer containing the information about
		 * the type of queen
		 */
		const char* getType() override;

		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return int: the size of the array containing the potential moves for the queen
		 */
		int getPotentialMovesSize() override;

		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return Move*: a pointer to the first Move of the potential_moves array 
		 */
		Move* getPotentialMoves() override;

	private:

	  	/**
	  	 * @attribute An int containing the size of potential_moves for a Queen object (3)
	  	 */
		int potential_moves_size = 3;

		/**
		 * @attribute An array containing the 4 moves that a pawn could make
		 * Note: The number 100 is used to indicate any number of squares
		 */
		Move potential_moves[3] = {
			Move(0,100), // Vertical move of any number of squares
			Move(100,0), // Horizontal move of any number of squares
			Move(100,100) // Diagonal move of any number of squares
		};
};

#endif
