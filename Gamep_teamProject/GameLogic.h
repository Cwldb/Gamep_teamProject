#pragma once
#include "Enums.h"

const int MAP_HEIGHT = 24;
const int MAP_WIDTH = 22;


void Init(char _gameMap[MAP_HEIGHT][MAP_WIDTH]);

void Update();

void Render(char _gameMap[MAP_HEIGHT][MAP_WIDTH]);
void LoadStage(char _gameMap[MAP_HEIGHT][MAP_WIDTH]);

void GameScene(Scene& _eCurScene, char _gameMap[MAP_HEIGHT][MAP_WIDTH]);
void InfoScene(Scene& _eCurScene);
void RenderInfo();
