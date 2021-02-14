#include "King.h"

void King::markValids(Piece*** Board, colors Turn) {
	clearValids();
	markDirection(-1, 0, Board, Turn, 1);
	markDirection(-1, 1, Board, Turn, 1);
	markDirection(0, 1, Board, Turn, 1);
	markDirection(1, 1, Board, Turn, 1);
	markDirection(1, 0, Board, Turn, 1);
	markDirection(1, -1, Board, Turn, 1);
	markDirection(0, -1, Board, Turn, 1);
	markDirection(-1, -1, Board, Turn, 1);
}
void King::draw() {
	setcolor(WHITE);
	outtextxy(pos.x * cellSize + (cellSize / 2), pos.y * cellSize + (cellSize / 2), pieceColor == WHITE ? "K" : "k");
}

char King::myChar() {
	return pieceColor == WHITE ? 'K' : 'k';
}

bool King::isKing(){
	return true;
}