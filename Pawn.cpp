#include "Pawn.h"


void Pawn::markValids(Piece*** Board, colors Turn){
	clearValids();
	int length, dir;
	if (pieceColor == WHITE) {
		dir = 1;
		if (pos.y == 1)
			length = 2;
		else
			length = 1;
	}
	else {
		dir = -1;
		if (pos.y == 6)
			length = 2;
		else
			length = 1;
	}
	int y = pos.y;
	for (int i = 0; i < length; i++) {
		y += dir;
		if(y >= 0 && y < 8 && Board[y][pos.x] == nullptr)
			valids[y][pos.x] = true;
		else
			break;
	}
	int x;
	y = pos.y + dir;
	x = pos.x + 1;
	if (y >= 0 && y < 8 && x >= 0 && x < 8) {
		if (Board[y][x] != nullptr && Board[y][x]->pieceColor != Turn)
			valids[y][x] = true;
	}
	y = pos.y + dir;
	x = pos.x - 1;
	if (y >= 0 && y < 8 && x >= 0 && x < 8) {
		if (Board[y][x] != nullptr && Board[y][x]->pieceColor != Turn)
			valids[y][x] = true;
	}
}
void Pawn::draw() {
	setcolor(WHITE);
	outtextxy(pos.x * cellSize + (cellSize / 2), pos.y * cellSize + (cellSize / 2), pieceColor == WHITE ? "P" : "p");
}

char Pawn::myChar() {
	return pieceColor == WHITE ? 'P' : 'p';
}