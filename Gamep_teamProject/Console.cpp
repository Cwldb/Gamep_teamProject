#include "Console.h"
#include <Windows.h>

void SetConsoleSettings(int _width, int _height, bool _isFullscreen, const std::wstring& _title)
{
	// 제목 설정
	SetConsoleTitle(_title.c_str());

	HWND hwnd = GetConsoleWindow();
	// 풀스크린 할지
	if (_isFullscreen)
	{
		// 위에 타이틀바 제거
		//SetWindowLong(hwnd, GWL_STYLE, WS_POPUP);
		ShowWindow(hwnd, SW_MAXIMIZE);
	}

	// 해상도 설정
	else
	{
		//LONG style = GetWindowLong(hwnd, GWL_STYLE);
		//style &= ~WS_CAPTION;
		//SetWindowLong(hwnd, GWL_STYLE, style);
		MoveWindow(hwnd, 0,0,_width, _height, true);
	}
}

void SetLockResize()
{
	HWND hwnd = GetConsoleWindow();
	LONG style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_SIZEBOX &~WS_MAXIMIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, style);
}

//여기는 콘솔창 조절 못하게 하는 함수
void DisableConsoleResize()
{
    HWND hWnd = GetConsoleWindow();
    if (hWnd)
    {
        LONG style = GetWindowLong(hWnd, GWL_STYLE);
        style &= ~WS_SIZEBOX;
        style &= ~WS_MAXIMIZEBOX;
        SetWindowLong(hWnd, GWL_STYLE, style);
    }
}

COORD GetConsoleResolution()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	short width  = info.srWindow.Right - info.srWindow.Left  + 1;
	short height = info.srWindow.Bottom - info.srWindow.Top  + 1;
	//COORD coord  {width, height};
	return { width, height };
	//return COORD{ width, height };
}

void Gotoxy(int _x, int _y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { _x, _y };
	//Cur.X = _x;
	SetConsoleCursorPosition(handle, Cur);
}

BOOL IsGotoxy(int _x, int _y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { _x, _y };
	//Cur.X = _x;
	return SetConsoleCursorPosition(handle, Cur);
}

COORD CursorPos()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	return info.dwCursorPosition;
}

void SetCursorVisual(bool _isVis, DWORD _size)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info = {_size, _isVis};
	// size : 1 ~ 100, 
	// isvis= false하고 싶으면 size가 최소 1이 있어야 합니다.
	//info.dwSize = _size;
	SetConsoleCursorInfo(handle, &info);
}

void SetColor(COLOR _textcolor, COLOR _bgcolor)
{
	int textcolor = (int)_textcolor;
	int bgcolor = (int)_bgcolor;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 
		(bgcolor << 4) | textcolor);
}


void FrameSync(unsigned int _frame)
{
	clock_t oldtime, curtime;
	oldtime = clock();
	while (true)
	{
		curtime = clock();
		if (curtime - oldtime > 1000 / _frame)
		{
			oldtime = curtime;
			break;
		}
	}
}

void SetConsoleFont(LPCWSTR _fontname, COORD _size, UINT _weight)
{
	// 콘솔 핸들
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// 구조체 초기화
	CONSOLE_FONT_INFOEX cf = {};
	cf.cbSize = sizeof(CONSOLE_FONT_INFOEX);

	// 현재 폰트 정보 Get
	GetCurrentConsoleFontEx(handle, false, &cf);
	cf.dwFontSize = _size; // 폭, 높이
	cf.FontWeight = _weight; // FW~
	wcscpy_s(cf.FaceName, _fontname); // 폰트이름 복사
	// 폰트 정보 Set
	SetCurrentConsoleFontEx(handle, false, &cf);
}