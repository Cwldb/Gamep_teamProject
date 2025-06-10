#include "TitleScene.h"
#include "GameLogic.h"

int main()
{
	char gameMap[MAP_HEIGHT][MAP_WIDTH] = {};
	Scene curScene = Scene::TITLE;
	Init(gameMap);

	while (curScene != Scene::QUIT)
	{
		switch (curScene)
		{
		case Scene::TITLE:
			TitleScene(curScene);
			break;
		case Scene::GAME:
			GameScene(curScene, gameMap);
			break;
		case Scene::INFO:
			InfoScene(curScene);
			break;
		}
	}
}