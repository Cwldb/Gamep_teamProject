#pragma once
#include "Enums.h"
#include <ctime>
#include<vector>
using std::vector;

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 22;
const int DDONG_DROP_INTERVAL = 10;

typedef struct _pos
{
    int x;
    int y;
}POS, * PPOS;

typedef struct _playerstate
{
    int coinCnt;
}PLAYERSTATE, * PPLAYERSTATE;

typedef struct _playerpos
{
    POS tPos;
    POS tNewPos;
    POS tStartPos;
}PLAYERPOS, * PPLAYERPOS;

typedef struct _player
{
    PLAYERPOS position;
    PLAYERSTATE state;
    bool isGameOver = false;
    int survivedTimeOnGameOver = -1;
    int startTime = 0;
}PLAYER, * PPLAYER;

typedef struct _tagDDONG
{
    POS _pos;
    bool isCol;

}DDONG, * PDDONG;

void Init(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer);

void Update(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, vector<DDONG> vecDDONG, Scene& _eCurScene);

void Render(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, int _startTime , Scene& _eCurScene);
void RenderUI(PPLAYER _pPlayer, int _startTime);
void LoadStage(char _gameMap[MAP_HEIGHT][MAP_WIDTH]);
void GameScene(Scene& _eCurScene, char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, vector<DDONG> vecDDONG, int _startTime);
void SpawnDDong(char _gameMap[MAP_HEIGHT][MAP_WIDTH], vector<DDONG>& vecDDONG, PPLAYER _pPlayer, Scene& _eCurScene);
void InfoScene(Scene& _eCurScene, PPLAYER _pPlayer);
void RenderInfo(PPLAYER _pPlayer);
void GameOverScene(Scene& _eCurScene, PPLAYER _pPlayer, int startTime, int survivedTime);
void RenderGameOver(int startTime, int survivedTime);

void PlayerInit(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer);
void HandleInput(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer);

void ClearBottomRow(char _gameMap[MAP_HEIGHT][MAP_WIDTH]);
void MoveTileDown(char _gameMap[MAP_HEIGHT][MAP_WIDTH], char tileType, char newType = 0);
void SpawnTile(char _gameMap[MAP_HEIGHT][MAP_WIDTH], char tileType, int maxSpawn);