#include "Engine.h"

HPEN BG1_Pen, BG2_Pen, BC_Pen, GC_Pen, RC_Pen, LC_Pen, DBC_Pen, VC_Pen, LVC_Pen, Wi_Pen;
HBRUSH BG1_Brush, BG2_Brush, BC_Brush, GC_Brush, RC_Brush, LC_Brush, DBC_Brush, VC_Brush, LVC_Brush, Wi_Brush;
HWND Hwnd;
HDC Hdc1;
RECT PlaceArea, PlaceFArea, ScoreArea;
Figure* _Figure;

int XPoseF = 2, YPoseF = 3;
int Score = 0, Time = 1000;
int Choice, ChoiceF;
bool EndBut = false;
char Place[17][14] =
{
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
};
char PlaceF[6][5] =
{
	{ '0', '0', '0', '0', '0'},
	{ '0', '0', '0', '0', '0'},
	{ '0', '0', '0', '0', '0'},
	{ '0', '0', '0', '0', '0'},
	{ '0', '0', '0', '0', '0'},
	{ '0', '0', '0', '0', '0'},
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
			switch (PlaceF[y][x])
			{
			case '0':
				SelectObject(hdc, BG2_Pen);
				SelectObject(hdc, BG2_Brush);
				break;
			case '1':
				SelectObject(hdc, BC_Pen);
				SelectObject(hdc, BC_Brush);
				break;
			case '2':
				SelectObject(hdc, GC_Pen);
				SelectObject(hdc, GC_Brush);
				break;
			case '3':
				SelectObject(hdc, RC_Pen);
				SelectObject(hdc, RC_Brush);
				break;
			case '4':
				SelectObject(hdc, LC_Pen);
				SelectObject(hdc, LC_Brush);
				break;
			case '5':
				SelectObject(hdc, DBC_Pen);
				SelectObject(hdc, DBC_Brush);
				break;
			case '6':
				SelectObject(hdc, VC_Pen);
				SelectObject(hdc, VC_Brush);
				break;
			case '7':
				SelectObject(hdc, LVC_Pen);
				SelectObject(hdc, LVC_Brush);
				break;
			}
			Rectangle(hdc, 119 + x + (15 * x), 209 + y + (15 * y), 119 + (15 * (x + 1)) + x, 209 + (15 * (y + 1) + y));
		}
	}
}

void Init_Wind(HDC hdc)
{
	Hdc1 = hdc;
}

void RemoveLine(int y)
{
	while (y > 0)
	{
		for (int x = 0; x < 14; x++)
		{
			Place[y][x] = Place[y - 1][x];
		}
		y--;
	}
}

void CheckLine()
{
	bool containO;
	for (int y = 0; y < 17; y++)
	{
		containO = false;
		for (int x = 0; x < 14; x++)
		{
			if (Place[y][x] == '0')
			{
				containO = true;
				break;
			}
		}
		if (!containO)
		{
			RemoveLine(y);
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

bool CheckPlace()
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 3; x < 9; x++)
		{
			if (Place[y][x] != '0')
				return false;
		}
	}
	return true;
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
	RedrawPlace();
}

