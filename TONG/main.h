
#include "gameManager.h"
#include "Utils.h"
#include "Screen.h"
#include "ball.h"
#include "board.h"
#include "UserBoard.h"
#include "PcBoard.h"


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;
enum { BEST = 0, GOOD = 4, NOVICE = 1 };


void drawMenu();
void drawMarker(int y);
void eraseMarker(int y);
void down(int& y);
void up(int& y);
void viewInstructions();
void setcursor(bool visible, DWORD size);
int whichLevel(int y);
