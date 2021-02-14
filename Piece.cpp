#include "Piece.h"

int Piece::cellSize = screenSize / 10;

bool Piece::valids[8][8]{false};

void Piece::markDirection(int dy, int dx, Piece*** Board, colors Turn, int limit){
	int y = pos.y;
	int x = pos.x;
	for (int i = 0; i < limit; i++) {
		y += dy;
		x += dx;
		if (!(x >= 0 && x < 8 && y >= 0 && y < 8))
			break;
		if (Board[y][x] == nullptr) {
			valids[y][x] = true;
		}
		else if (Board[y][x]->pieceColor != Turn) {
			valids[y][x] = true;
			break;
		}
		else if (Board[y][x]->pieceColor == Turn)
			break;
		
	}
}

void Piece::markDiag(Piece*** Board, colors Turn) {
	markDirection(1, 1, Board, Turn);
	markDirection(-1, 1, Board, Turn);
	markDirection(1, -1, Board, Turn);
	markDirection(-1, -1, Board, Turn);
}

void Piece::markHoriVert(Piece*** Board, colors Turn) {
	markDirection(0, 1, Board, Turn);
	markDirection(0, -1, Board, Turn);
	markDirection(1, 0, Board, Turn);
	markDirection(-1, 0, Board, Turn);
}

void Piece::clearValids() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			valids[i][j] = false;
}