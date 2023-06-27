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
	void Rotate() override;
	void MoveLeft() override;
	void MoveRight() override;
	bool MoveDown() override;
};
