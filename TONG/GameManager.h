#pragma once
#include "Board.h"
#include "KeyboardManager.h"
#include "Ball.h"
#include <list>
#include <array>

bool start(int(&rightDeadArea)[20][25], int(&LeftDeadArea)[16][25], Board & playerLeft, Board & playerRight, Ball & b, KeyboardManager kb);
bool isFullLineLeft(int LeftDeadArea[16][25], Screen& screen);
bool isFullLineRight(int RightDeadArea[20][25], Screen& screen);
void drawDeadAreas(int LeftDeadArea[16][25], int RightDeadArea[20][25]);
void clearDeadAreas(int LeftDeadArea[16][25], int RightDeadArea[20][25]);
void leftClearImpact(int x, int LeftDeadArea[16][25], Screen & screen);
void rightClearImpact(int x, int RightDeadArea[20][25], Screen & screen);
