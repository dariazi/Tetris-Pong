#pragma once

#include "Board.h"
#include "Point.h"
#include "ball.h"
class ball;

class PcBoard : public Board {
	int level = 0;
	enum { BEST = 0, GOOD = 4, NOVICE = 1 };
public:
	friend class ball;
	PcBoard(Point up, Point down) :Board(up, down) {}
	void MoveBy(Ball& b, Board & enemy);
	bool is2StepsAway(Ball b);
	void attackEnemy(Ball & ball, Board & enemy);
	int getTheLevel()
	{
		return level;
	}
	void setTheLevel(int LevelNew)
	{
		level = LevelNew;
	}

};