void Redraw_Choice()
{
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			PlaceF[y][x] = '0';
		}
	}
	switch (ChoiceF)
	{
	case 0:
		PlaceF[YPoseF][XPoseF] = '1';
		PlaceF[YPoseF - 1][XPoseF] = '1';
		PlaceF[YPoseF][XPoseF - 1] = '1';
		PlaceF[YPoseF][XPoseF + 1] = '1';
		break;
	case 1:
		PlaceF[YPoseF][XPoseF] = '2';
		PlaceF[YPoseF + 1][XPoseF] = '2';
		PlaceF[YPoseF + 1][XPoseF + 1] = '2';
		PlaceF[YPoseF - 1][XPoseF] = '2';
		break;
	case 2:
		PlaceF[YPoseF][XPoseF] = '3';
		PlaceF[YPoseF + 1][XPoseF] = '3';
		PlaceF[YPoseF + 1][XPoseF - 1] = '3';
		PlaceF[YPoseF - 1][XPoseF] = '3';
		break;
	case 3:
		PlaceF[YPoseF][XPoseF] = '4';
		PlaceF[YPoseF][XPoseF - 1] = '4';
		PlaceF[YPoseF - 1][XPoseF] = '4';
		PlaceF[YPoseF - 1][XPoseF + 1] = '4';
		break;
	case 4:
		PlaceF[YPoseF][XPoseF] = '5';
		PlaceF[YPoseF][XPoseF + 1] = '5';
		PlaceF[YPoseF - 1][XPoseF] = '5';
		PlaceF[YPoseF - 1][XPoseF - 1] = '5';
		break;
	case 5:
		PlaceF[YPoseF][XPoseF] = '6';
		PlaceF[YPoseF - 1][XPoseF] = '6';
		PlaceF[YPoseF - 2][XPoseF] = '6';
		PlaceF[YPoseF + 1][XPoseF] = '6';
		break;
	case 6:
		PlaceF[YPoseF][XPoseF] = '7';
		PlaceF[YPoseF][XPoseF - 1] = '7';
		PlaceF[YPoseF - 1][XPoseF] = '7';
		PlaceF[YPoseF - 1][XPoseF - 1] = '7';
		break;
	}
	InvalidateRect(Hwnd, &PlaceFArea, FALSE);
}

void Set_Figure()
{
	CheckLine();
	if (!CheckPlace())
	{
		Message();
		return;
	}
	Choice = ChoiceF;
	ChoiceF = rand() % 7;
	Redraw_Choice();
	delete _Figure;
	switch (Choice)
	{
	case 0:
		_Figure = new TFigure(Place[0]);
		break;
	case 1:
		_Figure = new LFigure(Place[0]);
		break;
	case 2:
		_Figure = new JFigure(Place[0]);
		break;
	case 3:
		_Figure = new RFigure(Place[0]);
		break;
	case 4:
		_Figure = new ZFigure(Place[0]);
		break;
	case 5:
		_Figure = new IFigure(Place[0]);
		break;
	case 6:
		_Figure = new BFigure(Place[0]);
		break;
	}
}

void Init_Logic()
{
	ChoiceF = rand() % 7;
	Set_Figure();
}

void Retry()
{
	int x, y;
	for (y = 0; y < 17; y++)
	{
		for (x = 0; x < 14; x++)
		{
			Place[y][x] = '0';
		}
	}
	for (y = 0; y < 6; y++)
	{
		for (x = 0; x < 5; x++)
		{
			PlaceF[y][x] = '0';
		}
	}
	Score = 0, Time = 1000, EndBut = false;
	Init_Logic();
	RedrawPlace();
	Redraw_Choice();
}

int On_Key_Down(EKey_type EKtype)
{
	switch (EKtype)
	{
	case EKt_Left:
		_Figure->MoveLeft();
		RedrawPlace();
		break;
	case EKt_Right:
		_Figure->MoveRight();
		RedrawPlace();
		break;
	case EKt_Up:
		_Figure->Rotate();
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
			switch (Place[16 - y][x])
			{
			case '0':
				SelectObject(hdc, BG2_Pen);
				SelectObject(hdc, BG2_Brush);
				break;
			case '1':
				SelectObject(hdc, BC_Pen);
				SelectObject(hdc, BC_Brush);
				break;
			case '2':
				SelectObject(hdc, GC_Pen);
				SelectObject(hdc, GC_Brush);
				break;
			case '3':
				SelectObject(hdc, RC_Pen);
				SelectObject(hdc, RC_Brush);
				break;
			case '4':
				SelectObject(hdc, LC_Pen);
				SelectObject(hdc, LC_Brush);
				break;
			case '5':
				SelectObject(hdc, DBC_Pen);
				SelectObject(hdc, DBC_Brush);
				break;
			case '6':
				SelectObject(hdc, VC_Pen);
				SelectObject(hdc, VC_Brush);
				break;
			case '7':
				SelectObject(hdc, LVC_Pen);
				SelectObject(hdc, LVC_Brush);
				break;
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
	Draw_Place(hdc);
	Draw_PlaceF(hdc);
}

int Timer_On()
{
	if (EndBut != true)
	{
		if (!_Figure->MoveDown())
			Set_Figure();
		RedrawPlace();
	}
	return 0;
}