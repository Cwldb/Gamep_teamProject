#include "TitleScene.h"
#include "GameLogic.h"
#include "Mci.h"
#include <iostream>
#include <mutex>

std::once_flag flag;
using std::cout;
using std::endl;

int main()
{
	char gameMap[MAP_HEIGHT][MAP_WIDTH] = {};
	Scene curScene = Scene::TITLE;
	PLAYER player;
	vector<DDONG> vecDDONG;

	if (!InitAllSounds())
	{
		cout << "사운드 초기화 실패!";
		//return;
	}

	Init(gameMap, &player);

	while (curScene != Scene::QUIT)
	{
		switch (curScene)
		{
		case Scene::TITLE:
			TitleScene(curScene);

			if (curScene == Scene::GAME)
			{
				player.startTime = time(0);
			}
			break;

		case Scene::GAME:
			if (player.isGameOver)
			{
				memset(gameMap, 0, sizeof(gameMap));
				vecDDONG.clear();
				Init(gameMap, &player);
				player.startTime = time(0);
				player.isGameOver = false;
			}

			if (!player.isGameOver)
			{
				std::call_once(flag, []() {
					system("cls");
					});

				GameScene(curScene, gameMap, &player, vecDDONG, player.startTime);
			}
			break;

		case Scene::INFO:
			InfoScene(curScene, &player);
			break;

		case Scene::GAMEOVER:
		{
			int survivedTime = time(0) - player.startTime;
			if (survivedTime < 0) survivedTime = 0;

			GameOverScene(curScene, &player, player.startTime, survivedTime);
			break;
		}
		case Scene::CLEAR:
			ClearScene(gameMap, curScene, &player);
			std::call_once(flag, []() {
				system("cls");
				});
			break;
		}
	}
	system("cls");
	ReleaseAllSounds();
}
