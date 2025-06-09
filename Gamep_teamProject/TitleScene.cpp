#include "TitleScene.h"
#include<io.h>
#include<fcntl.h>
#include "Console.h"

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
	// 2 
	switch (eKey)
	{
	case Key::UP:
		if (y > originy)
		{
			Gotoxy(x - 2, y);
			cout << " ";
			Gotoxy(x - 2, --y);
			cout << ">";
			Sleep(100);
		}
		break;
	case Key::DOWN:
		if (y < originy + 2)
		{
			Gotoxy(x - 2, y);
			cout << " ";
			Gotoxy(x - 2, ++y);
			cout << ">";
			Sleep(100);
			// 1 
		}
		break;
	case Key::SPACE:
		if (originy == y) return Menu::START;
		else if (originy + 1 == y) return Menu::INFO;
		else  if (originy + 2 == y) return Menu::QUIT;
		break;
	}
	return Menu::FAIL;
}

void TitleSceneRender()
{
}
