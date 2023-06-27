#pragma once
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "Figure.h"
#include "BFigure.h"
#include "IFigure.h"
#include "JFigure.h"
#include "LFigure.h"
#include "RFigure.h"
#include "TFigure.h"
#include "ZFigure.h"

const int Timer_ID = WM_USER + 1;

enum EKey_type
{
	EKt_Left, EKt_Right, EKt_Up, EKt_Down, EKt_Y, EKt_N
};

void Init_Engine(HWND hwnd);
void Init_Time();
void Draw_function(HDC hdc, RECT& paint_area);
int On_Key_Down(EKey_type EKtype);
int Timer_On();