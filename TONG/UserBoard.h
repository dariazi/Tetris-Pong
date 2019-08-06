#pragma once
#include "Board.h"
#include "Ball.h"
#include "Point.h"
#include"KeyboardEventListener.h"
class UserBoard :public Board, public KeyboardEventListener {
	char kbChars[3];
	char ch = 0;
public:
	friend class ball;

	UserBoard(Point up, Point down, const char& kbCharsDown, const char& kbCharsUp, const char & kbCharsBomb) :Board(up, down), kbChars{ kbCharsDown,kbCharsUp,kbCharsBomb } {}
	const char* getKbChars()
	{
		return kbChars;
	}
	void handleKey(char c);
	void MoveBy(Ball& b, Board & enemy);
}; 