#include "Queen.h"

void Queen::markValids(Piece*** Board, colors Turn) {
	clearValids();
	markDiag(Board,Turn);
	markHoriVert(Board, Turn);
}

void Queen::draw() {
	setcolor(WHITE);
	outtextxy(pos.x * cellSize + (cellSize / 2), pos.y * cellSize + (cellSize / 2), pieceColor == WHITE ? "Q" : "q");
}

char Queen::myChar() {
	return pieceColor == WHITE ? 'Q' : 'q';
}