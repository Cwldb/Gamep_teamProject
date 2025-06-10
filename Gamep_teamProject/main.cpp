#include "TitleScene.h"
#include "GameLogic.h"

int main()
{
	char gameMap[MAP_HEIGHT][MAP_WIDTH] = {};
	Scene curScene = Scene::TITLE;
	PLAYER player;
	Init(gameMap, &player);
	while (curScene != Scene::QUIT)
	{
		switch (curScene)
		{
		case Scene::TITLE:
			TitleScene(curScene);
			break;
		case Scene::GAME:
			GameScene(curScene, gameMap, &player);
			break;
		case Scene::INFO:
			InfoScene(curScene);
			break;
		}
	}
}