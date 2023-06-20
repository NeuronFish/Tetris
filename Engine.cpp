#include "Engine.h"

HPEN BG1_Pen, BG2_Pen, BC_Pen, GC_Pen, RC_Pen, LC_Pen, DBC_Pen, VC_Pen, LVC_Pen, Wi_Pen;
HBRUSH BG1_Brush, BG2_Brush, BC_Brush, GC_Brush, RC_Brush, LC_Brush, DBC_Brush, VC_Brush, LVC_Brush, Wi_Brush;
HWND Hwnd;
HDC Hdc1;
RECT PlaceArea, PlaceFArea, ScoreArea;
int XPose = 7, YPose = 15, XPoseF = 2, YPoseF = 3;
int FPose = 1;
int X2, X3, X4, Y2, Y3, Y4;
int LStop = 1, RStop = 12;
int LStop1 = 0, RStop1 = 13;
int G = 3, Choice, ChoiceF, Score = 0, Time = 1000;
bool C = true;
bool EndBut = false;
char FType;
enum EFType
{
	ET_FType = 1, EL_FType = 2, EJ_FType = 3, ER_FType = 4, EZ_FType = 5, EI_FType = 6, EB_FType = 7
};
char Place[17][14] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
char PlaceF[6][5] =
{
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0
};

void Create_PenAndBrush(unsigned r, unsigned g, unsigned b, HPEN& pen, HBRUSH& brush)
{
	pen = CreatePen(PS_SOLID, 0, RGB(r, g, b));
	brush = CreateSolidBrush(RGB(r, g, b));
}

void Init_Engine(HWND hwnd)
{
	Hwnd = hwnd;
	Create_PenAndBrush(0, 255, 255, BC_Pen, BC_Brush);
	Create_PenAndBrush(0, 255, 0, GC_Pen, GC_Brush);
	Create_PenAndBrush(244, 0, 0, RC_Pen, RC_Brush);
	Create_PenAndBrush(0, 128, 255, LC_Pen, LC_Brush);
	Create_PenAndBrush(0, 64, 128, DBC_Pen, DBC_Brush);
	Create_PenAndBrush(128, 0, 128, VC_Pen, VC_Brush);
	Create_PenAndBrush(128, 128, 255, LVC_Pen, LVC_Brush);
	Create_PenAndBrush(255, 255, 255, Wi_Pen, Wi_Brush);
	PlaceArea.left = 290;
	PlaceArea.top = 0;
	PlaceArea.right = 515;
	PlaceArea.bottom = 540;
	PlaceFArea.left = 118;
	PlaceFArea.top = 208;
	PlaceFArea.right = 199;
	PlaceFArea.bottom = 305;
	ScoreArea.left = 91;
	ScoreArea.top = 315;
	ScoreArea.right = 205;
	ScoreArea.bottom = 335;
}

void Init_Time()
{
	SetTimer(Hwnd, Timer_ID, Time, 0);
}

void RedrawPlace()
{
	InvalidateRect(Hwnd, &PlaceArea, FALSE);
}

void Draw_PlaceF(HDC hdc)
{
	int x, y;
	for (y = 0; y < 6; y++)
	{
		for (x = 0; x < 5; x++)
		{
			if (PlaceF[y][x] == 0)
			{
				SelectObject(hdc, BG2_Pen);
				SelectObject(hdc, BG2_Brush);
			}
			else if (PlaceF[y][x] == 1)
			{
				SelectObject(hdc, BC_Pen);
				SelectObject(hdc, BC_Brush);
			}
			else if (PlaceF[y][x] == 2)
			{
				SelectObject(hdc, GC_Pen);
				SelectObject(hdc, GC_Brush);
			}
			else if (PlaceF[y][x] == 3)
			{
				SelectObject(hdc, RC_Pen);
				SelectObject(hdc, RC_Brush);
			}
			else if (PlaceF[y][x] == 4)
			{
				SelectObject(hdc, LC_Pen);
				SelectObject(hdc, LC_Brush);
			}
			else if (PlaceF[y][x] == 5)
			{
				SelectObject(hdc, DBC_Pen);
				SelectObject(hdc, DBC_Brush);
			}
			else if (PlaceF[y][x] == 6)
			{
				SelectObject(hdc, VC_Pen);
				SelectObject(hdc, VC_Brush);
			}
			else if (PlaceF[y][x] == 7)
			{
				SelectObject(hdc, LVC_Pen);
				SelectObject(hdc, LVC_Brush);
			}
			Rectangle(hdc, 119 + x + (15 * x), 209 + y + (15 * y), 119 + (15 * (x + 1)) + x, 209 + (15 * (y + 1) + y));
		}
	}
}

void TFigures()
{
	Place[YPose][XPose] = char(1);
	Place[YPose + Y2][XPose + 1 + X2] = char(1);
	Place[YPose + 1 + Y3][XPose + X3] = char(1);
	Place[YPose + Y4][XPose - 1 + X4] = char(1);
	FType = ET_FType;
}

void LFigures()
{
	Place[YPose][XPose] = char(2);
	Place[YPose + 1 + Y2][XPose + X2] = char(2);
	Place[YPose - 1 + Y3][XPose + X3] = char(2);
	Place[YPose - 1 + Y4][XPose + 1 + X4] = char(2);
	FType = EL_FType;
}

