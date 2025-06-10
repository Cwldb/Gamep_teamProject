#pragma once
#include "Enums.h"

const int MAP_HEIGHT = 20;
const int MAP_WIDTH = 21;

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
    int coinCnt; // 코인 개수
}PLAYERSTATE, * PPLAYERSTATE;

typedef struct _playerpos
{
    POS tPos;
    POS tNewPos;
}PLAYERPOS, * PPLAYERPOS;

typedef struct _player
{
    PLAYERPOS position;
    PLAYERSTATE state;
}PLAYER, * PPLAYER;

void Init();

void Update();

void Render();
void GameScene(Scene& _eCurScene);
