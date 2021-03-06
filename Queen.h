#pragma once
#include "Piece.h"

class Queen :
	public Piece
{
private:
	friend class Game;
	Queen(colors pieceColor, Position pos) : Piece(pieceColor, pos) {}

	virtual void markValids(Piece*** Board, colors Turn) override;
	virtual void draw() override;
	virtual char myChar() override;
};

