#include "GameLogic.h"
#include "TitleScene.h"
#include "Console.h"
#include "KeyController.h"
#include <algorithm>

void Init(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer)
{
	//SetConsoleFont(L"NSimsun", { 20,20 }, FW_BOLD);
	//SetConsoleSettings(800, 600, false, L"Catch Of Crush");
	SetCursorVisual(true, 50);
	LoadStage(_gameMap);
	PlayerInit(_gameMap, _pPlayer);
}

void PlayerInit(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer)
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			// 맵 데이터에 의해 플레이어 세팅
			if (_gameMap[i][j] == (char)Tile::START)
				_pPlayer->position.tStartPos = { j, i };

		}
	}
	_pPlayer->position.tPos = _pPlayer->position.tStartPos;
	_pPlayer->state = { 0 };
}

void HandleInput(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer)
{
	_pPlayer->position.tNewPos = _pPlayer->position.tPos;
	Key eKey = KeyController();

	switch (eKey)
	{
	case Key::LEFT:
		--_pPlayer->position.tNewPos.x;
		break;
	case Key::RIGHT:
		++_pPlayer->position.tNewPos.x;
		break;
	case Key::SPACE:
		break;
	case Key::ESC:
		break;
	case Key::FAIL:
		break;
	default:
		break;
	}

	_pPlayer->position.tNewPos.x = std::clamp(_pPlayer->position.tNewPos.x, 0, MAP_WIDTH - 2);
	_pPlayer->position.tNewPos.y = std::clamp(_pPlayer->position.tNewPos.y, 0, MAP_HEIGHT - 1);

	// 최종 반영
	if (_gameMap[_pPlayer->position.tNewPos.y][_pPlayer->position.tNewPos.x] != (char)Tile::WALL)
		_pPlayer->position.tPos = _pPlayer->position.tNewPos;
}

void Update(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer)
{
	HandleInput(_gameMap, _pPlayer);
}


void Render(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer)
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (_pPlayer->position.tPos.x == j && _pPlayer->position.tPos.y == i)
				cout << "§";
			else
			{
				if (_gameMap[i][j] == (char)Tile::BACK)
					cout << "  ";
				else if (_gameMap[i][j] == (char)Tile::WALL)
					cout << "■";
				else if (_gameMap[i][j] == (char)Tile::START)
					cout << "  ";
				else if (_gameMap[i][j] == (char)Tile::SPAWNDDONG)
					cout << "♨";
			}
		}
		cout << endl;
	}
}

void LoadStage(char _gameMap[MAP_HEIGHT][MAP_WIDTH])
{
	strcpy_s(_gameMap[0], "133333333333333333331");
	strcpy_s(_gameMap[1], "100000000000000000001");
	strcpy_s(_gameMap[2], "100000000000000000001");
	strcpy_s(_gameMap[3], "100000000000000000001");
	strcpy_s(_gameMap[4], "100000000000000000001");
	strcpy_s(_gameMap[5], "100000000000000000001");
	strcpy_s(_gameMap[6], "100000000000000000001");
	strcpy_s(_gameMap[7], "100000000000000000001");
	strcpy_s(_gameMap[8], "100000000000000000001");
	strcpy_s(_gameMap[9], "100000000000000000001");
	strcpy_s(_gameMap[10], "100000000000000000001");
	strcpy_s(_gameMap[11], "100000000000000000001");
	strcpy_s(_gameMap[12], "100000000000000000001");
	strcpy_s(_gameMap[13], "100000000000000000001");
	strcpy_s(_gameMap[14], "100000000000000000001");
	strcpy_s(_gameMap[15], "100000000000000000001");
	strcpy_s(_gameMap[16], "100000000000000000001");
	strcpy_s(_gameMap[17], "100000000000000000001");
	strcpy_s(_gameMap[18], "100000000000000000001");
	strcpy_s(_gameMap[19], "100000000020000000001");
	strcpy_s(_gameMap[20], "100000000000000000001");
	strcpy_s(_gameMap[21], "100000000000000000001");
	strcpy_s(_gameMap[22], "111111111111111111111");
}

void GameScene(Scene& _eCurScene, char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer)
{
	_eCurScene = Scene::GAME;
	Update(_gameMap, _pPlayer);
	Gotoxy(0, 0);
	Render(_gameMap, _pPlayer);
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
	cout << "정보씬";
}
