#ifndef MOVE_H
#define MOVE_H
#include<iostream>
			
class Move {

        public:

			/**
			 * @brief Construct a new Move object
			 * 
			 * @param f_move: An int representing the file move (e.g., moving from file
			 * 'A' to 'C' would be considered a file move of +2)
			 * @param r_move: An int representing the rank move (e.g., moving from rank
			 * '8' to '5' would be considered a rank move of -3)
			 */
            Move(int f_move, int r_move);

			/**
			 * @brief Define the behaviour of the << operator, in order to print the file
			 * and rank move information of the Move object. This was mostly used for
			 * debugging purposes
			 * 
			 * @return std::ostream& 
			 */
			friend std::ostream& operator << (std::ostream&, const Move&);
			         
			/**
			 * @brief Specify the behaviour of the comparison operator, used to compare
			 * two different Move objects. It can also be used to identify the type of
			 * move (horizontal, vertical, diagonal, knight move). See the attribute
			 * explanations for more information
			 * 
			 * @return true: if both moves are the same 
			 * @return false: if the moves are different 
			 */
            bool operator==(const Move&) const;
			
			/**
			 * @brief Define the ehaviour of the multiplication operator, in order to
			 * multiply the file_move and rank_move values by a factor
			 * 
			 * @param factor: The int that will multiply file_move and rank_move
			 */
			void operator*(const int& factor);

			/**
			 * @brief Obtain the direction of a move (i.e., the smallest Move m that,
			 * when repeated N times, will be equivalent to the current Move object).
			 * Example 1: If a move is (5, 0), the value of the direction will be (1, 0).
			 * Example 2: If a move is (-3, 3), the value of the direction will be (-1, 1)
			 * 
			 * This method is important for determining if there are any pieces in the
			 * path of a move being attempted. The only exception is that, for the knight,
			 * the same value of the move will be returned (as it does not matter if there
			 * are pieces in the path due to the knight "jumping" when moving)
			 * 
			 * @return Move: the move representing the direction of the current Move
			 * object 
			 */
			Move getDirection();

			// Made Position a friend class of Move
			friend class Position;

		private:

			/**
			 * @brief Get the absolute value of an integer
			 * 
			 * @param integer: the int whose absolute value will be returned
			 * @return int: the absolute value of integer 
			 */
			static int getAbsolute(int integer);

			/**
			 * @attribute The integer representing the file move (e.g., moving from
			 * file 'A' to 'C' would be considered a file move of +2)
			 * 
			 * The value 100 is used to indicate that any integer value is allowed.
			 * Example: If a Move is 100|0, it is considerd a horizontal move and
			 * values like 1|0, 2|0, -3|0 ... will be considered to be equal to it.
			 * This is useful when trying to identify the type of move (horizontal,
			 * vertical, diagonal, knight move)
			 */
			int file_move; 

			/**
			 * @attribute The integer representing the file move (e.g., moving from
			 * file '8' to '5' would be considered a file move of -3)
			 * 
			 * The value 100 is used to indicate that any integer value is allowed.
			 * Example: If a Move is 0|100, it is considerd a vertical move and
			 * values like 0|1, 0|4, 0|-5 ... will be considered to be equal to it.
			 * This is useful when trying to identify the type of move (horizontal,
			 * vertical, diagonal, knight move)
			 */
			int rank_move; 

};

#endif
