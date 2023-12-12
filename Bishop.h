#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
	public:
	 	/**
	 	 * @brief Construct a new Bishop object
	 	 * 
	 	 * @param type: a char that informs about the type of the piece (i.e., black
		 * bishop if 'b', white if 'B')
	 	 */
		Bishop(char type);

		/**
		 * @brief Overridden version of Piece's getSymbol, used to display the unicode
		 * symbol of the bishop 
		 */
		void getSymbol() override;

		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return const char*: a const char pointer containing the information about
		 * the type of bishop
		 */
		const char* getType() override;

		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return int: the size of the array containing the potential moves for the bishop 
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
	  	 * @attribute An int containing the size of potential_moves for a Bishop object (1)
	  	 */
	 	int potential_moves_size = 1;

		/**
		 * @attribute An array containing the 1 moves that a bishop could make
		 * Note: The number 100 is used to indicate any number of squares
		 */
		Move potential_moves[1] = {
			Move(100,100) // Diagonal move of any number of squares
		};
};

#endif
