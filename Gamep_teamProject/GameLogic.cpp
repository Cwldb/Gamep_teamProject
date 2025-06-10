#include "GameLogic.h"
#include "TitleScene.h"
#include "Console.h"

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

