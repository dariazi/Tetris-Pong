#include"main.h"
extern int countDownToBall, countDownToBomb;
int main()
{
	setcursor(0, 0);
	int rightDeadArea[20][25] = { 0 };
	int leftDeadArea[16][25] = { 0 };
	KeyboardManager kb;
	const int heightOfMark = 15;
	PcBoard playerLeftPC({ 4,12,'#' }, { 4,10,'#' });
	PcBoard playerRightPC({ 76,13,'#' }, { 76,11,'#' });
	UserBoard playerLeftUS({ 4,12,'#' }, { 4,10,'#' }, 'a', 'q', 's');
	UserBoard playerRightUS({ 76,13,'#' }, { 76,11,'#' }, 'l', 'p', 'k');
	Ball b;
	int whichPlay = 0;
	int Mark = 10;
	bool GameOn = false;

	char ch;
	drawMenu();
	drawMarker(Mark);
	while (true)
	{
		ch = _getch();
		while (ch != 'C'&& ch != 'c')
		{
			if (ch == 'a' || ch == 'A')
			{
				down(Mark);
			}
			if (ch == 'q' || ch == 'Q')
			{
				up(Mark);
			}
			ch = _getch();
		}
		if (Mark == 10)
		{
			whichPlay = 0;
			system("CLS");
			clearDeadAreas(leftDeadArea, rightDeadArea);
			playerLeftUS.set({ 4, 12, '#' }, { 4,10,'#' });
			playerRightUS.set({ 76,13,'#' }, { 76,11,'#' });
			kb.registerKbListener(&playerLeftUS);
			kb.registerKbListener(&playerRightUS);
			b.replace();
			countDownToBall = 0;
			countDownToBomb = 0;
			playerLeftUS.enableTrigger();
			playerRightUS.enableTrigger();

			GameOn = start(rightDeadArea, leftDeadArea, playerLeftUS, playerRightUS, b, kb);
			if (!GameOn)
			{
				clearDeadAreas(leftDeadArea, rightDeadArea);
				playerLeftUS.set({ 4, 12, '#' }, { 4,10,'#' });
				playerRightUS.set({ 76,13,'#' }, { 76,11,'#' });
				b.replace();
			}
			system("CLS");
			drawMenu();
			Mark = 10;
			drawMarker(Mark);

		}
		if (Mark == 12)
		{
			whichPlay = 1;
			system("CLS");
			gotoxy(10, 10);
			cout << "Set the level of the Computer player: \n";
			playerRightPC.setTheLevel(whichLevel((heightOfMark)));
			system("CLS");
			clearDeadAreas(leftDeadArea, rightDeadArea);
			playerLeftUS.set({ 4, 12, '#' }, { 4,10,'#' });
			playerRightPC.set({ 76,13,'#' }, { 76,11,'#' });
			kb.registerKbListener(&playerLeftUS);
			b.replace();
			countDownToBall = 0;
			countDownToBomb = 0;
			playerLeftUS.enableTrigger();
			playerRightUS.enableTrigger();
			GameOn = start(rightDeadArea, leftDeadArea, playerLeftUS, playerRightPC, b, kb);
			if (!GameOn)
			{
				clearDeadAreas(leftDeadArea, rightDeadArea);
				playerLeftUS.set({ 4, 12, '#' }, { 4,10,'#' });
				playerRightPC.set({ 76,13,'#' }, { 76,11,'#' });
				b.replace();
			}
			system("CLS");
			drawMenu();
			Mark = 10;
			drawMarker(Mark);

		}
		if (Mark == 14)
		{
			whichPlay = 2;
			system("CLS");
			gotoxy(10, 10);
			cout << "Set the level of the LEFT Computer player: \n";
			playerLeftPC.setTheLevel(whichLevel((heightOfMark)));
			system("CLS");
			gotoxy(10, 10);
			cout << "Set the level of the RIGHT Computer player: \n";
			playerRightPC.setTheLevel(whichLevel((heightOfMark)));
			system("CLS");
			clearDeadAreas(leftDeadArea, rightDeadArea);
			playerLeftPC.set({ 4, 12, '#' }, { 4,10,'#' });
			playerRightPC.set({ 76,13,'#' }, { 76,11,'#' });
			b.replace();
			countDownToBall = 0;
			countDownToBomb = 0;
			playerLeftUS.enableTrigger();
			playerRightUS.enableTrigger();
			GameOn = start(rightDeadArea, leftDeadArea, playerLeftPC, playerRightPC, b, kb);
			if (!GameOn)
			{
				clearDeadAreas(leftDeadArea, rightDeadArea);
				playerLeftPC.set({ 4,12,'#' }, { 4,10,'#' });
				playerRightPC.set({ 76,13,'#' }, { 76,11,'#' });
				b.replace();
			}
			system("CLS");
			drawMenu();
			Mark = 10;
			drawMarker(Mark);

		}
		if (Mark == 16)
		{

			system("CLS");
			if (GameOn)
			{
				if (whichPlay == 0)
					GameOn = start(rightDeadArea, leftDeadArea, playerLeftUS, playerRightUS, b, kb);
				if (whichPlay == 1)
					GameOn = start(rightDeadArea, leftDeadArea, playerLeftUS, playerRightPC, b, kb);
				if (whichPlay == 2)
					GameOn = start(rightDeadArea, leftDeadArea, playerLeftPC, playerRightPC, b, kb);
			}
			else
			{
				gotoxy(40, 12);
				cout << "NO ACTIVE GAME";
				Sleep(1000);
			}

			if (!GameOn)
			{
				clearDeadAreas(leftDeadArea, rightDeadArea);
				playerLeftUS.set({ 4,12,'#' }, { 4,10,'#' });
				playerRightUS.set({ 76,13,'#' }, { 76,11,'#' });
				playerLeftPC.set({ 4,12,'#' }, { 4,10,'#' });
				playerRightPC.set({ 76,13,'#' }, { 76,11,'#' });

				b.replace();
			}
			system("CLS");
			drawMenu();
			Mark = 10;
			drawMarker(Mark);
		}
		if (Mark == 18)
		{
			system("CLS");
			viewInstructions();
			system("CLS");
			drawMenu();
			Mark = 10;
			drawMarker(Mark);
		}
		if (Mark == 20)
		{
			system("CLS");
			return 0;
		}
	}


}

