#pragma once
#include "Enums.h"
#include<Windows.h>

void TitleScene(Scene& _eCurScene);
void TitleSceneUpdate(Scene& _eCurScene);
void CrossAnimation(COORD _resolution, int _delaytime);
void FlashAnimation(COORD _resolution, int _cnt, int _delaytime);
void EnterAnimation();
void TitleSceneRender();
Menu GetCurMenu();