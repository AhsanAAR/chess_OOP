#include "Rook.h"

void Rook::markValids(Piece*** Board, colors Turn) {
	clearValids();
	markHoriVert(Board,Turn);
}

void Rook::draw() {
	setcolor(WHITE);
	outtextxy(pos.x * cellSize + (cellSize / 2), pos.y * cellSize + (cellSize / 2), pieceColor == WHITE ? "R" : "r");
}

char Rook::myChar() {
	return pieceColor == WHITE ? 'R' : 'r';
}