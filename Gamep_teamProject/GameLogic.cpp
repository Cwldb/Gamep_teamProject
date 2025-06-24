#include "GameLogic.h"
#include "TitleScene.h"
#include "Console.h"
#include "KeyController.h"
#include <algorithm>
#include <random>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>

int g_ddongFrame = 0;

void Init(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer)
{
	//SetConsoleFont(L"NSimsun", { 20,20 }, FW_BOLD);
	SetConsoleSettings(1000, 600, false, L"Catch Of Crush");
	DisableConsoleResize();
	SetCursorVisual(false, 50);
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
	_pPlayer->survivedTimeOnGameOver = -1;
	_pPlayer->startTime = time(0);
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

void Update(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, vector<DDONG> vecDDONG, Scene& _eCurScene)
{
	HandleInput(_gameMap, _pPlayer);
	SpawnDDong(_gameMap, vecDDONG, _pPlayer, _eCurScene);
}


void Render(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, int _startTime, Scene& _eCurScene)
{

	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (_pPlayer->position.tPos.x == j && _pPlayer->position.tPos.y == i)
			{
				SetColor(COLOR::LIGHTGREEN, COLOR::BLACK);
				cout << "§";
				SetColor();
			}

			else
			{
				if (_gameMap[i][j] == (char)Tile::BACK)
				{
					cout << "  ";
				}
				else if (_gameMap[i][j] == (char)Tile::WALL)
				{
					SetColor(COLOR::LIGHTGRAY, COLOR::BLACK);
					cout << "■";
					SetColor();
				}
				else if (_gameMap[i][j] == (char)Tile::START)
					cout << "  ";
				else if (_gameMap[i][j] == (char)Tile::DDONG) 
				{
					SetColor(COLOR::BROWN, COLOR::BLACK);
					cout << "♨";
					SetColor();
				}
				else if (_gameMap[i][j] == (char)Tile::SPAWNDDONG)
				{
					SetColor(COLOR::RED, COLOR::BLACK);
					cout << "※";
					SetColor();
				}

				else if (_gameMap[i][j] == (char)Tile::FLOOR)
				{
					SetColor(COLOR::LIGHTGRAY, COLOR::BLACK);
					cout << "■";
					SetColor();
				}
				else if (_gameMap[i][j] == (char)Tile::COIN)
				{
					SetColor(COLOR::YELLOW, COLOR::BLACK);
					cout << "㉧";
					SetColor();
				}
			}
		}
		cout << endl;
	}
	RenderUI(_pPlayer, _startTime, _eCurScene);

	if (_eCurScene == Scene::GAMEOVER)
	{
		system("cls");
		return;
	}
}

void RenderUI(PPLAYER _pPlayer, int _startTime, Scene& _eCurScene)
{
	COORD consoleSize = GetConsoleResolution();
	int x = consoleSize.X / 2;
	int y = 5;
	int timer = _startTime - time(0);
	if (timer == 0)
	{
		system("cls");
		_eCurScene = Scene::CLEAR;
	}

	Gotoxy(x, y++);
	cout << "--------------------";
	Gotoxy(x, y++);
	Gotoxy(x, y++);
	cout << "  현재 골드 : " << _pPlayer->state.coinCnt;
	Gotoxy(x, y++);
	cout << "  남은 시간 : " << timer << "초";
	Gotoxy(x, y++);
	Gotoxy(x, y++);
	cout << "--------------------";
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
	strcpy_s(_gameMap[19], "100000000000000000001");
	strcpy_s(_gameMap[20], "100000000000000000001");
	strcpy_s(_gameMap[21], "100000000000000000001");
	strcpy_s(_gameMap[22], "100000000020000000001");
	strcpy_s(_gameMap[23], "155555555555555555551");
}

void GameScene(Scene& _eCurScene, char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, vector<DDONG> vecDDONG, int _startTime)
{
	_eCurScene = Scene::GAME;
	Update(_gameMap, _pPlayer, vecDDONG, _eCurScene);
	Gotoxy(0, 0);
	Render(_gameMap, _pPlayer, _startTime, _eCurScene);
	FrameSync(30);
}

