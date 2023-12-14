## Repository for Chess Assignment
This is the repository for the Chess Coursework. The structure is as follows:

- Abstract class **Piece**, which all the child piece classes will inherit from.
- Child classes for each type of piece (**Pawn**, **King**, **Queen**, **Rook**, **Knight**, **Bishop**). All of these classes have a potential_moves array containing the different moves each piece can potentially make (they need to be validated before an actual move is made). If any additional conditions are needed for moves to be valid (e.g., Pawn can only move diagonally when taking an opposing piece), the additionalConditionsMet method will check them.
- A **Position** class, that will be used to store the file and rank information of the pieces.
- A **Move** class, which will be used in conjunction with the Position class in order to describe the different possible moves on the board.
- A **ChessBoard** class to store all the Pieces on the board. It has a board attribute, containing Piece pointers (NULL indicates empty square, otherwise a piece is present at that square). Besides the methods indicated in ChessMain.cpp, there are some additional ones like displayPieces, which will show a 2D representation of the board on the screen.
- A **GameManager** class, which will carry out most of the computations associated with checking the validity of moves, looking for checks, checking the turn, making moves...

Besides the basic functionality, a solution for **Castling has also been implemented**. Pawn promotion and En Passant were not implemented.

The code has been documented in detail. Please refer to the comments in the files for clarifications (header files will be specially helpful for understanding what each function is utilized for).