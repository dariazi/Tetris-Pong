#include "GameManager.h"
#include"UserBoard.h"
#include"PcBoard.h"
#include "KeyboardEventListener.h"

extern bool globalBomb;
extern int countDownToBall;
extern int countDownToBomb;


bool start(int(&RightDeadArea)[20][25], int(&LeftDeadArea)[16][25],
	Board& playerLeft, Board& playerRight, Ball& b, KeyboardManager kb)
{
	Screen screen;
	screen.drawScreen();
	bool exit = false;
	drawDeadAreas(LeftDeadArea, RightDeadArea);
	playerLeft.draw();
	playerRight.draw();
	b.draw();
	b.startDir();
	globalBomb = false;
	int curState;
	int leftX, rightX;

	while (!exit)
	{
		b.move();
		playerLeft.move(b, playerRight);
		playerRight.move(b, playerLeft);
		leftX = playerLeft.getX();
		rightX = playerRight.getX();
		exit = kb.handleKeyboard();
		curState = b.checkState();// ball checks if a player has triggred the bomb

		if (countDownToBomb > 0)// 
		{
			countDownToBomb--;
			if (countDownToBomb == 0)
			{
				b.triggerBomb();
			}
		}
		if (countDownToBall> 0)
		{
			countDownToBall--;
			if (countDownToBall == 0) {
				if (b.getXleft() >= leftX && b.getXright() <= rightX)// making sure bomb is between boards.
					b.upgradeMode(regBall);
			}
		}
		if (b.getXleft() + 1 == 40) {
			if (playerLeft.getTriggerState())
			{
				playerLeft.updateCoolDown();
				if (playerLeft.getCoolDown() == 0)
					playerLeft.enableTrigger();
			}
			if (playerRight.getTriggerState()) {
				playerRight.updateCoolDown();
				if (playerRight.getCoolDown() == 0)
					playerRight.enableTrigger();

			}
		}

		switch (curState) {
		case regBall:
			if (b.getXright() < 40) {
				if (b.isHitTheBoardLeft(playerLeft)) {
					b.moveAfterHit();
					break;
				}
				else if (b.isMissedLeft(playerLeft)) {
					if (leftX < 20)
					{
						playerLeft.BoardFallsLeft(playerLeft, LeftDeadArea);
						if (!isFullLineLeft(LeftDeadArea, screen))
						{

							playerLeft.draw(' ');
							playerLeft.replaceLeft(leftX + 1);

						}
						else
						{
							playerLeft.draw(' ');
							playerLeft.replaceLeft(leftX - 5);

						}
						b.replace();
						b.draw();
						playerLeft.draw();
						playerRight.draw(' ');
						playerRight.replaceRight(rightX);
						playerRight.draw();
						b.startDir();
						break;
					}
					else
					{
						std::cout << "Game OVER!" << '\n';
						std::cout << "right WIN LEFT LOSE" << '\n';
						Sleep(1000);
						return false;
					}
				}
			}
			else {
				if (b.isHitTheBoardRight(playerRight)) {
					b.moveAfterHit();
					break;
				}

				else if (b.isMissedRight(playerRight))
				{
					if (rightX > 60)
					{
						playerRight.BoardFallsRight(playerRight, RightDeadArea);
						if (!isFullLineRight(RightDeadArea, screen))
						{

							playerRight.draw(' ');
							playerRight.replaceRight(rightX - 1);

						}
						else {
							playerRight.draw(' ');
							playerRight.replaceRight(rightX + 5);
						}
						b.replace();
						b.draw();
						playerRight.draw();
						playerLeft.draw(' ');
						playerLeft.replaceLeft(leftX);
						playerLeft.draw();
						b.startDir();
						break;
					}
					else {
						std::cout << "Game OVER!" << '\n';
						std::cout << " left WIN right LOSE" << '\n';
						Sleep(1000);
						return false;

					}
				}
			}
			break;
		case preBomb:
			if (b.getXright() < 40) {

				if (b.isHitTheBoardLeft(playerLeft)) {
					b.upgradeMode(regBall);
					b.moveAfterHit();
					break;
				}
				else if (b.isMissedLeft(playerLeft))
				{
					if (leftX < 20)
					{
						playerLeft.BoardFallsLeft(playerLeft, LeftDeadArea);
						if (!isFullLineLeft(LeftDeadArea, screen))
						{

							playerLeft.draw(' ');
							playerLeft.replaceLeft(leftX + 1);

						}
						else
						{
							playerLeft.draw(' ');
							playerLeft.replaceLeft(leftX - 5);

						}
						b.upgradeMode(regBall);
						b.replace();
						b.draw();
						playerLeft.draw();
						playerRight.draw(' ');
						playerRight.replaceRight(rightX);
						playerRight.draw();
						b.startDir();
						break;
					}
					else
					{
						std::cout << "Game OVER!" << '\n';
						std::cout << "right WIN LEFT LOSE" << '\n';
						Sleep(1000);
						return false;
					}
				}
			}
			else {

				if (b.isHitTheBoardRight(playerRight)) {
					b.upgradeMode(regBall);
					b.moveAfterHit();
					break;
				}

				else if (b.isMissedRight(playerRight))
				{
					if (rightX > 60)
					{
						playerRight.BoardFallsRight(playerRight, RightDeadArea);
						if (!isFullLineRight(RightDeadArea, screen))
						{

							playerRight.draw(' ');
							playerRight.replaceRight(rightX - 1);

						}
						else {
							playerRight.draw(' ');
							playerRight.replaceRight(rightX + 5);
						}
						b.replace();
						b.draw();
						playerRight.draw();
						playerLeft.draw(' ');
						playerLeft.replaceLeft(leftX);
						playerLeft.draw();
						b.startDir();
						break;
					}
					else {
						std::cout << "Game OVER!" << '\n';
						std::cout << " left WIN right LOSE" << '\n';
						Sleep(1000);
						return false;

					}
				}
			}
			break;
		case Bomb:
			if (b.isHitTheBoardLeft(playerLeft)) {

				if (leftX < 20)
				{
					playerLeft.BoardFallsLeft(playerLeft, LeftDeadArea);
					if (!isFullLineLeft(LeftDeadArea, screen))
					{

						playerLeft.draw(' ');
						playerLeft.replaceLeft(leftX + 3);

					}
					else
					{
						playerLeft.draw(' ');
						playerLeft.replaceLeft(leftX - 5);

					}
					b.replace();
					b.draw();
					playerLeft.draw();
					playerRight.draw(' ');
					playerRight.replaceRight(rightX);
					playerRight.draw();
					b.startDir();
					break;
				}
				else
				{
					std::cout << "Game OVER!" << '\n';
					std::cout << "right WIN LEFT LOSE" << '\n';
					Sleep(1000);
					return false;
				}
			}
			else if (b.isHitTheBoardRight(playerRight)) {

				if (rightX > 60)
				{
					playerRight.BoardFallsRight(playerRight, RightDeadArea);
					if (!isFullLineRight(RightDeadArea, screen))
					{

						playerRight.draw(' ');
						playerRight.replaceRight(rightX - 3);

					}
					else {
						playerRight.draw(' ');
						playerRight.replaceRight(rightX + 5);
					}
					b.replace();
					b.draw();
					playerRight.draw();
					playerLeft.draw(' ');
					playerLeft.replaceLeft(leftX);
					playerLeft.draw();
					b.startDir();
					break;
				}
				else {
					std::cout << "Game OVER!" << '\n';
					std::cout << " left WIN right LOSE" << '\n';
					Sleep(1000);
					return false;

				}
			}
			else if (b.isMissedLeft(playerLeft))
			{

				if (LeftDeadArea[b.getXleft() - 1][b.getYdown()] == 1 ||
					LeftDeadArea[b.getXleft() - 1][b.getYup()] == 1
					|| LeftDeadArea[b.getXleft() - 1][b.getYdown() - 1] == 1)
				{
					leftClearImpact(b.getXleft() - 1, LeftDeadArea, screen);
					playerLeft.draw(' ');
					playerLeft.replaceLeft(leftX - 1);
					playerLeft.draw();
					b.upgradeMode(regBall);
					b.replace();
					b.draw();
					b.startOppWay(1);
					break;

				}
				else if (b.getXleft() == 2)
				{
					playerLeft.draw(' ');
					playerLeft.replaceLeft(leftX);
					b.upgradeMode(regBall);
					b.replace();
					b.draw();
					b.startOppWay(1);
					playerLeft.draw();
					break;
				}
				else break;
			}
			else if (b.isMissedRight(playerRight))
			{

				if (RightDeadArea[b.getXright() - 60][b.getYdown()] == 1 ||
					RightDeadArea[b.getXright() - 60][b.getYup()] == 1
					|| RightDeadArea[b.getXright() - 60][b.getYdown() - 1] == 1)
				{
					rightClearImpact(b.getXright() - 60, RightDeadArea, screen);
					playerRight.draw(' ');
					playerRight.replaceRight(rightX + 1);
					playerRight.draw();
					b.upgradeMode(regBall);
					b.replace();
					b.draw();
					b.startOppWay(-1);
					break;

				}
				else if (b.getXright() == 78)
				{
					b.upgradeMode(regBall);
					b.replace();
					b.draw();
					b.startOppWay(1);
					playerRight.draw(' ');
					playerRight.replaceRight(rightX);
					playerRight.draw();
					break;
				}
				else break;
			}
		default: break;
		}

		b.draw();

		Sleep(50);

	}
	return true;
}


