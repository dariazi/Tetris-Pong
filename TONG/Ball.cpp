#pragma once
#include "Ball.h"
int countDownToBall;
int countDownToBomb;
void Ball::startDir()
{
	srand(time(0));
	int dir = rand();
	dir = dir % 4;

	if (dir == 0)
	{
		dir_x = 1;
		dir_y = 1;
	}
	if (dir == 1)
	{
		dir_x = 1;
		dir_y = -1;
	}
	if (dir == 2)
	{
		dir_x = -1;
		dir_y = 1;
	}
	if (dir == 3)
	{
		dir_x = -1;
		dir_y = -1;
	}
}
int Ball::checkState()
{
	if (globalBomb == true)
	{
		currMode = preBomb;
		countDownToBomb = BOMB_COUNTDOWN;
		globalBomb = false;
	}
	return currMode;
}
void Ball::move()
{
	upL.draw(' ');
	upR.draw(' ');
	mid1.draw(' ');
	mid2.draw(' ');
	mid3.draw(' ');
	mid4.draw(' ');
	downL.draw(' ');
	downR.draw(' ');
	if (mid4.x + dir_x == MAX_X || mid1.x + dir_x == MIN_X) {
		dir_x = -dir_x;
	}
	if (downL.y + dir_y >= MAX_Y || downR.y + dir_y >= MAX_Y
		|| upL.y + dir_y <= MIN_Y || upR.y + dir_y <= MIN_Y) {
		dir_y = -dir_y;
	}

	upL.x += dir_x;
	upR.x += dir_x;
	mid1.x += dir_x;
	mid2.x += dir_x;
	mid3.x += dir_x;
	mid4.x += dir_x;
	downL.x += dir_x;
	downR.x += dir_x;

	upL.y += dir_y;
	upR.y += dir_y;
	mid1.y += dir_y;
	mid2.y += dir_y;
	mid3.y += dir_y;
	mid4.y += dir_y;
	downL.y += dir_y;
	downR.y += dir_y;

}

void Ball::moveAfterHit()
{
	dir_x = -dir_x;

	upL.x += dir_x;
	upR.x += dir_x;
	mid1.x += dir_x;
	mid2.x += dir_x;
	mid3.x += dir_x;
	mid4.x += dir_x;
	downL.x += dir_x;
	downR.x += dir_x;

	upL.y += dir_y;
	upR.y += dir_y;
	mid1.y += dir_y;
	mid2.y += dir_y;
	mid3.y += dir_y;
	mid4.y += dir_y;
	downL.y += dir_y;
	downR.y += dir_y;

}


bool Ball::isHitTheBoardRight(Board & playerR)
{
	
	if (this->getXright() == playerR.getX())
	{
		if (this->getYup() <= playerR.getUpY() && this->getYdown() >= (playerR.getDownY()))
			return true;

	}
	return false;

}
bool Ball::isHitTheBoardLeft(Board & playerL)
{
	if (this->getXleft() == playerL.getX())
	{
		if (this->getYup() <= playerL.getUpY() && this->getYdown() >= (playerL.getDownY()))
			return true;
	}
	
	return false;

}
bool Ball::isMissedLeft(const Board playerL)
{	
	if (this->getXleft() == playerL.getX())
	{
		if (this->getYup() > playerL.getUpY() || this->getYdown() < playerL.getDownY())
			return true;
	}
	else if (this->getXleft() < playerL.getX())
		return true;
	return false;
}

bool Ball::isMissedRight(const Board playerR)
{
	if (this->getXright() == playerR.getX())
	{
		if (this->getYup() > playerR.getUpY() || this->getYdown() < playerR.getDownY())
			return true;
	}
	else if (this->getXright() > playerR.getX())
		return true;
	return false;
}
