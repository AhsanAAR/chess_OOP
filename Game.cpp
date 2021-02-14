#include "Game.h"

void Game::Init() {
	Board = new Piece * *[8];
	for (int i = 0; i < 8; i++)
		Board[i] = new Piece * [8];
	for (int i = 0; i < 8; i++) {
		Board[1][i] = new Pawn(WHITE, Position(1, i));
		Board[6][i]= new Pawn(BLACK, Position(6, i));
		switch (i) {
		case 0:
		case 7:
			Board[0][i]= new Rook(WHITE, Position(0, i));
			Board[7][i]= new Rook(BLACK, Position(7, i));
			break;
		case 1:
		case 6:
			Board[0][i]= new Knight(WHITE, Position(0, i));
			Board[7][i]= new Knight(BLACK, Position(7, i));
			break;
		case 2:
		case 5:
			Board[0][i]= new Bishop(WHITE, Position(0, i));
			Board[7][i]= new Bishop(BLACK, Position(7, i));
			break;
		case 3:
			Board[0][i]= new Queen(WHITE, Position(0, i));
			Board[7][i]= new Queen(BLACK, Position(7, i));
			break;
		case 4:
			Board[0][i]= new King(WHITE, Position(0, i));
			Board[7][i]= new King(BLACK, Position(7, i));
			break;
		}
		Board[2][i]= nullptr;
		Board[3][i]= nullptr;
		Board[4][i]= nullptr;
		Board[5][i]= nullptr;
	}
}

void Game::drawCell(Position pos) {
	if (pos.x % 2 == pos.y % 2) 
		setfillstyle(fill_styles::SOLID_FILL, DARKGRAY);
	else 
		setfillstyle(fill_styles::SOLID_FILL, LIGHTGRAY);
	bar(pos.x * Piece::cellSize, pos.y * Piece::cellSize,
		(pos.x + 1) * Piece::cellSize, (pos.y + 1) * Piece::cellSize);
	if (Board[pos.y][pos.x] != nullptr)
		Board[pos.y][pos.x]->draw();
	if (Piece::valids[pos.y][pos.x])
		highLight(pos, GREEN);
}

void Game::drawBoard() {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			drawCell(Position(y, x));
		}
	}
}

void Game::mouseClick(Position& pos) {
	int x, y;
	do {
		do {
			if (ismouseclick(WM_LBUTTONDOWN)) {
				clearmouseclick(WM_LBUTTONDOWN);
				break;
			}
		} while (true);
		y = mousey();
		y /= Piece::cellSize;
		x = mousex();
		x /= Piece::cellSize;
		if (x >= 0 && x < 8 && y >= 0 && y < 8)
			break;
	} while (true);
	pos.x = x;
	pos.y = y;
}

bool Game::validStartPos(Position& startpos, colors Turn) {
	return (Board[startpos.y][startpos.x] != nullptr && Board[startpos.y][startpos.x]->pieceColor == Turn);
}

colors operator!(colors Turn) {
	return Turn == WHITE ? BLACK : WHITE;
}

bool Game::check(colors Turn) {
	Position kingPos = findKing(Turn);
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (Board[y][x] != nullptr && Board[y][x]->pieceColor != Turn) {
				Board[y][x]->markValids(Board, !Turn);
				if (Piece::valids[kingPos.y][kingPos.x])
					return true;
			}
		}
	}
	return false;
}

Position Game::findKing(colors kingColor) {
	for (int y = 0; y < 8; y++)
		for (int x = 0; x < 8; x++)
			if (Board[y][x] != nullptr && Board[y][x]->isKing() && Board[y][x]->pieceColor == kingColor)
				return Position(y, x);
	return Position(-1, -1);
}

bool Game::validEndPos(Position& endpos, colors Turn) {
	return (Board[endpos.y][endpos.x] == nullptr || Board[endpos.y][endpos.x]->pieceColor != Turn);
}

void Game::highLight(Position pos, colors color) {
	setlinestyle(line_styles::SOLID_LINE, 0, 7);
	setcolor(color);
	rectangle(pos.x * Piece::cellSize, pos.y * Piece::cellSize,
		(pos.x + 1) * Piece::cellSize, (pos.y + 1) * Piece::cellSize);
}

void Game::highLightValids() {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (Piece::valids[y][x])
				highLight(Position(y, x), GREEN);
		}
	}
}
