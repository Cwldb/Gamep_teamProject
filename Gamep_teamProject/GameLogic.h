#pragma once
#include "Enums.h"

const int MAP_HEIGHT = 24;
const int MAP_WIDTH = 22;

typedef struct _pos
{
    int x;
    int y;
    bool operator == (_pos other)
    //bool operator== (const _pos& other) const
    {
        return (x == other.x && y == other.y);
    }

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
}PLAYER, * PPLAYER;

void Init(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer);

void Update(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer);

void Render(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer);
void LoadStage(char _gameMap[MAP_HEIGHT][MAP_WIDTH]);
void GameScene(Scene& _eCurScene, char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer);
void InfoScene(Scene& _eCurScene);
void RenderInfo();

void PlayerInit(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer);
void HandleInput(char _gameMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer);
