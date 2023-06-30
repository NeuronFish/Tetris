#include "ZFigure.h"

void ZFigure::ClearFigure()
{
	Place[XPose + YPose * 14] = '0';
	Place[XPose - 1 + YPose * 14] = '0';
	Place[XPose + (YPose + 1 + Y2) * 14] = '0';
	Place[XPose + X3 + 1 + (YPose + 1) * 14] = '0';
}
void ZFigure::PlaceFigure()
{
	Place[XPose + YPose * 14] = '5';
	Place[XPose - 1 + YPose * 14] = '5';
	Place[XPose + (YPose + 1 + Y2) * 14] = '5';
	Place[XPose + X3 + 1 + (YPose + 1) * 14] = '5';
}
ZFigure::ZFigure(char* place) : Figure(place)
{
	PlaceFigure();
}
void ZFigure::Rotate()
{
	Place[XPose - 1 + YPose * 14] = '0';
	Place[XPose + (YPose + 1 + Y2) * 14] = '0';
	Place[XPose + X3 + 1 + (YPose + 1) * 14] = '0';
	if (FPose == 0)
	{
		if (Place[XPose - 1 + (YPose + 1) * 14] == '0' && Place[XPose + (YPose - 1) * 14] == '0')
		{
			Y2 = -2;
			X3 = -2;
			RStop = 13;
			FPose = 1;
		}
	}
	else
	{
		if (XPose != 13 && Place[XPose + (YPose + 1) * 14] == '0' && Place[XPose + 1 + (YPose + 1) * 14] == '0')
		{
			Y2 = 0;
			X3 = 0;
			RStop = 12;
			FPose = 0;
		}
	}
	Place[XPose - 1 + YPose * 14] = '5';
	Place[XPose + (YPose + 1 + Y2) * 14] = '5';
	Place[XPose + X3 + 1 + (YPose + 1) * 14] = '5';
}
void ZFigure::MoveLeft()
{
	ClearFigure();
	if (FPose == 0)
	{
		if (XPose != LStop && Place[XPose - 2 + YPose * 14] == '0' && Place[XPose - 1 + (YPose + 1) * 14] == '0')
			XPose--;
	}
	else
	{
		if (XPose != LStop && Place[XPose - 2 + (YPose + 1) * 14] == '0' && Place[XPose - 2 + YPose * 14] == '0' &&
			Place[XPose - 1 + (YPose - 1) * 14] == '0')
			XPose--;
	}
	PlaceFigure();
}
void ZFigure::MoveRight()
{
	ClearFigure();
	if (FPose == 0)
	{
		if (XPose != RStop && Place[XPose + 1 + YPose * 14] == '0' && Place[XPose + 2 + (YPose + 1) * 14] == '0')
			XPose++;
	}
	else
	{
		if (XPose != RStop && Place[XPose + (YPose + 1) * 14] == '0' && Place[XPose + 1 + YPose * 14] == '0' &&
			Place[XPose + 1 + (YPose - 1) * 14] == '0')
			XPose++;
	}
	PlaceFigure();
}
bool ZFigure::MoveDown()
{
	if (FPose == 0)
	{
		if (YPose == 15 || Place[XPose - 1 + (YPose + 1) * 14] != '0' || Place[XPose + (YPose + 2) * 14] != '0' ||
			Place[XPose + 1 + (YPose + 2) * 14] != '0')
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
		if (YPose == 15 || Place[XPose - 1 + (YPose + 2) * 14] != '0' || Place[XPose + (YPose + 1) * 14] != '0')
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
