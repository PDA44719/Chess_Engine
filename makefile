chess: tester.cpp GameManager.cpp ChessBoard.cpp Piece.cpp King.cpp Queen.cpp Rook.cpp Knight.cpp Bishop.cpp Pawn.cpp Position.cpp Move.cpp
	g++ -g -Wall tester.cpp GameManager.cpp ChessBoard.cpp Piece.cpp King.cpp Queen.cpp Rook.cpp Knight.cpp Bishop.cpp Pawn.cpp Position.cpp Move.cpp -o chess

clean:
	rm -f chess *.o