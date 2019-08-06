#include "UserBoard.h"

void UserBoard::handleKey(char c)
{
	ch = c;
}

void UserBoard::MoveBy(Ball& b,  Board& enemy )
{
	if (ch == 0)
		return; 
	if (ch == kbChars[2]) {
		if (disableTrigger != true)
		{
			triggerBomb();// TODO write function to trigger the bomb
		}
	}
	else if (ch == kbChars[0] || ch - 'A' + 'a' == kbChars[0]) {
		if (!up.isMax()){
				down.erase();
				down.move(0, 1);
				up.move(0, 1);
				setColor(COLOR::WHITE_TEXT);
				up.draw();
		}
	}
	else if (ch == kbChars[1] || ch - 'A' + 'a' == kbChars[1]) {
		if (!down.isMin())	{
				up.erase();
				up.move(0, -1);
				down.move(0, -1);
				setColor(COLOR::WHITE_TEXT);
				down.draw();
			}
		}
	ch = 0;
	}
