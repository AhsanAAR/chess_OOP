#pragma once
#include "Piece.h"
class King :
	public Piece
{
private:
	friend class Game;
	King(colors pieceColor, Position pos) : Piece(pieceColor, pos) {}
	bool isKing() override;
	virtual void markValids(Piece*** Board, colors Turn) override;
	virtual void draw() override;
	virtual char myChar() override;
};

