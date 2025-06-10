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
	Sleep(60);
}

void TitleSceneUpdate(Scene& _eCurScene)
{
	Menu eMenu = GetCurMenu();
	switch (eMenu)
	{
	case Menu::START:
		_eCurScene = Scene::GAME;
		break;
	case Menu::INFO:
		_eCurScene = Scene::INFO;
		break;
	case Menu::QUIT:
		_eCurScene = Scene::QUIT;
		break;
	}
}

Menu GetCurMenu()
{
	COORD resolution = GetConsoleResolution();
	int x = resolution.X / 3;
	static int y = resolution.Y / 3 * 2;
	static int originy = y;
	Key eKey = KeyController();
	switch (eKey)
	{
	case Key::SPACE:
		return Menu::START;
		break;
	}
	return Menu::FAIL;
}

void TitleSceneRender()
{
	COORD resolution = GetConsoleResolution();
	int y = resolution.Y / 3;
	Gotoxy(0, y);
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"	 ██████╗ █████╗ ████████╗ ██████╗██╗  ██╗     ██████╗ ██████╗      ██████╗██████╗  █████╗ ███████╗██╗  ██╗" << endl;
	wcout << L"	██╔════╝██╔══██╗╚══██╔══╝██╔════╝██║  ██║    ██╔═══██╗██╔══██╗    ██╔════╝██╔══██╗██╔══██╗██╔════╝██║  ██║" << endl;
	wcout << L"	██║     ███████║   ██║   ██║     ███████║    ██║   ██║██████╔╝    ██║     ██████╔╝███████║███████╗███████║" << endl;
	wcout << L"	██║     ██╔══██║   ██║   ██║     ██╔══██║    ██║   ██║██╔══██╗    ██║     ██╔══██╗██╔══██║╚════██║██╔══██║" << endl;
	wcout << L"	╚██████╗██║  ██║   ██║   ╚██████╗██║  ██║    ╚██████╔╝██║  ██║    ╚██████╗██║  ██║██║  ██║███████║██║  ██║" << endl;
	wcout << L"	 ╚═════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝╚═╝  ╚═╝     ╚═════╝ ╚═╝  ╚═╝     ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ " << endl;
	int wcoutmode = _setmode(_fileno(stdout), coutmode);
	int x = resolution.X / 3;
	y = resolution.Y / 3 * 2;
	Gotoxy(x + 15, y);
	cout << "게임 시작";
	Gotoxy(x + 15, y + 1);
	cout << "게임 정보";
	Gotoxy(x + 15, y + 2);
	cout << "게임 종료";
}
