#include "RFigure.h"

void RFigure::ClearFigure()
{
	Place[XPose + YPose * 14] = '0';
	Place[XPose + 1 + X1 + YPose * 14] = '0';
	Place[XPose + (YPose + 1) * 14] = '0';
	Place[XPose - 1 + (YPose + 1 + Y3) * 14] = '0';
}
void RFigure::PlaceFigure()
{
	Place[XPose + YPose * 14] = '4';
	Place[XPose + 1 + X1 + YPose * 14] = '4';
	Place[XPose + (YPose + 1) * 14] = '4';
	Place[XPose - 1 + (YPose + 1 + Y3) * 14] = '4';
}
RFigure::RFigure(char* place) : Figure(place)
{
	PlaceFigure();
}
void RFigure::Rotate()
{
	Place[XPose + 1 + X1 + YPose * 14] = '0';
	Place[XPose + (YPose + 1) * 14] = '0';
	Place[XPose - 1 + (YPose + 1 + Y3) * 14] = '0';
	if (FPose == 0)
	{
		if (Place[XPose - 1 + YPose * 14] == '0' && Place[XPose - 1 + (YPose - 1) * 14] == '0')
		{
			X1 = -2;
			Y3 = -2;
			RStop = 13;
			FPose = 1;
		}
	}
	else
	{
		if (XPose != 13 && Place[XPose - 1 + (YPose + 1) * 14] == '0' && Place[XPose + 1 + YPose * 14] == '0')
		{
			X1 = 0;
			Y3 = 0;
			RStop = 12;
			FPose = 0;
		}
	}
	Place[XPose + 1 + X1 + YPose * 14] = '4';
	Place[XPose + (YPose + 1) * 14] = '4';
	Place[XPose - 1 + (YPose + 1 + Y3) * 14] = '4';
}
void RFigure::MoveLeft()
{
	ClearFigure();
	if (FPose == 0)
	{
		if (XPose != LStop && Place[XPose - 2 + (YPose + 1) * 14] == '0' && Place[XPose - 1 + YPose * 14] == '0')
			XPose--;
	}
	else
	{
		if (XPose != LStop && Place[XPose + (YPose + 1) * 14] == '0' && Place[XPose - 2 + YPose * 14] == '0' &&
			Place[XPose - 2 + (YPose - 1) * 14] == '0')
			XPose--;
	}
	PlaceFigure();
}
void RFigure::MoveRight()
{
	ClearFigure();
	if (FPose == 0)
	{
		if (XPose != RStop && Place[XPose + 2 + YPose * 14] == '0' && Place[XPose + 1 + (YPose + 1) * 14] == '0')
			XPose++;
	}
	else
	{
		if (XPose != RStop && Place[XPose + 1 + (YPose + 1) * 14] == '0' && Place[XPose + 1 + YPose * 14] == '0' &&
			Place[XPose + (YPose - 1) * 14] == '0')
			XPose++;
	}
	PlaceFigure();
}
bool RFigure::MoveDown()
{
	if (FPose == 0)
	{
		if (YPose == 15 || Place[XPose - 1 + (YPose + 2) * 14] != '0' || Place[XPose + (YPose + 2) * 14] != '0' ||
			Place[XPose + 1 + (YPose + 1) * 14] != '0')
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
		if (YPose == 15 || Place[XPose - 1 + (YPose + 1) * 14] != '0' || Place[XPose + (YPose + 2) * 14] != '0')
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
