#include "PcBoard.h"

void PcBoard::MoveBy(Ball & b, Board & enemy)
{
	int bY = b.getYup() + 1;
	int boardY = up.getY() - 1;
	int random = 0;
	if (is2StepsAway(b))
		random = (rand() % (level * 10 + 1));

	attackEnemy(b, enemy);

	if (random != 1)
	{
		if (boardY > bY)
		{
			if (!up.isMax())
			{
				up.erase();
				down.move(0, -1);
				up.move(0, -1);
				setColor(COLOR::WHITE_TEXT);
				down.draw();
			}
		}
		if (boardY < bY)
		{
			if (!down.isMin())
			{
				down.erase();
				up.move(0, 1);
				down.move(0, 1);
				setColor(COLOR::WHITE_TEXT);
				up.draw();
			}
		}
	}
	else
	{
		if (boardY > bY)
		{
			if (!down.isMin())
			{
				down.erase();
				up.move(0, 1);
				down.move(0, 1);
				setColor(COLOR::WHITE_TEXT);
				up.draw();
			}
			if (!down.isMin())
			{
				down.erase();
				up.move(0, 1);
				down.move(0, 1);
				setColor(COLOR::WHITE_TEXT);
				up.draw();
			}
		}
		if (boardY < bY)
		{
			if (!up.isMax())
			{
				up.erase();
				down.move(0, -1);
				up.move(0, -1);
				setColor(COLOR::WHITE_TEXT);
				down.draw();
			}
			if (!up.isMax())
			{
				up.erase();
				down.move(0, -1);
				up.move(0, -1);
				setColor(COLOR::WHITE_TEXT);
				down.draw();
			}
		}

	}


}

bool PcBoard::is2StepsAway(Ball b)
{
	return ((b.getXleft() - 1) == getX() || (b.getXright() + 1 == getX()));
}

void PcBoard::attackEnemy(Ball & b, Board & enemy)
{
	int attack = rand()%2;
	if ((((b.getXleft() == enemy.getX() + 8)&& b.getDirX()==-1)||(( b.getXright() == enemy.getX() - 8) && b.getDirX() == 1)) && attack==1 && coolDown==0)
		triggerBomb();
}