void ClearScene(Scene& _eCurScene, PPLAYER _pPlayer)
{
	_eCurScene = Scene::CLEAR;
	COORD resolution = GetConsoleResolution();
	int y = resolution.Y / 3;
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
	Gotoxy(0, y);
		wcout << L"███████╗████████╗ █████╗  ██████╗ ███████╗     ██████╗██╗     ███████╗ █████╗ ██████╗ " << endl;
		wcout << L"██╔════╝╚══██╔══╝██╔══██╗██╔════╝ ██╔════╝    ██╔════╝██║     ██╔════╝██╔══██╗██╔══██╗" << endl;
		wcout << L"███████╗   ██║   ███████║██║  ███╗█████╗      ██║     ██║     █████╗  ███████║██████╔╝" << endl;
		wcout << L"╚════██║   ██║   ██╔══██║██║   ██║██╔══╝      ██║     ██║     ██╔══╝  ██╔══██║██╔══██╗" << endl;
		wcout << L"███████║   ██║   ██║  ██║╚██████╔╝███████╗    ╚██████╗███████╗███████╗██║  ██║██║  ██║" << endl;
		wcout << L"╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚══════╝     ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝" << endl;
	int wcoutmode = _setmode(_fileno(stdout), coutmode);
}

void ClearBottomRow(char _gameMap[MAP_HEIGHT][MAP_WIDTH])
{
	for (int j = 0; j < MAP_WIDTH; ++j)
		if (_gameMap[MAP_HEIGHT - 2][j] == (char)Tile::DDONG || _gameMap[MAP_HEIGHT - 2][j] == (char)Tile::COIN)
			_gameMap[MAP_HEIGHT - 2][j] = (char)Tile::BACK;
}

void MoveTileDown(char _gameMap[MAP_HEIGHT][MAP_WIDTH], char tileType, char newType)
{
	for (int i = MAP_HEIGHT - 2; i >= 0; --i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (_gameMap[i][j] == tileType)
			{
				char& below = _gameMap[i + 1][j];

				if (below == (char)Tile::BACK || below == (char)Tile::START)
				{
					below = tileType;
					_gameMap[i][j] = (char)Tile::BACK;
				}
				else if (newType && below == (char)Tile::FLOOR)
				{
					below = newType;
					_gameMap[i][j] = (char)Tile::BACK;
				}
			}
		}
	}
}

void SpawnTile(char _gameMap[MAP_HEIGHT][MAP_WIDTH], char tileType, int maxSpawn)
{
	std::vector<int> spawnCols;
	for (int j = 0; j < MAP_WIDTH; ++j)
	{
		for (int i = 0; i < MAP_HEIGHT - 1; ++i)
		{
			if (_gameMap[i][j] == (char)Tile::SPAWNDDONG &&
				(_gameMap[i + 1][j] == (char)Tile::BACK || _gameMap[i + 1][j] == (char)Tile::START))
				spawnCols.push_back(j);
		}
	}

	if (!spawnCols.empty())
	{
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::shuffle(spawnCols.begin(), spawnCols.end(), gen);
		int count = std::min<int>(maxSpawn, spawnCols.size());

		for (int n = 0; n < count; ++n)
		{
			int x = spawnCols[n];
			for (int i = 0; i < MAP_HEIGHT - 1; ++i)
			{
				if (_gameMap[i][x] == (char)Tile::SPAWNDDONG &&
					(_gameMap[i + 1][x] == (char)Tile::BACK || _gameMap[i + 1][x] == (char)Tile::START)) {
					_gameMap[i + 1][x] = tileType;
					break;
				}
			}
		}
	}
}

