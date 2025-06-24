#pragma once

enum class Menu
{
	START, INFO, QUIT, FAIL
};

enum class Key
{
	LEFT, RIGHT, DOWN, UP, SPACE, ESC, FAIL
};

enum class Scene
{
	TITLE, GAME, INFO, QUIT, END, GAMEOVER, CLEAR
};

enum class Tile
{
	BACK = '0', WALL, START, SPAWNDDONG, DDONG, FLOOR, COIN
};