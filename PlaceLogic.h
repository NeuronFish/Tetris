#include "Figure.h"
#include "BFigure.h"
#include "IFigure.h"
#include "JFigure.h"
#include "LFigure.h"
#include "RFigure.h"
#include "TFigure.h"
#include "ZFigure.h"

void ClearFuturePlace(char* place);
void ClearPlace(char* place);
void SetFutureFigure(char* place, int type);
void CheckLine(char* place, int* score, int* time);
bool CheckPlace(char* place);
