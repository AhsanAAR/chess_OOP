#pragma once
#include "Position.h"
#include "graphics.h"

class Game;

class Piece 
{
protected:
	virtual bool isKing() { return false; }
	friend class Game;
	virtual void draw() = 0;
	void markDiag(Piece*** Board, colors Turn);
	void markHoriVert(Piece*** Board, colors Turn);
	void markDirection(int dy, int dx, Piece*** Board, colors Turn, int limit = 8);
	static void clearValids();
public:
	static int cellSize;
	static bool valids[8][8];
	colors pieceColor;
	Position pos;
	Piece(colors pieceColor, Position pos) : pieceColor(pieceColor), pos(pos) {}
	virtual void markValids(Piece*** Board, colors Turn) = 0;
	virtual char myChar() = 0;
};