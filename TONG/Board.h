#pragma once
#include "Point.h"
#include "Ball.h"
#include <list>
#include <array>
class Ball;
extern bool globalBomb;	
const int DOWN_TIME = 4;

class Board {
protected:
	Point up, down;
	bool disableTrigger=false;
	int coolDown=0;
public:

	enum { MAX_X = 79, MAX_Y = 24 };
	enum { MIN_X = 1, MIN_Y = 4 };
	
	Board(const Point& up1, const Point& down1) : up(up1), down(down1) {}
	
	void draw();
	void draw(char ch);
	void move(Ball &b, Board & enemy);
	void BoardFallsLeft(Board PlayerLeft, int LefttDeadArea[16][25]);
	void BoardFallsRight(Board playerRight, int rightDeadArea[20][25]);
	int getCoolDown() {
		return coolDown;
	}
	void updateCoolDown() {
		coolDown--;
	}
	void enableTrigger() {
		disableTrigger = false;
	}
	bool getTriggerState()
	{
		return disableTrigger;
	}
	virtual void MoveBy(Ball& b, Board & enemy);

	void set(Point up1, Point down1)
	{
		this->up = up1;
		this->down = down1;
	}

	int getX()const {
		return up.getX();
	}

	int getUpY()const {
		return up.getY();
	}

	int getDownY()const {
		return down.getY();
	}

	void setX(int x) {
		up.set(x, up.getY(), '#');
		down.set(x, down.getY(), '#');
	}

	void replaceLeft(int x)
	{
		up.set(x, 12, '#');
		down.set(x, 10, '#');
	}

	void replaceRight(int x)
	{
		up.set(x, 13, '#');
		down.set(x, 11, '#');
	}
	void triggerBomb()
	{
		globalBomb = true;//enable bomb
		coolDown = DOWN_TIME; // start cool down
		disableTrigger = true; // disable player's bomb for the next 4 iterations
	}
};