#include "KeyController.h"
#include <Windows.h>
#include <chrono>

using namespace std::chrono;
Key KeyController()
{
    static auto lastInputTime = steady_clock::now();
    auto now = steady_clock::now();
    auto elapsed = duration_cast<milliseconds>(now - lastInputTime).count();

    int inputDelay = 60;

    if (elapsed < inputDelay)
        return Key::FAIL;

    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        lastInputTime = now;
        return Key::LEFT;
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        lastInputTime = now;
        return Key::RIGHT;
    }
    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        lastInputTime = now;
        return Key::UP;
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        lastInputTime = now;
        return Key::DOWN;
    }
    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
        lastInputTime = now;
        return Key::SPACE;
    }
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    {
        lastInputTime = now;
        return Key::ESC;
    }

    return Key::FAIL;
}