#include "Engine.h"

HPEN BG1_Pen, BG2_Pen, BC_Pen, GC_Pen, RC_Pen, LC_Pen, DBC_Pen, VC_Pen, LVC_Pen, Wi_Pen;
HBRUSH BG1_Brush, BG2_Brush, BC_Brush, GC_Brush, RC_Brush, LC_Brush, DBC_Brush, VC_Brush, LVC_Brush, Wi_Brush;
HWND Hwnd;
RECT PlaceArea, PlaceFArea, ScoreArea;
Figure* _Figure;
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
void Message(HDC hdc)
{
	SelectObject(hdc, Wi_Pen);
	SelectObject(hdc, Wi_Brush);
	Rectangle(hdc, 245, 270, 550, 360);
	SelectObject(hdc, BG2_Pen);
	SelectObject(hdc, BG2_Brush);
	Rectangle(hdc, 240, 265, 545, 355);
	TextOut(hdc, 365, 240, L"Game Over", lstrlen(L"Game Over"));
	TextOut(hdc, 377, 280, L"Retry?", lstrlen(L"Retry?"));
	TextOut(hdc, 330, 310, L"[Y]Yes!", lstrlen(L"[Y]Yes!"));
	TextOut(hdc, 420, 310, L"[N]No", lstrlen(L"[N]No"));
}
void Set_Figure()
{
	delete _Figure;
	CheckLine(Place[0], &Score, &Time);
	Init_Time();
	InvalidateRect(Hwnd, &ScoreArea, FALSE);
	RedrawPlace();
	if (!CheckPlace(Place[0]))
	{
		EndBut = true;
		_Figure = new Figure(Place[0]); 
		return;
	}
	Choice = ChoiceF;
	ChoiceF = rand() % 7;
	SetFutureFigure(PlaceF[0], ChoiceF);
	InvalidateRect(Hwnd, &PlaceFArea, FALSE);
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
	ClearPlace(Place[0]);
	ClearFuturePlace(PlaceF[0]);
	Score = 0, Time = 1000, EndBut = false;
	Init_Logic();
	RedrawPlace();
	SetFutureFigure(PlaceF[0], ChoiceF);
}
int On_Key_Down(EKey_type EKtype)
{
	switch (EKtype)
	{
	case EKey_type::Left:
		_Figure->MoveLeft();
		RedrawPlace();
		break;
	case EKey_type::Right:
		_Figure->MoveRight();
		RedrawPlace();
		break;
	case EKey_type::Up:
		_Figure->Rotate();
		RedrawPlace();
		break;
	case EKey_type::Down:
		Timer_On();
		break;
	case EKey_type::Y:
		if (EndBut == true)
			Retry();
		break;
	case EKey_type::N:
		if (EndBut == true)
			exit(EXIT_SUCCESS);
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
	Rectangle(hdc, 118, 208, 199, 305);
	Rectangle(hdc, 93, 320, 224, 340);
	SetTextColor(hdc, RGB(0, 0, 0));
	TextOut(hdc, 95, 322, L"Score: ", lstrlen(L"Score: "));
	wchar_t t[256];
	swprintf_s(t, L"%d", Score);
	if (Score > 9999)
	{
		TextOut(hdc, 138, 322, t, lstrlen(L"00000"));
	}
	else if (Score > 999)
	{
		TextOut(hdc, 138, 322, t, lstrlen(L"0000"));
	}
	else if (Score > 99)
	{
		TextOut(hdc, 138, 322, t, lstrlen(L"000"));
	}
	else if (Score == 0)
	{
		TextOut(hdc, 138, 322, t, lstrlen(L"0"));
	}
}
void Draw_function(HDC hdc, RECT& paint_area)
{
	Draw_Interface(hdc, paint_area);
	Draw_Place(hdc);
	Draw_PlaceF(hdc);
	if (EndBut == true)
		Message(hdc);
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