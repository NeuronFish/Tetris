#pragma once
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "PlaceLogic.h"

const int Timer_ID = WM_USER + 1;

enum class EKey_type
{
	Left, Right, Up, Down, Y, N
};

void Init_Engine(HWND hwnd);
void Init_Time();
void Init_Logic();
void Draw_function(HDC hdc, RECT& paint_area);
int On_Key_Down(EKey_type EKtype);
int Timer_On();