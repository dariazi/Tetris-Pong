#pragma once
#include "Point.h"
#include"Board.h"
#include"Utils.h"
extern int countDownToBall;
extern int countDownToBomb;
enum Mode {// ball modes
		regBall,preBomb,Bomb
	};
class Ball
{ 
	Point upL = { 39, 9, 'O' };
	Point upR = { 40, 9, 'O' };
	Point mid1 = { 38, 10, 'O' };
	Point mid2 = { 39, 10, 'O' };
	Point mid3 = { 40, 10, 'O' };
	Point mid4 = { 41, 10, 'O' };
	Point downL = { 39, 11, 'O' };
	Point downR = { 40, 11, 'O' };
	int dir_x = 0;
	int dir_y = 0;
	enum { MAX_X = 79, MAX_Y = 24 };
	enum { MIN_X = 1, MIN_Y = 4 };
	enum {BOMB_COUNTDOWN=8, BALL_COUNTDOWN=4 };
	

	Mode currMode= regBall;
	
public:
	
	friend class Board;
	
	
	void move();
	int checkState();

	void startDir();

	bool isHitTheBoardLeft(Board & playerL);
	bool isHitTheBoardRight(Board & playerR);

	void moveAfterHit();
	int getDirX() {
		return dir_x;
	}
	bool isMissedLeft(const Board playerL);

	bool isMissedRight(const Board playerR);
	
	void triggerPreBomb() {
		upgradeMode(preBomb);
		countDownToBomb = BOMB_COUNTDOWN;
	}
	void triggerBomb() {
		this->currMode = Bomb;
		countDownToBall = BALL_COUNTDOWN;
	}

	enum Mode getCurrentMode()//retrieve current mode
	{
		return currMode;
	}
	void upgradeMode(Mode mode)//upgrade ball mode
	{
		currMode = mode;
		if (mode == regBall) {
			countDownToBomb == 0;
		}
		
	}
	void draw()
	{
		switch (currMode)
		{
		case regBall:
			setColor(COLOR::WHITE_TEXT);
			upL.draw();
			setColor(COLOR::WHITE_TEXT);
			upR.draw();
			setColor(COLOR::WHITE_TEXT);
			mid1.draw();
			setColor(COLOR::WHITE_TEXT);
			mid2.draw();
			setColor(COLOR::WHITE_TEXT);
			mid3.draw();
			setColor(COLOR::WHITE_TEXT);
			mid4.draw();
			setColor(COLOR::WHITE_TEXT);
			downL.draw();
			setColor(COLOR::WHITE_TEXT);
			downR.draw();
			break;
		case preBomb:
			setColor(COLOR::YELLOW_TEXT);
			upL.draw();
			setColor(COLOR::YELLOW_TEXT);
			upR.draw();
			setColor(COLOR::YELLOW_TEXT);
			mid1.draw();
			setColor(COLOR::YELLOW_TEXT);
			mid2.draw();
			setColor(COLOR::YELLOW_TEXT);
			mid3.draw();
			setColor(COLOR::YELLOW_TEXT);
			mid4.draw();
			setColor(COLOR::YELLOW_TEXT);
			downL.draw();
			setColor(COLOR::YELLOW_TEXT);
			downR.draw();
			break;
		case Bomb:
			setColor(COLOR::RED_TEXT);
			upL.draw();
			setColor(COLOR::RED_TEXT);
			upR.draw();
			setColor(COLOR::RED_TEXT);
			mid1.draw();
			setColor(COLOR::RED_TEXT);
			mid2.draw();
			setColor(COLOR::RED_TEXT);
			mid3.draw();
			setColor(COLOR::RED_TEXT);
			mid4.draw();
			setColor(COLOR::RED_TEXT);
			downL.draw();
			setColor(COLOR::RED_TEXT);
			downR.draw();
			break;
		default:
			break;
		}
		

	}

	void replace()
	{
		
		upL.draw(' ');
		upR.draw(' ');
		mid1.draw(' ');
		mid2.draw(' ');
		mid3.draw(' ');
		mid4.draw(' ');
		downL.draw(' ');
		downR.draw(' ');
		
		upL = { 39, 9, 'O' };
		upR = { 40, 9, 'O' };
		mid1 = { 38, 10, 'O' };
		mid2 = { 39, 10, 'O' };
		mid3 = { 40, 10, 'O' };
		mid4 = { 41, 10, 'O' };
		downL = { 39, 11, 'O' };
		downR = { 40, 11, 'O' };

	}

	int getYup()const
	{
		return upL.getY();
	}

	int getYdown()const
	{
		return downL.getY();
	}

	int getXleft()const {
		return mid1.getX();
	}

	int getXright()const {
		return mid4.getX();
	}
	void startOppWay(int dir)
	{
		dir_x = dir;
		dir_y = dir;
	}

};