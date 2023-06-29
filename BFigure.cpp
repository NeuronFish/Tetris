#include "BFigure.h"

void BFigure::ClearFigure()
{
	Place[XPose + (YPose - 1) * 14] = '0';
	Place[XPose + 1 + (YPose - 1) * 14] = '0';
	Place[XPose + YPose * 14] = '0';
	Place[XPose + 1 + YPose * 14] = '0';
}
void BFigure::PlaceFigure()
{
	Place[XPose + (YPose - 1) * 14] = '7';
	Place[XPose + 1 + (YPose - 1) * 14] = '7';
	Place[XPose + YPose * 14] = '7';
	Place[XPose + 1 + YPose * 14] = '7';
}
BFigure::BFigure(char* place) : Figure(place)
{
	PlaceFigure();
	LStop = 0;
}
void BFigure::Rotate()
{ }
void BFigure::MoveLeft()
{
	if (XPose != LStop && Place[XPose - 1 + YPose * 14] == '0' && Place[XPose - 1 + (YPose - 1) * 14] == '0')
	{
		ClearFigure();
		XPose--;
		PlaceFigure();
	}
}
void BFigure::MoveRight()
{
	if (XPose != RStop && Place[XPose + 2 + YPose * 14] == '0' && Place[XPose + 2 + (YPose - 1) * 14] == '0')
	{
		ClearFigure();
		XPose++;
		PlaceFigure();
	}
}
bool BFigure::MoveDown()
{
	if (YPose == 16 || Place[XPose + (YPose + 1) * 14] != '0' || Place[XPose + 1 + (YPose + 1) * 14] != '0')
		return false;
	else
	{
		ClearFigure();
		YPose++;
		PlaceFigure();
		return true;
	}
}
