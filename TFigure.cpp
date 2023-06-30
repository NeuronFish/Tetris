#include "TFigure.h"

void TFigure::ClearFigure()
{
	Place[XPose + YPose * 14] = '0';
	Place[XPose + (YPose - 1 + Y1) * 14] = '0';
	Place[XPose - 1 + X2 + (YPose + Y2) * 14] = '0';
	Place[XPose + 1 + X3 + (YPose + Y3) * 14] = '0';
}
void TFigure::PlaceFigure()
{
	Place[XPose + YPose * 14] = '1';
	Place[XPose + (YPose - 1 + Y1) * 14] = '1';
	Place[XPose - 1 + X2 + (YPose + Y2) * 14] = '1';
	Place[XPose + 1 + X3 + (YPose + Y3) * 14] = '1';
}
TFigure::TFigure(char* place) : Figure(place)
{
	PlaceFigure();
}
void TFigure::Rotate()
{
	Place[XPose + (YPose - 1 + Y1) * 14] = '0';
	Place[XPose - 1 + X2 + (YPose + Y2) * 14] = '0';
	Place[XPose + 1 + X3 + (YPose + Y3) * 14] = '0';
	if (FPose == 3)
		FPose = 0;
	else
		FPose++;
	switch (FPose)
	{
	case 0:
		if (XPose == 13 || Place[XPose + 1 + YPose * 14] != '0')
			FPose = 3;
		else
		{
			X3 = 0;
			Y3 = 0;
			RStop = 12;
		}
		break;
	case 1:
		if (YPose == 16 || Place[XPose + (YPose + 1) * 14] != '0')
			FPose--;
		else
		{
			X2 = 1;
			Y2 = 1;
			LStop = 0;
		}
		break;
	case 2:
		if (XPose == 0 || Place[XPose + (YPose + 1) * 14] != '0')
			FPose--;
		else
		{
			X2 = 0;
			Y2 = 0;
			Y1 = 2;
			LStop = 1;
		}
		break;
	case 3:
		if (XPose == 13 || Place[XPose + (YPose + 1) * 14] != '0')
			FPose--;
		else
		{
			Y1 = 0;
			X3 = -1;
			Y3 = 1;
			RStop = 13;
		}
		break;
	}
	Place[XPose + (YPose - 1 + Y1) * 14] = '1';
	Place[XPose - 1 + X2 + (YPose + Y2) * 14] = '1';
	Place[XPose + 1 + X3 + (YPose + Y3) * 14] = '1';
}
void TFigure::MoveLeft()
{
	ClearFigure();
	switch (FPose)
	{
	case 0:
		if (XPose != LStop && Place[XPose - 2 + YPose * 14] == '0' && Place[XPose - 1 + (YPose - 1) * 14] == '0')
			XPose--;
		break;
	case 1:
		if (XPose != LStop && Place[XPose - 1 + (YPose + 1) * 14] == '0' && Place[XPose - 1 + YPose * 14] == '0' &&
			Place[XPose - 1 + (YPose - 1) * 14] == '0')
			XPose--;
		break;
	case 2:
		if (XPose != LStop && Place[XPose - 1 + (YPose + 1) * 14] == '0' && Place[XPose - 2 + YPose * 14] == '0')
			XPose--;
		break;
	case 3:
		if (XPose != LStop && Place[XPose - 1 + (YPose + 1) * 14] == '0' && Place[XPose - 2 + YPose * 14] == '0' &&
			Place[XPose - 1 + (YPose - 1) * 14] == '0')
			XPose--;
		break;
	}
	PlaceFigure();
}
void TFigure::MoveRight()
{
	ClearFigure();
	switch (FPose)
	{
	case 0:
		if (XPose != RStop && Place[XPose + 2 + YPose * 14] == '0' && Place[XPose + 1 + (YPose - 1) * 14] == '0')
			XPose++;
		break;
	case 1:
		if (XPose != RStop && Place[XPose + 1 + (YPose + 1) * 14] == '0' && Place[XPose + 2 + YPose * 14] == '0' &&
			Place[XPose + 1 + (YPose + 1) * 14] == '0')
			XPose++;
		break;
	case 2:
		if (XPose != RStop && Place[XPose + 1 + (YPose + 1) * 14] == '0' && Place[XPose + 2 + YPose * 14] == '0')
			XPose++;
		break;
	case 3:
		if (XPose != RStop && Place[XPose + 1 + (YPose + 1) * 14] == '0' && Place[XPose + 1 + YPose * 14] == '0' &&
			Place[XPose + 1 + (YPose + 1) * 14] == '0')
			XPose++;
		break;
	}
	PlaceFigure();
}
bool TFigure::MoveDown()
{
	switch (FPose)
	{
	case 0:
		if (YPose == 16 || Place[XPose - 1 + (YPose + 1) * 14] != '0' || Place[XPose + (YPose + 1) * 14] != '0' ||
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
	case 1:
		if (YPose == 15 || Place[XPose + (YPose + 2) * 14] != '0' || Place[XPose + 1 + (YPose + 1) * 14] != '0')
			return false;
		else
		{
			ClearFigure();
			YPose++;
			PlaceFigure();
			return true;
		}
		break;
	case 2:
		if (YPose == 15 || Place[XPose - 1 + (YPose + 1) * 14] != '0' || Place[XPose + (YPose + 2) * 14] != '0' ||
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
	case 3:
		if (YPose == 15 || Place[XPose - 1 + (YPose + 1) * 14] != '0' || Place[XPose + (YPose + 2) * 14] != '0')
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
