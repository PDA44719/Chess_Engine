chess: ChessMain.o GameManager.o ChessBoard.o Piece.o King.o Queen.o Rook.o Knight.o Bishop.o Pawn.o Position.o Move.o
	g++ -g -Wall ChessMain.o GameManager.o ChessBoard.o Piece.o King.o Queen.o Rook.o Knight.o Bishop.o Pawn.o Position.o Move.o -o chess

ChessMain.o: ChessMain.cpp ChessBoard.h
	g++ -g -Wall -c ChessMain.cpp 

GameManager.o: GameManager.cpp GameManager.h Piece.h Position.h ChessBoard.h Pawn.h King.h Rook.h Knight.h
	g++ -g -Wall -c GameManager.cpp 

ChessBoard.o: ChessBoard.cpp ChessBoard.h Piece.h GameManager.h Move.h King.h Queen.h Bishop.h Rook.h Pawn.h Knight.h Position.h
	g++ -g -Wall -c ChessBoard.cpp 

Pawn.o: Pawn.cpp Pawn.h Piece.h ChessBoard.h Move.h
	g++ -g -Wall -c Pawn.cpp 

King.o: King.cpp King.h Piece.h Rook.h
	g++ -g -Wall -c King.cpp 

Rook.o: Rook.cpp Rook.h Piece.h
	g++ -g -Wall -c Rook.cpp 

Knight.o: Knight.cpp Knight.h Piece.h
	g++ -g -Wall -c Knight.cpp 

Bishop.o: Bishop.cpp Bishop.h Piece.h
	g++ -g -Wall -c Bishop.cpp 

Queen.o: Queen.cpp Queen.h Piece.h
	g++ -g -Wall -c Queen.cpp 

Piece.o: Piece.cpp Piece.h Position.h ChessBoard.h
	g++ -g -Wall -c Piece.cpp 

Position.o: Position.cpp Position.h Move.h
	g++ -g -Wall -c Position.cpp 

Move.o: Move.cpp Move.h
	g++ -g -Wall -c Move.cpp 

clean:
	rm -f chess *.o