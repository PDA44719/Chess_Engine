#ifndef POSITION_H
#define POSITION_H
#include<iostream>
#include "Move.h"
			
class Position {

        public:

			/**
			 * @brief Construct a new Position object, with a given position
			 * 
			 * @param position: a char array containing the file and rank of the position 
			 */
			Position(const char* position);
			
			/**
			 * @brief Construct a new Position object with an invalid position. As no
			 * position is specified, it defaults to file='X', rank='X'. A position 'XX'
			 * is considered invalid
			 */
			Position();
			
			/**
			 * @brief Define the behavior of the comparison operator, in order to compare
			 * two positions
			 * 
			 * @return true: if the two positions are the same
			 * @return false: if the positions differ
			 */
			bool operator==(const Position&) const;
			
			/**
			 * @brief Specify the behaviour of the not equal to operator, to check that
			 * two positions are not the same
			 * 
			 * @return true: If the positions are not the same 
			 * @return false: If the positions are the same 
			 */
			bool operator!=(const Position&) const;
			
			/**
			 * @brief Define the behaviour of the assignment operator, in order to set
			 * a position to be equal to another
			 */
			void operator=(const Position&);
			
			/**
			 * @brief Specify the behaviour of the subtraction operator, in order to
			 * return the move that results from moving (i.e., subtracting) from an
			 * initial position to a final position
			 * 
			 * @param initial_pos: the inital position that will be subtracted from
			 * the current Position object
			 * 
			 * @return Move: The resulting move to go from initial to final position
			 */
			Move operator-(const Position& initial_pos) const;

			/**
			 * @brief Define the behaviour of the addition operator, in order to 
			 * add a move to the current Position object. This will return a new
			 * position.
			 * 
			 * This operator can be thought of as moving the initial position by the
			 * attributes specified in the Move object
			 * 
			 * @return Position: The position resulting from the move
			 */
			Position operator+(const Move&) const;

			/**
			 * @brief Specify the behaviour of the << operator, to properly display
			 * the file and rank of a position
			 * 
			 * This method was mainly used for debugging purposes
			 * 
			 * @return std::ostream& 
			 */
			friend std::ostream& operator << (std::ostream&, const Position&);

			/**
			 * @brief Move the Position object from its initial value to a value
			 * specified by amount_to_move
			 * 
			 * When you specify how much to move, the position will move along the
			 * different files. Once you reach the last file (i.e., 'H'), to continue
			 * moving the position will go to the next rank. Once the position is out
			 * of bounds (i.e., you have gone through all files and ranks), it will be
			 * invalidated ('XX')
			 * 
			 * @param amount_to_move: a char representing how much to move the position
			 * by. It can take on values from '1' to '8' (which are the characters used
			 * in FEN strings to depict empty squares)
			 * 
			 */
			void move(char amount_to_move);

			/**
			 * @brief Get the file of the position
			 * 
			 * @return char: The char representing the file
			 */
			char getFile();

			/**
			 * @brief Get the rank of the position
			 * 
			 * @return char: The char representing the rank 
			 */
			char getRank() const;

			/**
			 * @brief Check whether the Position object contains a valid position or an
			 * invalid one
			 * 
			 * @return true: If the position is a valid chessboard position
			 * @return false: If the position is invalid (i.e., 'XX') 
			 */
			bool isValid();

		private:

			/**
			 * @attribute A char representing the file of the Position. From 'A' to 'H'
			 * if the position is valid. 'X' if the position is invalid
			 */
			char piece_file; 

			/**
			 * @attribute A char representing the rank of the Position. From '1' to '8'
			 * if the position is valid. 'X' if the position is invalid
			 */
			char piece_rank; 

};

#endif
