#ifndef PIECE_H
#define PIECE_H
#include<iostream>

/**
 * @enum Represent one of two colours that each piece can have 
 */
enum Color {
	WHITE,
	BLACK
};

#include "Position.h"
class ChessBoard;
#include "ChessBoard.h"

/**
 * @brief Define the behavior of the << operator when encountering a Color object
 * 
 * @return std::ostream& 
 */
std::ostream& operator << (std::ostream&, Color);
			
class Piece {

        public:
		  
		 	/**
		 	 * @brief Construct a new Piece object
		 	 * 
		 	 * @param piece_type: The type of the piece (e.g., 'k' for black king, 'Q'
			 * for white queen)
		 	 */
			Piece(char piece_type);
			
			/**
			 * @brief Virtual destructor of the Piece object
			 */
			virtual ~Piece();
			
			/**
			 * @brief Virtual method to get the unicode symbol of each piece. This is
			 * used for ChessBoard's displayBoard method, which returns a visual
			 * representation of the board
			 */
			virtual void getSymbol() = 0;
			
			/**
			 * @brief Get the type of a piece (e.g., "Black's Pawn"). This metod will be
			 * used in the ChessBoard's submitMove, as a way to display information about
			 * which pieces are moving
			 * 
			 * @return const char*: a const char pointer containing the information about
			 * the type of piece
			 */
			virtual const char* getType() = 0;

			/**
			 * @brief Get the potential moves that a specific piece has.
			 * 
			 * This method is used inside GameManager's isMoveValid, to check if a move
			 * being attempted is one of the potential moves a piece has (e.g., if a pawn
			 * is trying to advance 3 ranks, it can be determined that that specific move
			 * is not one of its potential moves)
			 * 
			 * @return Move*: A pointer to the first move of the potential_moves array 
			 */
			virtual Move* getPotentialMoves() = 0;

			/**
			 * @brief Get the size of the potential_moves array (e.g., if a Pawn has 4
			 * potential moves, the value 4 will be returned).
			 * 
			 * @return int: The size/length of the potentil_moves array 
			 */
			virtual int getPotentialMovesSize() = 0;

			/**
			 * @brief Virtual method to check if there are any additional conditions that
			 * must be met in order for a potential move to be considered valid
			 * 
			 * @param cb: The ChessBoard object where the game is being played
			 * @param p: The initial Position of the Piece
			 * @param m: The Move to be completed by the piece
			 * 
			 * @return true: if the additional conditions are met. This is the default
			 * return value 
			 * @return false: if the additional conditions necessary for a potential move
			 * to be valid are not met
			 */
			virtual bool additionalConditionsMet(ChessBoard* cb, Position p, Move m);
			
			/**
			 * @brief Set the Color value of the piece's colour attribute, which can be
			 * either BLACK or WHITE
			 * 
			 */
			void setColour(char piece_type);

			/**
			 * @brief Get the color attribute
			 * 
			 * @return Color: The Color object that represent the color of the piece 
			 */
			Color getColour();

			/**
			 * @brief Determine if a piece has moved or not during the duration of the
			 * chess game. This mehod is mainly important in cases when the user wishes
			 * castle, as both the king and the rook must not have moved previously
			 * 
			 * @return true: if the piece has moved during the match 
			 * @return false: if the piece has not moved during the match
			 */
			bool hasMoved();
			
			/**
			 * @brief Set the has_moved attribute of the Piece object to the value
			 * specified as an argument to the method
			 */
			void setHasMoved(bool);

        protected:

			/**
			 * @attribute A Color object representing the color of the piece (either
			 * BLACK or WHITE) 
			 */
			Color colour;

			/**
			 * @attribute A boolean representing whether a piece has moved or not during
			 * the duration of the game. This attribute is only important for the King
			 * and Rook, as they both cannot have moved previously in order to castle
			 */
			bool has_moved = true;

};

#endif