void JFigures()
{
	Place[YPose][XPose] = char(3);
	Place[YPose + 1 + Y2][XPose + X2] = char(3);
	Place[YPose - 1 + Y3][XPose + X3] = char(3);
	Place[YPose - 1 + Y4][XPose - 1 + X4] = char(3);
	FType = EJ_FType;
}

void RFigures()
{
	Place[YPose][XPose] = char(4);
	Place[YPose + Y2][XPose + 1 + X2] = char(4);
	Place[YPose - 1 + Y3][XPose + X3] = char(4);
	Place[YPose - 1 + Y4][XPose - 1 + X4] = char(4);
	FType = ER_FType;
}

void ZFigures()
{
	Place[YPose][XPose] = char(5);
	Place[YPose + Y2][XPose - 1 + X2] = char(5);
	Place[YPose - 1 + Y3][XPose + 1 + X3] = char(5);
	Place[YPose - 1 + Y4][XPose + X4] = char(5);
	FType = EZ_FType;
}

void IFigures()
{
	Place[YPose][XPose] = char(6);
	Place[YPose + 1 + Y2][XPose + X2] = char(6);
	Place[YPose - 1 + Y3][XPose + X3] = char(6);
	Place[YPose - 2 + Y4][XPose + X4] = char(6);
	FType = EI_FType;
}

void BFigures()
{
	Place[YPose][XPose] = char(7);
	Place[YPose][XPose + 1] = char(7);
	Place[YPose - 1][XPose] = char(7);
	Place[YPose - 1][XPose + 1] = char(7);
	FType = EB_FType;
}

void Init_Wind(HDC hdc)
{
	Hdc1 = hdc;
}

void CheckLine()
{
	int x, y;
	for (y = 0; y < 13; y++)
	{
		bool c = true;
		for (x = 0; x < 14; x++)
		{
			if (Place[y][x] == char(0))
			{
				x = 13;
				c = false;
			}
			else if (x == 13)
			{
				if (c == true)
				{
					for (x = 0; x < 14; x++)
					{
						Place[y][x] = char(0);
					}
					for (y; y < 13; y++)
					{
						for (x = 0; x < 14; x++)
						{
							if (y == 12)
							{
								Place[y][x] = char(0);
							}
							else
							{
								Place[y][x] = Place[y + 1][x];
							}
						}
					}
					Score += 100;
					if (Score > 1300)
					{
						Time = 100;
					}
					else if (Score > 1000)
					{
						Time = 150;
					}
					else if (Score > 900)
					{
						Time = 200;
					}
					else if (Score > 700)
					{
						Time = 400;
					}
					else if (Score > 500)
					{
						Time = 600;
					}
					else if (Score > 200)
					{
						Time = 800;
					}
					Init_Time();
					InvalidateRect(Hwnd, &ScoreArea, FALSE);
					RedrawPlace();
				}
			}
		}
	}
}

void CheckPlace()
{
	int x, y;
	if (G == 1)
	{
		for (y = 13; y < 16; y++)
		{
			for (x = 5; x < 9; x++)
			{
				if (Place[y][x] != char(0))
				{
					y = 16;
					x = 9;
					G = 2;
					C = false;
				}
			}
		}
	}
}

void Message()
{
	SelectObject(Hdc1, Wi_Pen);
	SelectObject(Hdc1, Wi_Brush);
	Rectangle(Hdc1, 245, 270, 550, 360);
	SelectObject(Hdc1, BG2_Pen);
	SelectObject(Hdc1, BG2_Brush);
	Rectangle(Hdc1, 240, 265, 545, 355);
	TextOut(Hdc1, 365, 240, L"Game Over", lstrlen(L"Game Over"));
	TextOut(Hdc1, 377, 280, L"Retry?", lstrlen(L"Retry?"));
	TextOut(Hdc1, 330, 310, L"[Y]Yes!", lstrlen(L"[Y]Yes!"));
	TextOut(Hdc1, 420, 310, L"[N]No", lstrlen(L"[N]No"));
	EndBut = true;
}

void Redraw_Choice()
{
	InvalidateRect(Hwnd, &PlaceFArea, FALSE);
}

