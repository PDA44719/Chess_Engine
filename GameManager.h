#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include<iostream>
#include "Piece.h"
#include "Position.h"

class ChessBoard;

class GameManager {

        public:
            
            /**
             * @brief Construct a new GameManager object
             * 
             * @param chess_board: a pointer to the chessboard that the object will be
             * managing 
             */
            GameManager(ChessBoard* chess_board);
            
            /**
             * @brief Given the FEN string character that informs about which player's
             * turn it is, set the turn attribute to that color
             */
            void setTurn(char);
            
            /**
             * @brief Check that the given piece is of the same color as the turn
             * attribute
             * 
             * @return true: If the Piece's color is the same as turn, and hence
             * could move
             * @return false: Otherwise (i.e., the piece would not be allowed to
             * move) 
             */
            bool checkTurn(Piece*); // Determine whose turn it is to move 
            
            /**
             * @brief Update the turn attribute. After every move, the turn must be
             * updated in order to allow the other player to make a move
             */
            void updateTurn();
            
            /**
             * @brief Get the value of turn
             * 
             * @return Color: The Color object representing whose turn it is to move 
             */
            Color getTurn();
            
            /**
             * @brief Given a pointer to the portion of the FEN string that informs
             * about castling availability, modify the has_moved attributes for the
             * different King and Rook objects (i.e., castling can only take place
             * if it is the first move for both the king and rook involved).
             * 
             * NOTE: This method assumes that a correct FEN string was provided.
             * Students were told a valid one would be provided
             */
            void setCastlingInformation(const char*) const;
            
            /**
             * @brief Given a Color and a board Position, check if there is a piece
             * of the same colour at that position. This method is used to prevent
             * pieces from accidentally taking a piece from the same player
             * 
             * @return true: If there is a piece of the same colour at that position 
             * @return false: If the position is either empty or occupied by a piece
             * of a different colour 
             */
            bool sameColorPieceAtDestination(Color, Position);
            
            /**
             * @brief Check if there are any pieces in the path from starting to 
             * destination. This method is used to ensure pieces do not "jump" over other
             * pieces when getting to their destination
             * 
             * @param starting: The starting piece Position 
             * @param destination: The destination Position of the piece 
             * @param m: In the case of this function, this is the direction of the move
             * that the player is attempting (for more information see Move.h) 

             * @return true: If there is a piece in the path
             * @return false: If the path is empty and hence the piece is can move to the
             * destination 
             */
            bool pieceInThePath(Position starting, const Position& destination, const Move& m);
            
            /**
             * @brief Determine if a move being attempted is valid
             * 
             * @param p: The initial Position of the piece to be moved 
             * @param final_p: The Position the piece is attempting to move to 
             * @param after_check: A boolean attribute that informs about whether, in the
             * case of a valid move, it is necessary to determine if the move will lead to
             * check. There are cases (e.g., when looking for checks on a specific king)
             * where we do not care if a piece that can take that king may leave its own
             * king unprotected. True means count the number of checks after a move, false
             * means ignore that
             * 
             * @return true: If the move is valid and hence can be completed 
             * @return false: If the move is invalid 
             */
            bool isMoveValid(const Position& p, const Position& final_p, bool after_check);

            /**
             * @brief Move both the king and the rook from their initial position to their
             * final positions. This method is used both when making a castling move and
             * when undoing a castling move (in order to check the validity of moves, they
             * will be done and then undone to determine if they may lead to check)
             * 
             * @param initial_k_pos: The starting Position of the king 
             * @param final_k_pos: The final Position of the king  
             * @param initial_r_pos: The initial Position of the rook  
             * @param final_r_pos: The final Position of the rook   
             * @param undo: A boolean that informs about whether the castling is to be
             * completed (false) or undone (true). This is important because, when undoing
             * a castling move, both the king and the rook's has_moved attribute needs to
             * be restored to their previous state. Otherwise, the GameManager will believe
             * both pieces have already moved and cannot castle
             */
            void castle(const Position& initial_k_pos, const Position& final_k_pos,
				const Position& initial_r_pos, const Position& final_r_pos, bool undo);
            
            /**
             * @brief Move the piece stored at position p to position final_p
             * 
             * @param p: The inital Position of the piece
             * @param final_p: The Position the piece will be moved to  
             *
             * @return Piece*: The Piece pointer stored at that position of the board.
             * This is important because, after making a move, it is necessary to know
             * if a piece was previously at the final position (both in cases of undoing
             * moves and to print out the piece that was taken on the terminal)
             */
            Piece* makeMove(const Position& p, const Position& final_p);

            /**
             * @brief Undo the last move that was made
             * 
             * @param p: The initial Position of the previous move 
             * @param final_p: The final Position of the last move
             * @param previous: The Piece* that was previously stored at that board
             * position (e.g., if there was a piece at that position, this pointer
             * will allow the method to restore that piece)
             */
            void undoLastMove(const Position& p, const Position& final_p, Piece* previous);
            
            /**
             * @brief Update the position of the king. As the position of the king is
             * an attribute stored inside ChessBoard, it is necessary to update that
             * position should the king be moved
             * 
             * @param king: The Piece* pointing to the king that will be moved 
             * @param new_position: the new position of that king 
             */
            void updateKingPosition(Piece* king, Position new_position);
            
            /**
             * @brief Count the number of checks on a king, which is specified by
             * passing its color as an argument
             * 
             * @return int: The number of checks on the specified king 
             */
            int checkCounter(Color);

            /**
             * @brief Given the Color of a king, check if that king is in checkmate or
             * stalemate
             * 
             * @return true: The king is in checkmate or stalemate
             * @return false: The king is neither in checkmate nor stalemate 
             */
            bool isCheckMateOrStaleMate(Color);
            
            /**
             * @brief Given a move and a position determine if the move that is being
             * attempted/was attempted was a castling move. If it was, return the
             * initial position of the rook associated with that move
             * 
             * @param m: The Move that is being attempted/was attempted 
             * @param piece_pos: The initial posititon of the piece 
             * @param rook_pos: The position of the rook. Initially, the Position is set
             * to an invalid value (i.e., Position("XX")). If the move is/was a castling
             * move, then this value will be modified to the starting position of the
             * rook. If the move was not a castling move, then this value will remain
             * Position("XX")
             */
            void getRookPosition(const Move& m, const Position& piece_pos, Position& rook_pos);

      private:
            
            /**
             * @attribute A pointer to the ChessBoard object containing all the pieces
             */
            ChessBoard* cb;

            /**
             * @attribute A Color containing the color of the player's turn (i.e., if
             * turn is WHITE, then white player to move)
             */
            Color turn; 

            /**
             * @attribute A boolean variable storing the previous has_moved value from
             * the last piece that was moved. This attribute is really important when
             * undoing moves, as the has_moved value needs to be restored to its previous
             * value (important for checking the validity of castling moves)
             */
            bool previous_has_moved_state1;

            /**
             * @attribute A boole storing the previous has_moved state of the rook
             * involved in the last castling move made. For most moves, only
             * previous_has_moved_state1 will be used (as only one piece is moved).
             * However, as two pieces move when castling, this second attribute will be
             * used to store has_moved's value for the rook
             */
            bool previous_has_moved_state2;
};

#endif
