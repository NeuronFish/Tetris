#pragma once
#include "Figure.h"

class JFigure : public Figure
{
private:
	int X1 = 0, Y1 = 0, X2 = 0, Y2 = 0, X3 = 0, Y3 = 0;
	void ClearFigure();
	void PlaceFigure();
public:
	JFigure(char* place);
	void Rotate() override;
	void MoveLeft() override;
	void MoveRight() override;
	bool MoveDown() override;
};
