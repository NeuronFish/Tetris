#include "PlaceLogic.h"

const int XPose = 2, YPose = 3;

void ClearFuturePlace(char* place)
{
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			place[x + y * 5] = '0';
		}
	}
}
void ClearPlace(char* place)
{
	for (int y = 0; y < 17; y++)
	{
		for (int x = 0; x < 14; x++)
		{
			place[x + y * 14] = '0';
		}
	}
}
void SetFutureFigure(char* place, int type)
{
	ClearFuturePlace(place);
	switch (type)
	{
	case 0:
		place[XPose + YPose * 5] = '1';
		place[XPose + (YPose - 1) * 5] = '1';
		place[XPose - 1 + YPose * 5] = '1';
		place[XPose + 1 + YPose * 5] = '1';
		break;
	case 1:
		place[XPose + YPose * 5] = '2';
		place[XPose + (YPose + 1) * 5] = '2';
		place[XPose + 1 + (YPose + 1) * 5] = '2';
		place[XPose + (YPose - 1) * 5] = '2';
		break;
	case 2:
		place[XPose + YPose * 5] = '3';
		place[XPose + (YPose + 1) * 5] = '3';
		place[XPose - 1 + (YPose + 1) * 5] = '3';
		place[XPose + (YPose - 1) * 5] = '3';
		break;
	case 3:
		place[XPose + YPose * 5] = '4';
		place[XPose - 1 + YPose * 5] = '4';
		place[XPose + (YPose - 1) * 5] = '4';
		place[XPose + 1 + (YPose - 1) * 5] = '4';
		break;
	case 4:
		place[XPose + YPose * 5] = '5';
		place[XPose + 1 + YPose * 5] = '5';
		place[XPose + (YPose - 1) * 5] = '5';
		place[XPose - 1 + (YPose - 1) * 5] = '5';
		break;
	case 5:
		place[XPose + YPose * 5] = '6';
		place[XPose + (YPose - 1) * 5] = '6';
		place[XPose + (YPose - 2) * 5] = '6';
		place[XPose + (YPose + 1) * 5] = '6';
		break;
	case 6:
		place[XPose + YPose * 5] = '7';
		place[XPose - 1 + YPose * 5] = '7';
		place[XPose + (YPose - 1) * 5] = '7';
		place[XPose - 1 + (YPose - 1) * 5] = '7';
		break;
	}
}
void RemoveLine(char* place, int y)
{
	while (y > 0)
	{
		for (int x = 0; x < 14; x++)
		{
			place[x + y * 14] = place[x + (y - 1) * 14];
		}
		y--;
	}
}
void CheckScore(int* score, int* time)
{
	if (*score > 1300)
	{
		*time = 100;
	}
	else if (*score > 1000)
	{
		*time = 150;
	}
	else if (*score > 900)
	{
		*time = 200;
	}
	else if (*score > 700)
	{
		*time = 400;
	}
	else if (*score > 500)
	{
		*time = 600;
	}
	else if (*score > 200)
	{
		*time = 800;
	}
}
void CheckLine(char* place, int* score, int* time)
{
	bool containO;
	for (int y = 0; y < 17; y++)
	{
		containO = false;
		for (int x = 0; x < 14; x++)
		{
			if (place[x + y * 14] == '0')
			{
				containO = true;
				break;
			}
		}
		if (!containO)
		{
			RemoveLine(place, y);
			*score += 100;
			CheckScore(score, time);
		}
	}
}
bool CheckPlace(char* place)
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 3; x < 9; x++)
		{
			if (place[x + y * 14] != '0')
				return false;
		}
	}
	return true;
}
