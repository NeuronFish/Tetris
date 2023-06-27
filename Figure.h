#pragma once

class Figure
{
protected:
	int XPose = 7, YPose = 1;
	char* Place;
	int FPose = 0;
	int LStop = 1, RStop = 12;

	Figure(char* place)
	{
		Place = place;
	}
public:
	virtual void Rotate() = 0;
	virtual void MoveLeft() = 0;
	virtual void MoveRight() = 0;
	virtual bool MoveDown() = 0;
};