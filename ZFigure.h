#pragma once
#include "Figure.h"

class ZFigure : Figure
{
private:
	int Y2 = 0, X3 = 0;
	void ClearFigure();
	void PlaceFigure();
public:
	ZFigure(char* place);
	virtual void Rotate();
	virtual void MoveLeft();
	virtual void MoveRight();
	virtual bool MoveDown();
};
