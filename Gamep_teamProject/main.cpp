#include "TitleScene.h"
#include "GameLogic.h"

int main()
{
	Scene curScene = Scene::TITLE;
	while (curScene != Scene::QUIT)
	{
		switch (curScene)
		{
		case Scene::TITLE:
			TitleScene(curScene);
			break;
		case Scene::GAME:
			GameScene(curScene);
		}
	}
}