void Draw_Figures()
{
	CheckLine();
	CheckPlace();
	if (G == 3)
	{
		Choice = rand() % 7;
		ChoiceF = rand() % 7;
		G = 0;
	}
	else if (G == 0)
	{
		Choice = Choice;
	}
	else if (G == 2)
	{
		Choice = 7;
	}
	else if (G == 1)
	{
		Choice = ChoiceF;
		for (int y = 0; y < 6; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				PlaceF[y][x] = char(0);
			}
		}
		ChoiceF = rand() % 7;
		Redraw_Choice();
		G = 0;
	}
	switch (Choice)
	{
	case 0:
		TFigures();
		break;
	case 1:
		LFigures();
		break;
	case 2:
		JFigures();
		break;
	case 3:
		RFigures();
		break;
	case 4:
		ZFigures();
		break;
	case 5:
		IFigures();
		break;
	case 6:
		BFigures();
		break;
	case 7:
		Message();
		break;
	}
	switch (ChoiceF)
	{
	case 0:
		PlaceF[YPoseF][XPoseF] = char(1);
		PlaceF[YPoseF - 1][XPoseF] = char(1);
		PlaceF[YPoseF][XPoseF - 1] = char(1);
		PlaceF[YPoseF][XPoseF + 1] = char(1);
		break;
	case 1:
		PlaceF[YPoseF][XPoseF] = char(2);
		PlaceF[YPoseF + 1][XPoseF] = char(2);
		PlaceF[YPoseF + 1][XPoseF + 1] = char(2);
		PlaceF[YPoseF - 1][XPoseF] = char(2);
		break;
	case 2:
		PlaceF[YPoseF][XPoseF] = char(3);
		PlaceF[YPoseF + 1][XPoseF] = char(3);
		PlaceF[YPoseF + 1][XPoseF - 1] = char(3);
		PlaceF[YPoseF - 1][XPoseF] = char(3);
		break;
	case 3:
		PlaceF[YPoseF][XPoseF] = char(4);
		PlaceF[YPoseF][XPoseF - 1] = char(4);
		PlaceF[YPoseF - 1][XPoseF] = char(4);
		PlaceF[YPoseF - 1][XPoseF + 1] = char(4);
		break;
	case 4:
		PlaceF[YPoseF][XPoseF] = char(5);
		PlaceF[YPoseF][XPoseF + 1] = char(5);
		PlaceF[YPoseF - 1][XPoseF] = char(5);
		PlaceF[YPoseF - 1][XPoseF - 1] = char(5);
		break;
	case 5:
		PlaceF[YPoseF][XPoseF] = char(6);
		PlaceF[YPoseF - 1][XPoseF] = char(6);
		PlaceF[YPoseF - 2][XPoseF] = char(6);
		PlaceF[YPoseF + 1][XPoseF] = char(6);
		break;
	case 6:
		PlaceF[YPoseF][XPoseF] = char(7);
		PlaceF[YPoseF][XPoseF - 1] = char(7);
		PlaceF[YPoseF - 1][XPoseF] = char(7);
		PlaceF[YPoseF - 1][XPoseF - 1] = char(7);
		break;
	}
}

void Retry()
{
	int x, y;
	for (y = 0; y < 17; y++)
	{
		for (x = 0; x < 14; x++)
		{
			Place[y][x] = char(0);
		}
	}
	for (y = 0; y < 6; y++)
	{
		for (x = 0; x < 5; x++)
		{
			PlaceF[y][x] = char(0);
		}
	}
	XPose = 7, YPose = 15, G = 3, Score = 0, Time = 1000, C = true, LStop = 1, RStop = 12, LStop1 = 0, RStop1 = 13, EndBut = false;
	Draw_Figures();
	RedrawPlace();
	Redraw_Choice();
}

