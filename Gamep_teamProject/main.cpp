#include "TitleScene.h"
#include "GameLogic.h"
#include <iostream>

int main()
{
	char gameMap[MAP_HEIGHT][MAP_WIDTH] = {};
	Scene curScene = Scene::TITLE;
	PLAYER player;
	int startTime = 60 + time(0);
	vector<DDONG> vecDDONG;
	Init(gameMap, &player);
	while (curScene != Scene::QUIT)
	{
		switch (curScene)
		{
		case Scene::TITLE:
			TitleScene(curScene);
			break;
		case Scene::GAME:
			GameScene(curScene, gameMap, &player, vecDDONG, startTime);
			break;
		case Scene::INFO:
			InfoScene(curScene);
			break;
		}
	}
}