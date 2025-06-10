#include "GameLogic.h"
#include "TitleScene.h"
#include "Console.h"
#include "KeyController.h"

void Init()
{
	SetConsoleFont(L"NSimsun", { 20,20 }, FW_BOLD);
	SetConsoleSettings(800, 600, false, L"Catch Of Crush");
	SetCursorVisual(true, 50);
}

void Update()
{
}

void Render()
{
}

void GameScene(Scene& _eCurScene)
{
	_eCurScene = Scene::GAME;
	cout << "°ÔÀÓ¾À";
}

void InfoScene(Scene& _eCurScene)
{
	Key eKey = KeyController();
	RenderInfo();
	if (eKey == Key::ESC)
	{
		_eCurScene = Scene::TITLE;
		system("cls");
	}
}

void RenderInfo()
{
	cout << "Á¤º¸¾À";
}



