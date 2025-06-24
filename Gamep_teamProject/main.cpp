#include "TitleScene.h"
#include "GameLogic.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	char gameMap[MAP_HEIGHT][MAP_WIDTH] = {};
	Scene curScene = Scene::TITLE;
	PLAYER player;
	int startTime = 60 + time(0);
	int survivedTime = 0;
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
			if (player.isGameOver) {
				memset(gameMap, 0, sizeof(gameMap));
				vecDDONG.clear();
				Init(gameMap, &player);
				startTime = 60 + time(0);
				player.isGameOver = false;
			}
			if (!player.isGameOver) {
				GameScene(curScene, gameMap, &player, vecDDONG, startTime);
			}
			break;
		case Scene::INFO:
			InfoScene(curScene, &player);
			break;
		case Scene::GAMEOVER:
			survivedTime = 60 - (startTime - time(0));
			if (survivedTime < 0) survivedTime = 0;
			GameOverScene(curScene, &player, startTime, survivedTime);
			break;
		case Scene::CLEAR:
			ClearScene(curScene, &player);
		}
	}
	system("cls");
}