void drawMenu()
{

	setColor(COLOR::TEAL_TEXT);

	cout << R"(
__/\\\\\\\\\\\\\\\_______/\\\\\_______/\\\\\_____/\\\_____/\\\\\\\\\\\\____________/\\\\\\\\\\\__/\\\\\\\\\\\_        
 _\///////\\\/////______/\\\///\\\____\/\\\\\\___\/\\\___/\\\//////////____________\/////\\\///__\/////\\\///__       
  _______\/\\\_________/\\\/__\///\\\__\/\\\/\\\__\/\\\__/\\\___________________________\/\\\_________\/\\\_____      
   _______\/\\\________/\\\______\//\\\_\/\\\//\\\_\/\\\_\/\\\____/\\\\\\\_______________\/\\\_________\/\\\_____     
    _______\/\\\_______\/\\\_______\/\\\_\/\\\\//\\\\/\\\_\/\\\___\/////\\\_______________\/\\\_________\/\\\_____    
     _______\/\\\_______\//\\\______/\\\__\/\\\_\//\\\/\\\_\/\\\_______\/\\\_______________\/\\\_________\/\\\_____   
      _______\/\\\________\///\\\__/\\\____\/\\\__\//\\\\\\_\/\\\_______\/\\\_______________\/\\\_________\/\\\_____  
       _______\/\\\__________\///\\\\\/_____\/\\\___\//\\\\\_\//\\\\\\\\\\\\/_____________/\\\\\\\\\\\__/\\\\\\\\\\\_ 
        _______\///_____________\/////_______\///_____\/////___\////////////______________\///////////__\///////////__


                                               
)";



		

	setColor(COLOR::RED_TEXT);
	gotoxy(10, 1);

	setColor(COLOR::WHITE_TEXT);
	gotoxy(10, 10);
	std::cout << "Start a new game - Human vs Human";

	gotoxy(10, 12);
	std::cout << "Start a new game - Human vs Computer";

	gotoxy(10, 14);
	std::cout << "Start a new game - Computer vs Computer";

	gotoxy(10, 16);
	std::cout << "return to the Game";

	gotoxy(10, 18);
	std::cout << "rules";

	gotoxy(10, 20);
	std::cout << "exit";

	gotoxy(20, 30);
	std::cout << "Enter C to choose & q(up) a(down) ";

}

void drawMarker(int y)
{
	setColor(COLOR::RED_TEXT);
	gotoxy(6, y);
	std::cout << "X";
	setColor(COLOR::RED_TEXT);
}

void eraseMarker(int y)
{
	gotoxy(6, y);
	std::cout << "  ";
}

void down(int& y)
{
	if (y < 20)
	{

		eraseMarker(y);
		y = y + 2;
		drawMarker(y);
	}

}

void up(int& y)
{
	if (y > 10)
	{

		eraseMarker(y);
		y = y - 2;
		drawMarker(y);
	}

}

void viewInstructions()
{
	char ch;
	gotoxy(15, 5);
	{

		cout << "KEYS:\n";
		cout << "LEFT PLAYER: UP=Q, DOWN=A, TRIGGER BOMB=S\n";
		cout << "RIGHT PLAYER: UP=P,DOWN=L, TRIGGER BOMB=K\n";
		cout << "ESC= PAUSE GAME AND VIEW MENU\n\n\n";
		cout << "PRESS C TO RETURN TO MAIN MENU";

	}

	ch = _getch();
	while (ch != 'C' && ch != 'c')
		ch = _getch();

}

void setcursor(bool visible, DWORD size)
{
	if (size == 0)
	{
		size = 20;
	}
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

int whichLevel(int y)
{
	gotoxy(6, y);
	std::cout << "X";
	gotoxy(10, 15);
	cout << "BEST";
	gotoxy(10, 20);
	cout << "GOOD";
	gotoxy(10, 25);
	cout << "NOVICE";

	char ch = _getch();
	while (ch != 'C' && ch != 'c')
	{
		if (ch == 'a' || ch == 'A')
		{
			if (y < 25)
			{

				eraseMarker(y);
				y = y + 5;
				drawMarker(y);
			}
		}
		if (ch == 'q' || ch == 'Q')
		{
			if (y > 15)
			{

				eraseMarker(y);
				y = y - 5;
				drawMarker(y);
			}
		}
		ch = _getch();
	}
	if (y == 15)
		return BEST;
	if (y == 20)
		return GOOD;
	if (y == 25)
		return NOVICE;
	return -1;
}



