#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
	public:

	 	/**
	 	 * @brief Construct a new Rook object
	 	 * 
	 	 * @param type: a char that informs about the type of the piece (i.e., black
		 * rook if 'r', white if 'R')
	 	 */
		Rook(char type);

		/**
		 * @brief Overridden version of Piece's getSymbol, used to display the unicode
		 * symbol of the rook 
		 */
		void getSymbol() override;

		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return const char*: a const char pointer containing the information about
		 * the type of rook
		 */
		const char* getType() override;

		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return int: the size of the array containing the potential moves for the rook 
		 */
		int getPotentialMovesSize() override;

		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return Move*: a pointer to the first Move of the potential_moves array 
		 */
		Move* getPotentialMoves() override;

		// Made GameManager a friend class of Rook
		friend class GameManager;

	private:

	  	/**
	  	 * @attribute An int containing the size of potential_moves for a Rook object (2)
	  	 */
	 	int potential_moves_size = 2; 

		/**
		 * @attribute An array containing the 2 moves that a rook could make
		 * Note: The number 100 is used to indicate any number of squares
		 */
		Move potential_moves[2] = {
			Move(100,0), // Horizontal move of any number of squares
			Move(0,100)  // Vertical move of any nuumber of squares
		};
};

#endif
