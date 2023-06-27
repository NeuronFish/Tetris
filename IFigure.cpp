#include "IFigure.h"

void IFigure::ClearFigure()
{
	Place[XPose + X1 + (YPose - 1 + Y1) * 14] = '0';
	Place[XPose + YPose * 14] = '0';
	Place[XPose + X2 + (YPose + 1 + Y2) * 14] = '0';
	Place[XPose + X3 + (YPose + 2 + Y3) * 14] = '0';
}
void IFigure::PlaceFigure()
{
	Place[XPose + X1 + (YPose - 1 + Y1) * 14] = '6';
	Place[XPose + YPose * 14] = '6';
	Place[XPose + X2 + (YPose + 1 + Y2) * 14] = '6';
	Place[XPose + X3 + (YPose + 2 + Y3) * 14] = '6';
}
IFigure::IFigure(char* place) : Figure(place)
{
	PlaceFigure();
	LStop = 0;
	RStop = 13;
}
void IFigure::Rotate()
{
	Place[XPose + X1 + (YPose - 1 + Y1) * 14] = '0';
	Place[XPose + X2 + (YPose + 1 + Y2) * 14] = '0';
	Place[XPose + X3 + (YPose + 2 + Y3) * 14] = '0';
	if (FPose == 0)
	{
		if (XPose != 13 && XPose > 1 && Place[XPose - 2 + YPose * 14] == '0' && Place[XPose - 1 + YPose * 14] == '0' &&
			Place[XPose + 1 + YPose * 14] == '0')
		{
			X3 = -2;
			Y3 = -2;
			X2 = -1;
			Y2 = -1;
			X1 = 1;
			Y1 = 1;
			LStop = 2;
			RStop = 12;
			FPose = 1;
		}
	}
	else
	{
		if (YPose < 15 && Place[XPose + (YPose + 2) * 14] == '0' && Place[XPose + (YPose + 1) * 14] == '0' &&
			Place[XPose + (YPose - 1) * 14] == '0')
		{
			X3 = 0;
			Y3 = 0;
			X2 = 0;
			Y2 = 0;
			X1 = 0;
			Y1 = 0;
			LStop = 0;
			RStop = 13;
			FPose = 0;
		}
	}
	Place[XPose + X1 + (YPose - 1 + Y1) * 14] = '6';
	Place[XPose + X2 + (YPose + 1 + Y2) * 14] = '6';
	Place[XPose + X3 + (YPose + 2 + Y3) * 14] = '6';
}
void IFigure::MoveLeft()
{
	ClearFigure();
	if (FPose == 0)
	{
		if (XPose != LStop && Place[XPose - 1 + (YPose + 2) * 14] == '0' && Place[XPose - 1 + (YPose + 1) * 14] == '0' &&
			Place[XPose - 1 + YPose * 14] == '0' && Place[XPose - 1 + (YPose - 1) * 14] == '0')
			XPose--;
	}
	else
	{
		if (XPose > 1 && Place[XPose - 3 + YPose * 14] == '0')
			XPose--;
	}
	PlaceFigure();
}
void IFigure::MoveRight()
{
	ClearFigure();
	if (FPose == 0)
	{
		if (XPose != RStop && Place[XPose + 1 + (YPose + 2) * 14] == '0' && Place[XPose + 1 + (YPose + 1) * 14] == '0' &&
			Place[XPose + 1 + YPose * 14] == '0' && Place[XPose + 1 + (YPose - 1) * 14] == '0')
			XPose++;
	}
	else
	{
		if (XPose != RStop && Place[XPose + 2 + YPose * 14] == '0')
			XPose++;
	}
	PlaceFigure();
}
bool IFigure::MoveDown()
{
	if (FPose == 0)
	{
		if (YPose == 14 || Place[XPose + (YPose + 3) * 14] != '0')
			return false;
		else
		{
			ClearFigure();
			YPose++;
			PlaceFigure();
			return true;
		}
	}
	else
	{
		if (YPose == 16 || Place[XPose - 2 + (YPose + 1) * 14] != '0' || Place[XPose - 1 + (YPose + 1) * 14] != '0' ||
			Place[XPose + (YPose + 1) * 14] != '0' || Place[XPose + 1 + (YPose + 1) * 14] != '0')
			return false;
		else
		{
			ClearFigure();
			YPose++;
			PlaceFigure();
			return true;
		}
	}
}
