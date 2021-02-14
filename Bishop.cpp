#include "Bishop.h"

void Bishop::markValids(Piece*** Board, colors Turn) {
	clearValids();
	markDiag(Board,Turn);
}

void Bishop::draw() {
	setcolor(WHITE);
	outtextxy(pos.x * cellSize + (cellSize / 2), pos.y * cellSize + (cellSize / 2), pieceColor == WHITE ? "B" : "b");
}

char Bishop::myChar(){
	return pieceColor == WHITE ? 'B' : 'b';
}