int On_Key_Down(EKey_type EKtype)
{
	switch (EKtype)
	{
	case EKt_Left:
		switch (FType)
		{
		case ET_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + Y2][XPose + 1 + X2] = char(0);
			Place[YPose + 1 + Y3][XPose + X3] = char(0);
			Place[YPose + Y4][XPose - 1 + X4] = char(0);
			switch (FPose)
			{
			case 1:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 2:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 3:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 4:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			}
			break;
		case EL_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + 1 + Y2][XPose + X2] = char(0);
			Place[YPose - 1 + Y3][XPose + X3] = char(0);
			Place[YPose - 1 + Y4][XPose + 1 + X4] = char(0);
			switch (FPose)
			{
			case 1:
				if (XPose == LStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 2:
				if (XPose == LStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 3:
				if (XPose == LStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 4:
				if (XPose == LStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			}
			break;
		case EJ_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + 1 + Y2][XPose + X2] = char(0);
			Place[YPose - 1 + Y3][XPose + X3] = char(0);
			Place[YPose - 1 + Y4][XPose - 1 + X4] = char(0);
			switch (FPose)
			{
			case 1:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 2:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 3:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 4:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			}
			break;
		case ER_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + Y2][XPose + 1 + X2] = char(0);
			Place[YPose - 1 + Y3][XPose + X3] = char(0);
			Place[YPose - 1 + Y4][XPose - 1 + X4] = char(0);
			switch (FPose)
			{
			case 1:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 2:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 3:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 4:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			}
			break;
		case EZ_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + Y2][XPose - 1 + X2] = char(0);
			Place[YPose - 1 + Y3][XPose + 1 + X3] = char(0);
			Place[YPose - 1 + Y4][XPose + X4] = char(0);
			switch (FPose)
			{
			case 1:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 2:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 3:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 4:
				if (XPose == LStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			}
			break;
		case EI_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + 1 + Y2][XPose + X2] = char(0);
			Place[YPose - 1 + Y3][XPose + X3] = char(0);
			Place[YPose - 2 + Y4][XPose + X4] = char(0);
			switch (FPose)
			{
			case 1:
				if (XPose == LStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 2][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 2:
				if (XPose == LStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 3] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 3:
				if (XPose == LStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 2][XPose - 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			case 4:
				if (XPose == LStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose - 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose -= 1;
				}
				break;
			}
			break;
		case EB_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose][XPose + 1] = char(0);
			Place[YPose - 1][XPose] = char(0);
			Place[YPose - 1][XPose + 1] = char(0);
			if (XPose == LStop1)
			{
				XPose = XPose;
			}
			else if (Place[YPose][XPose - 1] != char(0))
			{
				XPose = XPose;
			}
			else if (Place[YPose - 1][XPose - 1] != char(0))
			{
				XPose = XPose;
			}
			else
			{
				XPose -= 1;
			}
			break;
		}
		RedrawPlace();
		break;
	case EKt_Right:
		switch (FType)
		{
		case ET_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + Y2][XPose + 1 + X2] = char(0);
			Place[YPose + 1 + Y3][XPose + X3] = char(0);
			Place[YPose + Y4][XPose - 1 + X4] = char(0);
			switch (FPose)
			{
			case 1:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 2:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 3:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 4:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			}
			break;
		case EL_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + 1 + Y2][XPose + X2] = char(0);
			Place[YPose - 1 + Y3][XPose + X3] = char(0);
			Place[YPose - 1 + Y4][XPose + 1 + X4] = char(0);
			switch (FPose)
			{
			case 1:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 2:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 3:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 4:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			}
			break;
		case EJ_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + 1 + Y2][XPose + X2] = char(0);
			Place[YPose - 1 + Y3][XPose + X3] = char(0);
			Place[YPose - 1 + Y4][XPose - 1 + X4] = char(0);
			switch (FPose)
			{
			case 1:
				if (XPose == RStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 2:
				if (XPose == RStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 3:
				if (XPose == RStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 4:
				if (XPose == RStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			}
			break;
		case ER_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + Y2][XPose + 1 + X2] = char(0);
			Place[YPose - 1 + Y3][XPose + X3] = char(0);
			Place[YPose - 1 + Y4][XPose - 1 + X4] = char(0);
			switch (FPose)
			{
			case 1:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 2:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 3:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 4:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			}
			break;
		case EZ_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + Y2][XPose - 1 + X2] = char(0);
			Place[YPose - 1 + Y3][XPose + 1 + X3] = char(0);
			Place[YPose - 1 + Y4][XPose + X4] = char(0);
			switch (FPose)
			{
			case 1:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 2:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 3:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 4:
				if (XPose == RStop)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			}
			break;
		case EI_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + 1 + Y2][XPose + X2] = char(0);
			Place[YPose - 1 + Y3][XPose + X3] = char(0);
			Place[YPose - 2 + Y4][XPose + X4] = char(0);
			switch (FPose)
			{
			case 1:
				if (XPose == RStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 2][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 2:
				if (XPose == RStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 2] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 3:
				if (XPose == RStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose - 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 1][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else if (Place[YPose + 2][XPose + 1] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			case 4:
				if (XPose == RStop1)
				{
					XPose = XPose;
				}
				else if (Place[YPose][XPose + 3] != char(0))
				{
					XPose = XPose;
				}
				else
				{
					XPose += 1;
				}
				break;
			}
			break;
		case EB_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose][XPose + 1] = char(0);
			Place[YPose - 1][XPose] = char(0);
			Place[YPose - 1][XPose + 1] = char(0);
			if (XPose == RStop)
			{
				XPose = XPose;
			}
			else if (Place[YPose][XPose + 2] != char(0))
			{
				XPose = XPose;
			}
			else if (Place[YPose - 1][XPose + 2] != char(0))
			{
				XPose = XPose;
			}
			else
			{
				XPose += 1;
			}
			break;
		}
		RedrawPlace();
		break;
	case EKt_Up:
		switch (FType)
		{
		case ET_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + Y2][XPose + 1 + X2] = char(0);
			Place[YPose + 1 + Y3][XPose + X3] = char(0);
			Place[YPose + Y4][XPose - 1 + X4] = char(0);
			FPose += 1;
			if (FPose > 4)
			{
				FPose = 1;
			}
			switch (FPose)
			{
			case 1:
				if (Place[YPose][XPose + 1] != char(0))
				{
					FPose = 4;
				}
				else if (XPose == 13)
				{
					FPose = 4;
				}
				else if (XPose == 0)
				{
					FPose = 4;
				}
				else
				{
					X2 = 0;
					X3 = 0;
					X4 = 0;
					Y2 = 0;
					Y3 = 0;
					Y4 = 0;
					RStop = 12;
				}
				break;
			case 2:
				if (Place[YPose - 1][XPose] != char(0))
				{
					FPose = 1;
				}
				else if (YPose == 2)
				{
					FPose = 1;
				}
				else
				{
					Y4 = -1;
					X4 = 1;
					LStop = 0;
				}
				break;
			case 3:
				if (Place[YPose][XPose - 1] != char(0))
				{
					FPose = 2;
				}
				else if (XPose == 0)
				{
					FPose = 2;
				}
				else
				{
					Y3 = -1;
					X3 = -1;
					LStop = 1;
				}
				break;
			case 4:
				if (Place[YPose + 1][XPose] != char(0))
				{
					FPose = 3;
				}
				else
				{
					Y2 = 1;
					X2 = -1;
					RStop = 13;
				}
				break;
			}
			break;
		case EL_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + 1 + Y2][XPose + X2] = char(0);
			Place[YPose - 1 + Y3][XPose + X3] = char(0);
			Place[YPose - 1 + Y4][XPose + 1 + X4] = char(0);
			FPose += 1;
			if (FPose > 4)
			{
				FPose = 1;
			}
			switch (FPose)
			{
			case 1:
				if (YPose == 2)
				{
					FPose = 4;
				}
				else if (Place[YPose - 1][XPose + 1] != char(0))
				{
					FPose = 4;
				}
				else if (Place[YPose - 1][XPose] != char(0))
				{
					FPose = 4;
				}
				else if (Place[YPose + 1][XPose] != char(0))
				{
					FPose = 4;
				}
				else
				{
					Y2 = 0;
					X2 = 0;
					Y3 = 0;
					X3 = 0;
					Y4 = 0;
					X4 = 0;
					LStop1 = 0;
				}
				break;
			case 2:
				if (Place[YPose - 1][XPose - 1] != char(0))
				{
					FPose = 1;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					FPose = 1;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					FPose = 1;
				}
				else if (XPose == 0)
				{
					FPose = 1;
				}
				else
				{
					Y2 = -1;
					X2 = 1;
					Y3 = 1;
					X3 = -1;
					Y4 = 0;
					X4 = -2;
					LStop1 = 1;
				}
				break;
			case 3:
				if (Place[YPose - 1][XPose] != char(0))
				{
					FPose = 2;
				}
				else if (Place[YPose + 1][XPose - 1] != char(0))
				{
					FPose = 2;
				}
				else if (Place[YPose + 1][XPose] != char(0))
				{
					FPose = 2;
				}
				else
				{
					Y2 = -2;
					X2 = 0;
					Y3 = 2;
					X3 = 0;
					Y4 = 2;
					X4 = -2;
					RStop = 13;
				}
				break;
			case 4:
				if (XPose == 13)
				{
					FPose = 3;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					FPose = 3;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					FPose = 3;
				}
				else if (Place[YPose + 1][XPose + 1] != char(0))
				{
					FPose = 3;
				}
				else
				{
					Y2 = -1;
					X2 = -1;
					Y3 = 1;
					X3 = 1;
					Y4 = 2;
					X4 = 0;
					RStop = 12;
				}
				break;
			}
			break;
		case EJ_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + 1 + Y2][XPose + X2] = char(0);
			Place[YPose - 1 + Y3][XPose + X3] = char(0);
			Place[YPose - 1 + Y4][XPose - 1 + X4] = char(0);
			FPose += 1;
			if (FPose > 4)
			{
				FPose = 1;
			}
			switch (FPose)
			{
			case 1:
				if (Place[XPose - 1][YPose - 1] != char(0))
				{
					FPose = 4;
				}
				else if (Place[XPose][YPose - 1] != char(0))
				{
					FPose = 4;
				}
				else if (Place[XPose][YPose + 1] != char(0))
				{
					FPose = 4;
				}
				else
				{
					X2 = 0;
					Y2 = 0;
					X3 = 0;
					Y3 = 0;
					X4 = 0;
					RStop1 = 13;
				}
				break;
			case 2:
				if (XPose == 13)
				{
					FPose = 1;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					FPose = 1;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					FPose = 1;
				}
				else if (Place[YPose + 1][XPose - 1] != char(0))
				{
					FPose = 1;
				}
				else
				{
					X2 = 1;
					Y2 = -1;
					X3 = -1;
					Y3 = 1;
					Y4 = 2;
					RStop1 = 12;
				}
				break;
			case 3:
				if (YPose == 0)
				{
					FPose = 2;
				}
				else if (Place[YPose - 1][XPose] != char(0))
				{
					FPose = 2;
				}
				else if (Place[YPose + 1][XPose] != char(0))
				{
					FPose = 2;
				}
				else if (Place[YPose + 1][XPose + 1] != char(0))
				{
					FPose = 2;
				}
				else
				{
					X2 = 0;
					Y2 = -2;
					X3 = 0;
					Y3 = 2;
					X4 = 2;
					LStop = 0;
				}
				break;
			case 4:
				if (XPose == 0)
				{
					FPose = 3;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					FPose = 3;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					FPose = 3;
				}
				else if (Place[YPose - 1][XPose + 1] != char(0))
				{
					FPose = 3;
				}
				else
				{
					X2 = -1;
					Y2 = -1;
					X3 = 1;
					Y3 = 1;
					Y4 = 0;
					LStop = 1;
				}
				break;
			}
			break;
		case ER_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + Y2][XPose + 1 + X2] = char(0);
			Place[YPose - 1 + Y3][XPose + X3] = char(0);
			Place[YPose - 1 + Y4][XPose - 1 + X4] = char(0);
			FPose += 1;
			if (FPose > 4)
			{
				FPose = 1;
			}
			switch (FPose)
			{
			case 1:
				if (XPose == 0)
				{
					FPose = 4;
				}
				else if (Place[YPose - 1][XPose] != char(0))
				{
					FPose = 4;
				}
				else if (Place[YPose - 1][XPose - 1] != char(0))
				{
					FPose = 4;
				}
				else
				{
					X2 = 0;
					Y2 = 0;
					X3 = 0;
					Y3 = 0;
					X4 = 0;
					LStop = 1;
				}
				break;
			case 2:
				if (Place[YPose][XPose - 1] != char(0))
				{
					FPose = 1;
				}
				else if (Place[YPose + 1][XPose - 1] != char(0))
				{
					FPose = 1;
				}
				else
				{
					X2 = -1;
					Y2 = -1;
					X3 = -1;
					Y3 = 1;
					Y4 = 2;
					RStop = 13;
				}
				break;
			case 3:
				if (XPose == 13)
				{
					FPose = 2;
				}
				else if (Place[YPose + 1][XPose] != char(0))
				{
					FPose = 2;
				}
				else if (Place[YPose + 1][XPose + 1] != char(0))
				{
					FPose = 2;
				}
				else
				{
					X2 = -2;
					Y2 = 0;
					X3 = 0;
					Y3 = 2;
					X4 = 2;
					RStop = 12;
				}
				break;
			case 4:
				if (Place[YPose - 1][XPose + 1] != char(0))
				{
					FPose = 3;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					FPose = 3;
				}
				else
				{
					X2 = -1;
					Y2 = 1;
					X3 = 1;
					Y3 = 1;
					X4 = 2;
					Y4 = 0;
					LStop = 0;
				}
				break;
			}
			break;
		case EZ_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + Y2][XPose - 1 + X2] = char(0);
			Place[YPose - 1 + Y3][XPose + 1 + X3] = char(0);
			Place[YPose - 1 + Y4][XPose + X4] = char(0);
			FPose += 1;
			if (FPose > 4)
			{
				FPose = 1;
			}
			switch (FPose)
			{
			case 1:
				if (XPose == 0)
				{
					FPose = 4;
				}
				else if (Place[YPose - 1][XPose + 1] != char(0))
				{
					FPose = 4;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					FPose = 4;
				}
				else
				{
					X2 = 0;
					Y2 = 0;
					X3 = 0;
					Y3 = 0;
					X4 = 0;
					Y4 = 0;
					LStop = 1;
				}
				break;
			case 2:
				if (Place[YPose - 1][XPose - 1] != char(0))
				{
					FPose = 1;
				}
				else if (Place[YPose + 1][XPose] != char(0))
				{
					FPose = 1;
				}
				else
				{
					X2 = 1;
					Y2 = 1;
					X3 = -2;
					Y3 = 1;
					X4 = -1;
					RStop = 13;
				}
				break;
			case 3:
				if (XPose == 13)
				{
					FPose = 2;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					FPose = 2;
				}
				else if (Place[YPose + 1][XPose - 1] != char(0))
				{
					FPose = 2;
				}
				else
				{
					X2 = 2;
					Y2 = 0;
					X3 = -1;
					Y3 = 2;
					Y4 = 2;
					RStop = 12;
				}
				break;
			case 4:
				if (Place[YPose - 1][XPose] != char(0))
				{
					FPose = 3;
				}
				else if (Place[YPose + 1][XPose + 1] != char(0))
				{
					FPose = 3;
				}
				else
				{
					X2 = 1;
					Y2 = -1;
					X3 = 0;
					Y3 = 1;
					X4 = 1;
					Y4 = 2;
					LStop = 0;
				}
				break;
			}
			break;
		case EI_FType:
			Place[YPose][XPose] = char(0);
			Place[YPose + 1 + Y2][XPose + X2] = char(0);
			Place[YPose - 1 + Y3][XPose + X3] = char(0);
			Place[YPose - 2 + Y4][XPose + X4] = char(0);
			FPose += 1;
			if (FPose > 4)
			{
				FPose = 1;
			}
			switch (FPose)
			{
			case 1:
				if (YPose == 0)
				{
					FPose = 4;
				}
				else if (YPose == 1)
				{
					FPose = 4;
				}
				else if (Place[YPose - 2][XPose] != char(0))
				{
					FPose = 4;
				}
				else if (Place[YPose - 1][XPose] != char(0))
				{
					FPose = 4;
				}
				else if (Place[YPose + 1][XPose] != char(0))
				{
					FPose = 4;
				}
				else
				{
					X2 = 0;
					Y2 = 0;
					X3 = 0;
					Y3 = 0;
					X4 = 0;
					Y4 = 0;
					RStop1 = 13;
					LStop1 = 0;
				}
				break;
			case 2:
				if (XPose == 0)
				{
					FPose = 1;
				}
				else if (XPose == 1)
				{
					FPose = 1;
				}
				else if (XPose == 13)
				{
					FPose = 1;
				}
				else if (Place[YPose][XPose - 2] != char(0))
				{
					FPose = 1;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					FPose = 1;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					FPose = 1;
				}
				else
				{
					X2 = 1;
					Y2 = -1;
					X3 = -1;
					Y3 = 1;
					X4 = -2;
					Y4 = 2;
					RStop1 = 12;
					LStop1 = 2;
				}
				break;
			case 3:
				if (YPose == 0)
				{
					FPose = 2;
				}
				else if (Place[YPose - 1][XPose] != char(0))
				{
					FPose = 2;
				}
				else if (Place[YPose + 1][XPose] != char(0))
				{
					FPose = 2;
				}
				else if (Place[YPose + 2][XPose] != char(0))
				{
					FPose = 2;
				}
				else
				{
					X2 = 0;
					Y2 = -2;
					X3 = 0;
					Y3 = 2;
					X4 = 0;
					Y4 = 4;
					RStop1 = 13;
					LStop1 = 0;
				}
				break;
			case 4:
				if (XPose == 0)
				{
					FPose = 3;
				}
				else if (XPose == 13)
				{
					FPose = 3;
				}
				else if (XPose == 12)
				{
					FPose = 3;
				}
				else if (Place[YPose][XPose - 1] != char(0))
				{
					FPose = 3;
				}
				else if (Place[YPose][XPose + 1] != char(0))
				{
					FPose = 3;
				}
				else if (Place[YPose][XPose + 2] != char(0))
				{
					FPose = 3;
				}
				else
				{
					X2 = -1;
					Y2 = -1;
					X3 = 1;
					Y3 = 1;
					X4 = 2;
					Y4 = 2;
					RStop1 = 11;
					LStop1 = 1;
				}
				break;
			}
			break;
		}
		RedrawPlace();
		break;
	case EKt_Down:
		Timer_On();
		break;
	case EKt_Y:
		if (EndBut == true)
		{
			Retry();
		}
		break;
	case EKt_N:
		if (EndBut == true)
		{
			exit(EXIT_SUCCESS);
		}
		break;
	}
	return 0;
}

