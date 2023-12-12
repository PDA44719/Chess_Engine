#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include "ChessBoard.h"

class Pawn : public Piece {
	public:

	 	/**
	 	 * @brief Construct a new Pawn object
	 	 * 
	 	 * @param type: a char that informs about the type of the piece (i.e., black
		 * pawn if 'p', white if 'P')
	 	 */
		Pawn(char type);
		
		/**
		 * @brief Overridden version of Piece's getSymbol, used to display the unicode
		 * symbol of the pawn 
		 */
		void getSymbol() override;
		
		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return const char*: a const char pointer containing the information about
		 * the type of pawn
		 */
		const char* getType() override;
		
		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return int: the size of the array containing the potential moves for the pawn 
		 */
		int getPotentialMovesSize() override;
		
		/**
		 * @brief Overridden method from Piece
		 * 
		 * @return Move*: a pointer to the first Move of the potential_moves array 
		 */
		Move* getPotentialMoves() override;
		
		/**
		 * @brief Overridden method from Piece
		 * 
		 * @param cb: The ChessBoard object where the game is being played
		 * @param p: The initial Position of the Pawn
		 * @param m: The Move to be completed by the pawn
		 * 	
		 * @return true: if the additional conditions for a valid pawn move have been met 
		 * @return false: if the conditions were not met 
		 */
		bool additionalConditionsMet(ChessBoard* cb, Position p, Move m) override;

	private:

	  	/**
	  	 * @attribute An int containing the size of potential_moves for a Pawn object (4)
	  	 */
	 	int potential_moves_size = 4;
		
		/**
		 * @attribute An array containing the 4 moves that a pawn could make
		 */
		Move potential_moves[4] = {
			Move(0, 1), // Vertical move of one squares
			Move(0, 2), // Vertical move of two squares
			Move(1, 1), // Right diagonal move of one square
			Move(-1, 1) // Left diagonal move of one square
		};
};

#endif
