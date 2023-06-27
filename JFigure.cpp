#include "JFigure.h"

void JFigure::ClearFigure()
{
	Place[XPose + X1 + (YPose - 1 + Y1) * 14] = '0';
	Place[XPose + YPose * 14] = '0';
	Place[XPose + X2 + (YPose + 1 + Y2) * 14] = '0';
	Place[XPose - 1 + X3 + (YPose + 1 + Y3) * 14] = '0';
}
void JFigure::PlaceFigure()
{
	Place[XPose + X1 + (YPose - 1 + Y1) * 14] = '3';
	Place[XPose + YPose * 14] = '3';
	Place[XPose + X2 + (YPose + 1 + Y2) * 14] = '3';
	Place[XPose - 1 + X3 + (YPose + 1 + Y3) * 14] = '3';
}
JFigure::JFigure(char* place) : Figure(place)
{
	PlaceFigure();
	RStop = 13;
}
void JFigure::Rotate()
{
	Place[XPose + X1 + (YPose - 1 + Y1) * 14] = '0';
	Place[XPose + X2 + (YPose + 1 + Y2) * 14] = '0';
	Place[XPose - 1 + X3 + (YPose + 1 + Y3) * 14] = '0';
	if (FPose == 3)
		FPose = 0;
	else
		FPose++;
	switch (FPose)
	{
	case 0:
		if (Place[XPose - 1 + (YPose + 1) * 14] != '0' || Place[XPose + (YPose + 1) * 14] != '0' ||
			Place[XPose + (YPose - 1) * 14] != '0')
			FPose = 3;
		else
		{
			X3 = 0;
			X2 = 0;
			Y2 = 0;
			X1 = 0;
			Y1 = 0;
			RStop = 13;
		}
		break;
	case 1:
		if (XPose == 13 || Place[XPose - 1 + YPose * 14] != '0' || Place[XPose - 1 + (YPose - 1) * 14] != '0' ||
			Place[XPose + 1 + YPose * 14] != '0')
			FPose--;
		else
		{
			Y3 = -2;
			X2 = -1;
			Y2 = -1;
			X1 = 1;
			Y1 = 1;
			RStop = 12;
		}
		break;
	case 2:
		if (YPose == 16 || Place[XPose + (YPose + 1) * 14] != '0' || Place[XPose + (YPose - 1) * 14] != '0' ||
			Place[XPose + 1 + (YPose - 1) * 14] != '0')
			FPose--;
		else
		{
			X3 = 2;
			X2 = 0;
			Y2 = -2;
			X1 = 0;
			Y1 = 2;
			LStop = 0;
		}
		break;
	case 3:
		if (XPose == 0 || Place[XPose - 1 + YPose * 14] != '0' || Place[XPose + 1 + YPose * 14] != '0' ||
			Place[XPose + 1 + (YPose + 1) * 14] != '0')
			FPose--;
		else
		{
			Y3 = 0;
			X2 = 1;
			Y2 = -1;
			X1 = -1;
			Y1 = 1;
			LStop = 1;
		}
		break;
	}
	Place[XPose + X1 + (YPose - 1 + Y1) * 14] = '3';
	Place[XPose + X2 + (YPose + 1 + Y2) * 14] = '3';
	Place[XPose - 1 + X3 + (YPose + 1 + Y3) * 14] = '3';
}
void JFigure::MoveLeft()
{
	ClearFigure();
	switch (FPose)
	{
	case 0:
		if (XPose != LStop && Place[XPose - 2 + (YPose + 1) * 14] == '0' && Place[XPose - 1 + YPose * 14] == '0' &&
			Place[XPose - 1 + (YPose - 1) * 14] == '0')
			XPose--;
		break;
	case 1:
		if (XPose != LStop && Place[XPose - 2 + YPose * 14] == '0' && Place[XPose - 2 + (YPose - 1) * 14] == '0')
			XPose--;
		break;
	case 2:
		if (XPose != LStop && Place[XPose - 1 + (YPose + 1) * 14] == '0' && Place[XPose - 1 + YPose * 14] == '0' &&
			Place[XPose - 1 + (YPose - 1) * 14] == '0')
			XPose--;
		break;
	case 3:
		if (XPose != LStop && Place[XPose - 2 + YPose * 14] == '0' && Place[XPose + (YPose + 1) * 14] == '0')
			XPose--;
		break;
	}
	PlaceFigure();
}
void JFigure::MoveRight()
{
	ClearFigure();
	switch (FPose)
	{
	case 0:
		if (XPose != RStop && Place[XPose + 1 + (YPose + 1) * 14] == '0' && Place[XPose + 1 + YPose * 14] == '0' &&
			Place[XPose + 1 + (YPose - 1) * 14] == '0')
			XPose++;
		break;
	case 1:
		if (XPose != RStop && Place[XPose + 2 + YPose * 14] == '0' && Place[XPose + (YPose - 1) * 14] == '0')
			XPose++;
		break;
	case 2:
		if (XPose != RStop && Place[XPose + 1 + (YPose + 1) * 14] == '0' && Place[XPose + 1 + YPose * 14] == '0' &&
			Place[XPose + 2 + (YPose - 1)] == '0')
			XPose++;
		break;
	case 3:
		if (XPose != RStop && Place[XPose + 2 + (YPose + 1) * 14] == '0' && Place[XPose + 2 + YPose * 14] == '0')
			XPose++;
		break;
	}
	PlaceFigure();
}
bool JFigure::MoveDown()
{
	switch (FPose)
	{
	case 0:
		if (XPose == 12 || Place[XPose - 1 + (YPose + 2) * 14] != '0' || Place[XPose + (YPose + 2) * 14] != '0')
			return false;
		else
		{
			ClearFigure();
			YPose++;
			PlaceFigure();
			return true;
		}
		break;
	case 1:
		if (XPose == 13 || Place[XPose - 1 + (YPose + 1) * 14] != '0' || Place[XPose + (YPose + 1) * 14] != '0' ||
			Place[XPose + 1 + (YPose + 1) * 14] != '0')
			return false;
		else
		{
			ClearFigure();
			YPose++;
			PlaceFigure();
			return true;
		}
	case 2:
		if (XPose == 12 || Place[XPose + (YPose + 2) * 14] != '0' || Place[XPose + 1 + YPose * 14] != '0')
			return false;
		else
		{
			ClearFigure();
			YPose++;
			PlaceFigure();
			return true;
		}
		break;
	case 3:
		if (XPose == 12 || Place[XPose - 1 + (YPose + 1) * 14] != '0' || Place[XPose + (YPose + 1) * 14] != '0' &&
			Place[XPose + 1 + (YPose + 1) * 14] != '0')
			return false;
		else
		{
			ClearFigure();
			YPose++;
			PlaceFigure();
			return true;
		}
		break;
	}
}