void Draw_Place(HDC hdc)
{
	int x, y;
	for (y = 0; y < 17; y++)
	{
		for (x = 0; x < 14; x++)
		{
			if (Place[y][x] == 0)
			{
				SelectObject(hdc, BG2_Pen);
				SelectObject(hdc, BG2_Brush);
			}
			else if (Place[y][x] == 1)
			{
				SelectObject(hdc, BC_Pen);
				SelectObject(hdc, BC_Brush);
			}
			else if (Place[y][x] == 2)
			{
				SelectObject(hdc, GC_Pen);
				SelectObject(hdc, GC_Brush);
			}
			else if (Place[y][x] == 3)
			{
				SelectObject(hdc, RC_Pen);
				SelectObject(hdc, RC_Brush);
			}
			else if (Place[y][x] == 4)
			{
				SelectObject(hdc, LC_Pen);
				SelectObject(hdc, LC_Brush);
			}
			else if (Place[y][x] == 5)
			{
				SelectObject(hdc, DBC_Pen);
				SelectObject(hdc, DBC_Brush);
			}
			else if (Place[y][x] == 6)
			{
				SelectObject(hdc, VC_Pen);
				SelectObject(hdc, VC_Brush);
			}
			else if (Place[y][x] == 7)
			{
				SelectObject(hdc, LVC_Pen);
				SelectObject(hdc, LVC_Brush);
			}
			Rectangle(hdc, 291 + (16 * x), 524 - (16 * y), 306 + (16 * x), 539 - (16 * y));
		}
	}
}

