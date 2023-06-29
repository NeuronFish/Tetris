#pragma once
#include "Figure.h"

class BFigure : public Figure
{
private:
	void ClearFigure();
	void PlaceFigure();
public:
	BFigure(char* place);
	void Rotate() override;
	void MoveLeft() override;
	void MoveRight() override;
	bool MoveDown() override;
};
