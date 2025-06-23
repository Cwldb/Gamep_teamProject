#pragma once
#include<iostream>
//using namespace std;
using std::cout;
using std::wcout;
using std::endl;
#include<string>
using std::string;
using std::wstring;
//#include<vector>
//using std::vector;
#include<Windows.h>

void SetConsoleSettings(int _width, int _height, bool _isFullscreen, const std::wstring& _title);
void SetLockResize();
COORD GetConsoleResolution();
void DisableConsoleResize();

void Gotoxy(int _x, int _y);
BOOL IsGotoxy(int _x, int _y);
COORD CursorPos();
void SetCursorVisual(bool _isVis, DWORD _size);
enum class COLOR {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHTGRAY = 7,
    DARKGRAY = 8,
    LIGHTBLUE = 9,
    LIGHTGREEN = 10,
    LIGHTCYAN = 11,
    LIGHTRED = 12,
    LIGHTMAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};
void SetColor(COLOR _textcolor =COLOR::LIGHTGRAY, COLOR _bgcolor = COLOR::BLACK);
void FrameSync(unsigned int _frame);
void SetConsoleFont(LPCWSTR _fontname, COORD _size, UINT _weight);