void Draw_Interface(HDC hdc, RECT& paint_area)
{
	Create_PenAndBrush(255, 128, 0, BG1_Pen, BG1_Brush);
	SelectObject(hdc, BG1_Pen);
	SelectObject(hdc, BG1_Brush);
	Rectangle(hdc, 0, 0, 290, 540);
	Rectangle(hdc, 515, 0, 720, 540);
	Create_PenAndBrush(0, 0, 0, BG2_Pen, BG2_Brush);
	SelectObject(hdc, BG2_Pen);
	SelectObject(hdc, BG2_Brush);
	Rectangle(hdc, 290, 0, 515, 540);
	// 16 клеток
	Rectangle(hdc, 118, 208, 199, 305);
	Rectangle(hdc, 93, 320, 224, 340);
	SetTextColor(hdc, RGB(0, 0, 0));
	TextOut(hdc, 95, 322, L"Score: ", lstrlen(L"Score: "));
	wchar_t t[256];
	swprintf_s(t, L"%d", Score);
	if (Score > 9999)
	{
		TextOut(Hdc1, 138, 322, t, lstrlen(L"00000"));
	}
	else if (Score > 999)
	{
		TextOut(Hdc1, 138, 322, t, lstrlen(L"0000"));
	}
	else if (Score > 99)
	{
		TextOut(Hdc1, 138, 322, t, lstrlen(L"000"));
	}
	else if (Score == 0)
	{
		TextOut(Hdc1, 138, 322, t, lstrlen(L"0"));
	}
}

