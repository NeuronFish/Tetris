#pragma once

class Figure
{
protected:
	int XPose = 7, YPose = 1;
	char* Place;
	int FPose = 0;
	int LStop = 1, RStop = 12;
public:
	Figure(char* place)
	{
		Place = place;
	}
	virtual void Rotate() {}
	virtual void MoveLeft() {}
	virtual void MoveRight() {}
	virtual bool MoveDown() { return false; }
};