void SpawnDDong(char _gameMap[MAP_HEIGHT][MAP_WIDTH], vector<DDONG>& vecDDONG, PPLAYER _pPlayer, Scene& _eCurScene)
{
	auto& pos = _pPlayer->position.tPos;
	char& curTile = _gameMap[pos.y][pos.x];
	if (curTile == (char)Tile::DDONG)
	{
		system("cls");
		_pPlayer->isGameOver = true;
		_eCurScene = Scene::GAMEOVER;

		if (_pPlayer->survivedTimeOnGameOver == -1)
			_pPlayer->survivedTimeOnGameOver = time(0) - _pPlayer->startTime;

		return;
	}
	if (curTile == (char)Tile::COIN)
	{
		_pPlayer->state.coinCnt++;
		curTile = (char)Tile::BACK;
	}

	ClearBottomRow(_gameMap);

	g_ddongFrame++;
	if (g_ddongFrame >= DDONG_DROP_INTERVAL)
	{
		g_ddongFrame = 0;

		MoveTileDown(_gameMap, (char)Tile::DDONG, (char)Tile::FLOOR);
		MoveTileDown(_gameMap, (char)Tile::DDONG);
		MoveTileDown(_gameMap, (char)Tile::COIN, (char)Tile::FLOOR);

		int dropCount = rand() % 3;
		SpawnTile(_gameMap, (char)Tile::DDONG, dropCount);
	}

	static int coinFrame = 0;
	if (++coinFrame >= 100)
	{
		coinFrame = 0;
		SpawnTile(_gameMap, (char)Tile::COIN, 1);
	}
}

void InfoScene(Scene& _eCurScene, PPLAYER _pPlayer)
{
	Key eKey = KeyController();
	RenderInfo(_pPlayer);
	if (eKey == Key::ESC)
	{
		_eCurScene = Scene::TITLE;
		system("cls");
	}
}

void RenderInfo(PPLAYER _pPlayer)
{
	Gotoxy(47, 5);
	cout << "조작법";
	Gotoxy(47, 8);
	cout << "양쪽 화살표로 좌우로 움직이기";
	Gotoxy(47, 10);
	cout << "플레이어와 장애물이 닿으면 게임 OVER";
	Gotoxy(47, 12);
	cout << "플레이어와 코인이 닿으면 점수 UP";
	Gotoxy(47, 14);
	cout << "똥이랑 코인 닿으면 사라집니다!!!";
	Gotoxy(47, 17);
	cout << "ESC를 눌러서 타이틀로 돌아가기";
}

void GameOverScene(Scene& _eCurScene, PPLAYER _pPlayer, int startTime, int survivedTime)
{
	_pPlayer->isGameOver = true;
	Key eKey = KeyController();

	RenderGameOver(_pPlayer->survivedTimeOnGameOver);

	if (eKey == Key::ESC)
	{
		_eCurScene = Scene::TITLE;
		system("cls");
		_pPlayer->survivedTimeOnGameOver = -1;
	}
}

void RenderGameOver(int survivedTime)
{
	COORD resolution = GetConsoleResolution();
	int y = resolution.Y / 3;
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
	Gotoxy(0, y);
	wcout << L"			 ██████╗ ██╗  ██╗    ███╗   ███╗██╗   ██╗     ██████╗  ██████╗ ██████╗ ██╗██╗" << endl;
	wcout << L"			██╔═══██╗██║  ██║    ████╗ ████║╚██╗ ██╔╝    ██╔════╝ ██╔═══██╗██╔══██╗██║██║" << endl;
	wcout << L"			██║   ██║███████║    ██╔████╔██║ ╚████╔╝     ██║  ███╗██║   ██║██║  ██║██║██║" << endl;
	wcout << L"			██║   ██║██╔══██║    ██║╚██╔╝██║  ╚██╔╝      ██║   ██║██║   ██║██║  ██║╚═╝╚═╝" << endl;
	wcout << L"			╚██████╔╝██║  ██║    ██║ ╚═╝ ██║   ██║       ╚██████╔╝╚██████╔╝██████╔╝██╗██╗" << endl;
	wcout << L"			 ╚═════╝ ╚═╝  ╚═╝    ╚═╝     ╚═╝   ╚═╝        ╚═════╝  ╚═════╝ ╚═════╝ ╚═╝╚═╝" << endl;
	int wcoutmode = _setmode(_fileno(stdout), coutmode);

	Gotoxy(47, 20);
	cout << "생존 시간 : " << survivedTime << "초";

	Gotoxy(47, 22);
	cout << "ESC를 눌러서 타이틀로 돌아가기";
}


