#pragma once
#include<Windows.h>

// ¿ÀÇÂ
bool OpenMciDevice(LPCWSTR _deviceType, LPCWSTR _name, UINT& _deviceid);

// ´Ý±â
void CloseMciDevice(UINT& _deviceid);

// Àç»ý
void PlayMciDevice(UINT _deviceid, bool repeat = false);