bool isFullLineLeft(int LeftDeadArea[16][25], Screen& screen)
{

	int i = 1, j = 4;
	bool full = false;

	while (j < 25)
	{
		if (LeftDeadArea[i][j] == 0)
		{
			j = 4;
			i++;
		}
		else
		{
			j++;
		}
		if (j == 25)
		{
			for (int k = 0; k < 25; k++)
			{
				LeftDeadArea[i][k] = 0;
			}
			screen.cleanLine(i);
			return true;
		}
		if (i == 16)
		{
			return false;
		}
	}
}

bool isFullLineRight(int RightDeadArea[20][25], Screen& screen)
{
	int i = 19, j = 4;
	bool full = false;
	
	while (j < 25)
	{
		if (RightDeadArea[i][j] == 0)
		{
			j = 4;
			i--;
		}
		else
		{
			j++;
		}
		if (j == 25)
		{
			for (int k = 0; k < 25; k++)
			{
				RightDeadArea[i][k] = 0;
			}
			screen.cleanLine(i + 60);
			return true;
		}
		if (i == 0)
		{
			return false;
		}
	}
}

void drawDeadAreas(int LeftDeadArea[16][25], int RightDeadArea[20][25])
{
	int i = 1, j = 4;
	while (i < 16)
	{
		while (j < 25)
		{
			if (LeftDeadArea[i][j] == 1)
			{
				setColor(COLOR::WHITE_TEXT);
				gotoxy(i, j);
				cout << "#";

			}
			j++;

		}
		i++;
		j = 4;
	}
	i = 1;
	j = 4;
	while (i < 20)
	{
		while (j < 25)
		{
			if (RightDeadArea[i][j] == 1)
			{
				setColor(COLOR::WHITE_TEXT);
				gotoxy(i + 60, j);
				cout << "#";

			}
			j++;

		}
		i++;
		j = 4;
	}


}

void clearDeadAreas(int LeftDeadArea[16][25], int RightDeadArea[20][25])
{
	int i = 1, j = 4;
	while (i < 16)
	{
		while (j < 25)
		{
			if (LeftDeadArea[i][j] == 1)
			{
				LeftDeadArea[i][j] = 0;
			}
			j++;

		}
		i++;
		j = 4;
	}
	j = 4;
	while (i < 20)
	{
		while (j < 25)
		{
			if (RightDeadArea[i][j] == 1)
			{
				RightDeadArea[i][j] = 0;
			}
			j++;

		}
		i++;
		j = 4;
	}


}
void rightClearImpact(int x, int RightDeadArea[20][25], Screen & screen)
{
	int i = x;
	for (int k = 0; k < 25; k++)
	{
		RightDeadArea[i][k] = 0;
	}
	screen.cleanLine(i + 60);
}
void leftClearImpact(int x, int LeftDeadArea[16][25], Screen & screen)
{
	int i = x;
	for (int k = 0; k < 25; k++)
	{
		LeftDeadArea[i][k] = 0;
	}
	screen.cleanLine(i);
}




