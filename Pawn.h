#pragma once
#include "Piece.h"

class Pawn :
	public Piece
{
private:
	friend class Game;
	Pawn(colors pieceColor, Position pos) : Piece(pieceColor, pos){}

	virtual void markValids(Piece*** Board, colors Turn) override;
	virtual void draw() override;
	virtual char myChar() override;
};

