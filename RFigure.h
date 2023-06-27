#pragma once
#include "Figure.h"

class RFigure : public Figure
{
private:
	int X1 = 0, Y3 = 0;
	void ClearFigure();
	void PlaceFigure();
public:
	RFigure(char* place);
	void Rotate() override;
	void MoveLeft() override;
	void MoveRight() override;
	bool MoveDown() override;
};
