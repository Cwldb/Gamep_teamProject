#include "GameLogic.h"
#include "TitleScene.h"
#include "Console.h"
#include "KeyController.h"

void Init(char _gameMap[MAP_HEIGHT][MAP_WIDTH])
{
	//SetConsoleFont(L"NSimsun", { 20,20 }, FW_BOLD);
	//SetConsoleSettings(800, 600, false, L"Catch Of Crush");
	SetCursorVisual(true, 50);
	LoadStage(_gameMap);
}

void Update()
{
}



void Render(char _gameMap[MAP_HEIGHT][MAP_WIDTH])
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (_gameMap[i][j] == (char)Tile::BACK)
				cout << "  ";
			else if (_gameMap[i][j] == (char)Tile::WALL)
				cout << "¡á";
			else if (_gameMap[i][j] == (char)Tile::START)
				cout << "¡Ù";
			else if (_gameMap[i][j] == (char)Tile::SPAWNDDONG)
				cout << "¢Í";
		}
		cout << endl;
	}
}

void LoadStage(char _gameMap[MAP_HEIGHT][MAP_WIDTH])
{
	strcpy_s(_gameMap[0],"133333333333333333331");
	strcpy_s(_gameMap[1],"100000000000000000001");
	strcpy_s(_gameMap[2],"100000000000000000001");
	strcpy_s(_gameMap[3],"100000000000000000001");
	strcpy_s(_gameMap[4],"100000000000000000001");
	strcpy_s(_gameMap[5],"100000000000000000001");
	strcpy_s(_gameMap[6],"100000000000000000001");
	strcpy_s(_gameMap[7],"100000000000000000001");
	strcpy_s(_gameMap[8],"100000000000000000001");
	strcpy_s(_gameMap[9],"100000000000000000001");
	strcpy_s(_gameMap[10],"100000000000000000001");
	strcpy_s(_gameMap[11],"100000000000000000001");
	strcpy_s(_gameMap[12],"100000000000000000001");
	strcpy_s(_gameMap[13],"100000000000000000001");
	strcpy_s(_gameMap[14],"100000000000000000001");
	strcpy_s(_gameMap[15],"100000000000000000001");
	strcpy_s(_gameMap[16],"100000000000000000001");
	strcpy_s(_gameMap[17],"100000000000000000001");
	strcpy_s(_gameMap[18],"100000000000000000001");
	strcpy_s(_gameMap[19],"100000000020000000001");
	strcpy_s(_gameMap[20],"100000000000000000001");
	strcpy_s(_gameMap[21],"100000000000000000001");
	strcpy_s(_gameMap[22],"111111111111111111111");
}

void GameScene(Scene& _eCurScene, char _gameMap[MAP_HEIGHT][MAP_WIDTH])
{
	_eCurScene = Scene::GAME;
	Gotoxy(0, 0);
	Render(_gameMap);
	FrameSync(30);
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