void Draw_function(HDC hdc, RECT& paint_area)
{
	Init_Wind(hdc);
	Draw_Interface(hdc, paint_area);
	Draw_Figures();
	if (C == true)
	{
		Draw_Place(hdc);
	}
	Draw_PlaceF(hdc);
}

int Timer_On()
{
	switch (FType)
	{
	case ET_FType:
		switch (FPose)
		{
		case 1:
			if (Place[YPose - 1][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose + Y2 - 1][XPose + 1 + X2] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose + Y4 - 1][XPose - 1 + X4] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 0)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + Y2][XPose + 1 + X2] = char(0);
				Place[YPose + 1 + Y3][XPose + X3] = char(0);
				Place[YPose + Y4][XPose - 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 2:
			if (Place[YPose + Y2 - 1][XPose + 1 + X2] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 2][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + Y2][XPose + 1 + X2] = char(0);
				Place[YPose + 1 + Y3][XPose + X3] = char(0);
				Place[YPose + Y4][XPose - 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 3:
			if (Place[YPose + 1 + Y3 - 1][XPose + X3] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose + Y2 - 1][XPose + 1 + X2] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose + Y4 - 1][XPose - 1 + X4] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + Y2][XPose + 1 + X2] = char(0);
				Place[YPose + 1 + Y3][XPose + X3] = char(0);
				Place[YPose + Y4][XPose - 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 4:
			if (Place[YPose - 1][XPose - 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 2][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + Y2][XPose + 1 + X2] = char(0);
				Place[YPose + 1 + Y3][XPose + X3] = char(0);
				Place[YPose + Y4][XPose - 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		}
		RedrawPlace();
		break;
	case EL_FType:
		switch (FPose)
		{
		case 1:
			if (Place[YPose - 2][XPose + 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 2][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + 1 + Y2][XPose + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 1 + Y4][XPose + 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 2:
			if (Place[YPose - 2][XPose - 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose + 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + 1 + Y2][XPose + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 1 + Y4][XPose + 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 3:
			if (Place[YPose - 2][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose][XPose - 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + 1 + Y2][XPose + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 1 + Y4][XPose + 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 4:
			if (Place[YPose - 1][XPose - 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose + 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 0)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + 1 + Y2][XPose + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 1 + Y4][XPose + 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		}
		RedrawPlace();
		break;
	case EJ_FType:
		switch (FPose)
		{
		case 1:
			if (Place[YPose - 2][XPose - 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 2][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + 1 + Y2][XPose + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 1 + Y4][XPose - 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 2:
			if (Place[YPose - 1][XPose - 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose + 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 0)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + 1 + Y2][XPose + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 1 + Y4][XPose - 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 3:
			if (Place[YPose - 2][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose][XPose + 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + 1 + Y2][XPose + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 1 + Y4][XPose - 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 4:
			if (Place[YPose - 1][XPose - 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 2][XPose + 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + 1 + Y2][XPose + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 1 + Y4][XPose - 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		}
		RedrawPlace();
		break;
	case ER_FType:
		switch (FPose)
		{
		case 1:
			if (Place[YPose - 2][XPose - 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 2][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose + 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + Y2][XPose + 1 + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 1 + Y4][XPose - 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 2:
			if (Place[YPose - 1][XPose - 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 2][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + Y2][XPose + 1 + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 1 + Y4][XPose - 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 3:
			if (Place[YPose - 1][XPose - 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose][XPose + 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 0)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + Y2][XPose + 1 + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 1 + Y4][XPose - 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 4:
			if (Place[YPose - 2][XPose + 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + Y2][XPose + 1 + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 1 + Y4][XPose - 1 + X4] = char(0);
				YPose -= 1;
			}
			break;
		}
		RedrawPlace();
		break;
	case EZ_FType:
		switch (FPose)
		{
		case 1:
			if (Place[YPose - 1][XPose - 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 2][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 2][XPose + 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + Y2][XPose - 1 + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + 1 + X3] = char(0);
				Place[YPose - 1 + Y4][XPose + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 2:
			if (Place[YPose - 2][XPose - 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + Y2][XPose - 1 + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + 1 + X3] = char(0);
				Place[YPose - 1 + Y4][XPose + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 3:
			if (Place[YPose][XPose - 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose + 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 0)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + Y2][XPose - 1 + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + 1 + X3] = char(0);
				Place[YPose - 1 + Y4][XPose + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 4:
			if (Place[YPose - 2][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose + 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop = 1, RStop = 12;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + Y2][XPose - 1 + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + 1 + X3] = char(0);
				Place[YPose - 1 + Y4][XPose + X4] = char(0);
				YPose -= 1;
			}
			break;
		}
		RedrawPlace();
		break;
	case EI_FType:
		switch (FPose)
		{
		case 1:
			if (Place[YPose - 3][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 2)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + 1 + Y2][XPose + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 2 + Y4][XPose + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 2:
			if (Place[YPose - 1][XPose - 2] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose - 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose + 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 0)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + 1 + Y2][XPose + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 2 + Y4][XPose + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 3:
			if (Place[YPose - 2][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 1)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + 1 + Y2][XPose + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 2 + Y4][XPose + X4] = char(0);
				YPose -= 1;
			}
			break;
		case 4:
			if (Place[YPose - 1][XPose - 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose + 1] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (Place[YPose - 1][XPose + 2] != char(0))
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else if (YPose == 0)
			{
				XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop1 = 13;
				X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
				G = 1;
				Draw_Figures();
			}
			else
			{
				Place[YPose][XPose] = char(0);
				Place[YPose + 1 + Y2][XPose + X2] = char(0);
				Place[YPose - 1 + Y3][XPose + X3] = char(0);
				Place[YPose - 2 + Y4][XPose + X4] = char(0);
				YPose -= 1;
			}
			break;
		}
		RedrawPlace();
		break;
	case EB_FType:
		if (Place[YPose - 2][XPose] != char(0))
		{
			XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
			X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
			G = 1;
			Draw_Figures();
		}
		else if (Place[YPose - 2][XPose + 1] != char(0))
		{
			XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
			X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
			G = 1;
			Draw_Figures();
		}
		else if (YPose == 1)
		{
			XPose = 7, YPose = 15, FPose = 1, LStop1 = 0, RStop = 12;
			X2 = 0, X3 = 0, X4 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
			G = 1;
			Draw_Figures();
		}
		else
		{
			Place[YPose][XPose] = char(0);
			Place[YPose][XPose + 1] = char(0);
			Place[YPose - 1][XPose] = char(0);
			Place[YPose - 1][XPose + 1] = char(0);
			YPose -= 1;
		}
		RedrawPlace();
		break;
	}
	return 0;
}