#include "TitleScene.h"
#include<io.h>
#include<fcntl.h>
#include "Console.h"
#include "KeyController.h"

void TitleScene(Scene& _eCurScene)
{
	TitleSceneUpdate(_eCurScene);
	if (_eCurScene != Scene::TITLE)
		return;
	TitleSceneRender();
	Sleep(20);
}

void TitleSceneUpdate(Scene& _eCurScene)
{
	Menu eMenu = GetCurMenu();
	switch (eMenu)
	{
	case Menu::START:
		EnterAnimation();
		_eCurScene = Scene::GAME;
		system("cls");
		break;
	case Menu::INFO:
		_eCurScene = Scene::INFO;
		system("cls");
		break;
	case Menu::QUIT:
		_eCurScene = Scene::QUIT;
		break;
	}
}

Menu GetCurMenu()
{
	COORD resolution = GetConsoleResolution();
	static int x = resolution.X / 2 - 6;
	static int originx = x;
	int y = resolution.Y / 3 * 2 + 4;
	Key eKey = KeyController();

	switch (eKey)
	{
	case Key::LEFT:
		if (x > originx - 25)
		{
			Gotoxy(x - 2, y - 1);
			cout << " ";
			Gotoxy(x - 2, y);
			cout << "             ";
			x -= 25;
			Gotoxy(x, y);
			int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
			Gotoxy(x - 2, y - 1);
			wcout << L"☞";
			Gotoxy(x - 2, y);
			wcout << L"⚊⚊⚊⚊⚊⚊⚊⚊⚊⚊⚊⚊⚊";
			int wcoutmode = _setmode(_fileno(stdout), coutmode);
		}
		break;
	case Key::RIGHT:
		if (x < originx + 25)
		{
			Gotoxy(x - 2, y - 1);
			cout << " ";
			Gotoxy(x - 2, y);
			cout << "              ";
			x += 25;
			int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
			Gotoxy(x - 2, y - 1);
			wcout << L"☞";
;			Gotoxy(x - 2, y);
			wcout << L"⚊⚊⚊⚊⚊⚊⚊⚊⚊⚊⚊⚊⚊";
			int wcoutmode = _setmode(_fileno(stdout), coutmode);
		}
		break;

	case Key::SPACE:
		if (x == originx - 25) return Menu::START;
		else if (x == originx) return Menu::INFO;
		else if (x == originx + 25) return Menu::QUIT;
		break;
	}
	return Menu::FAIL;
}

void EnterAnimation()
{
	COORD resolution = GetConsoleResolution();
	int delaytime = 8;
	int flashCnt = 5;
	FlashAnimation(resolution, flashCnt, delaytime);
	CrossAnimation(resolution, delaytime);
	//SetColor(COLOR::WHITE, COLOR::MINT);
	system("cls");
}

void FlashAnimation(COORD _resolution, int _cnt, int _delaytime)
{
	for (int c = 0; c < _cnt; ++c)
	{
		SetColor(COLOR::BLACK, COLOR::WHITE);
		system("cls");
		Sleep(_delaytime);
		SetColor();
		system("cls");
	}
}

void CrossAnimation(COORD _resolution, int _delaytime)
{
	SetColor(COLOR::BLACK, COLOR::WHITE);
	for (int i = 0; i < _resolution.X / 2; ++i)
	{
		for (int j = 0; j < _resolution.Y; j += 2)
		{
			Gotoxy(i * 2, j);
			cout << "  ";
		}
		for (int j = 1; j < _resolution.Y; j += 2)
		{
			Gotoxy(_resolution.X - 2 - i * 2, j);
			cout << "  ";
		}
		Sleep(_delaytime);
	}
	SetColor();
}


void TitleSceneRender()
{
	COORD resolution = GetConsoleResolution();
	int y = resolution.Y / 3;
	Gotoxy(0, y);
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"	 ██████╗ █████╗ ████████╗ ██████╗██╗  ██╗     ██████╗ ██████╗      ██████╗██████╗  █████╗ ███████╗██╗  ██╗ " << endl;
	wcout << L"	██╔════╝██╔══██╗╚══██╔══╝██╔════╝██║  ██║    ██╔═══██╗██╔══██╗    ██╔════╝██╔══██╗██╔══██╗██╔════╝██║  ██║ " << endl;
	wcout << L"	██║     ███████║   ██║   ██║     ███████║    ██║   ██║██████╔╝    ██║     ██████╔╝███████║███████╗███████║ " << endl;
	wcout << L"	██║     ██╔══██║   ██║   ██║     ██╔══██║    ██║   ██║██╔══██╗    ██║     ██╔══██╗██╔══██║╚════██║██╔══██║ " << endl;
	wcout << L"	╚██████╗██║  ██║   ██║   ╚██████╗██║  ██║    ╚██████╔╝██║  ██║    ╚██████╗██║  ██║██║  ██║███████║██║  ██║ " << endl;
	wcout << L"	 ╚═════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝╚═╝  ╚═╝     ╚═════╝ ╚═╝  ╚═╝     ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ " << endl;
	int wcoutmode = _setmode(_fileno(stdout), coutmode);
	int x = resolution.X / 2 - 5;
	y = resolution.Y / 3 * 2 + 3;
	Gotoxy(x - 25, y);
	cout << "게임시작";
	Gotoxy(x, y);
	cout << "게임정보";
	Gotoxy(x + 25, y);
	cout << "게임종료";
}
