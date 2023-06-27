#pragma once
#include "Figure.h"

class BFigure : Figure
{
private:
	void ClearFigure();
	void PlaceFigure();
public:
	BFigure(char* place);
	virtual void Rotate();
	virtual void MoveLeft();
	virtual void MoveRight();
	virtual bool MoveDown();
};
