#pragma once
#include "Figure.h"

class TFigure : public Figure
{
private:
	int Y1 = 0, X2 = 0, Y2 = 0, X3 = 0, Y3 = 0;
	void ClearFigure();
	void PlaceFigure();
public:
	TFigure(char *place);
	void Rotate() override;
	void MoveLeft() override;
	void MoveRight() override;
	bool MoveDown() override;
};
