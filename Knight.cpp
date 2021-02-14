#include "Knight.h"

void Knight::markValids(Piece*** Board, colors Turn) {
	clearValids();
	int y;
	int x;

	int dy, dx;

	y = pos.y;
	x = pos.x;
	dy = -2;
	dx = 1;
	y += dy;
	x += dx;
	if (x >= 0 && x < 8 && y >= 0 && y < 8) {
		if (Board[y][x] == nullptr || Board[y][x]->pieceColor != Turn)
			valids[y][x] = true;
	}


	y = pos.y;
	x = pos.x;
	dy = -2;
	dx = -1;
	y += dy;
	x += dx;
	if (x >= 0 && x < 8 && y >= 0 && y < 8) {
		if (Board[y][x] == nullptr || Board[y][x]->pieceColor != Turn)
			valids[y][x] = true;
	}

	y = pos.y;
	x = pos.x;
	dy = -1;
	dx = 2;
	y += dy;
	x += dx;
	if (x >= 0 && x < 8 && y >= 0 && y < 8) {
		if (Board[y][x] == nullptr || Board[y][x]->pieceColor != Turn)
			valids[y][x] = true;
	}
	y = pos.y;
	x = pos.x;
	dy = -1;
	dx = -2;
	y += dy;
	x += dx;
	if (x >= 0 && x < 8 && y >= 0 && y < 8) {
		if (Board[y][x] == nullptr || Board[y][x]->pieceColor != Turn)
			valids[y][x] = true;
	}

	y = pos.y;
	x = pos.x;
	dy = 1;
	dx = 2;
	y += dy;
	x += dx;
	if (x >= 0 && x < 8 && y >= 0 && y < 8) {
		if (Board[y][x] == nullptr || Board[y][x]->pieceColor != Turn)
			valids[y][x] = true;
	}

	y = pos.y;
	x = pos.x;
	dy = 1;
	dx = -2;
	y += dy;
	x += dx;
	if (x >= 0 && x < 8 && y >= 0 && y < 8) {
		if (Board[y][x] == nullptr || Board[y][x]->pieceColor != Turn)
			valids[y][x] = true;
	}

	y = pos.y;
	x = pos.x;
	dy = 2;
	dx = 1;
	y += dy;
	x += dx;
	if (x >= 0 && x < 8 && y >= 0 && y < 8) {
		if (Board[y][x] == nullptr || Board[y][x]->pieceColor != Turn)
			valids[y][x] = true;
	}

	y = pos.y;
	x = pos.x;
	dy = 2;
	dx = -1;
	y += dy;
	x += dx;
	if (x >= 0 && x < 8 && y >= 0 && y < 8) {
		if (Board[y][x] == nullptr || Board[y][x]->pieceColor != Turn)
			valids[y][x] = true;
	}
}


void Knight::draw() {
	setcolor(WHITE);
	outtextxy(pos.x * cellSize + (cellSize / 2), pos.y * cellSize + (cellSize / 2), pieceColor == WHITE ? "N" : "n");
}

char Knight::myChar() {
	return pieceColor == WHITE ? 'N' : 'n';
}