#pragma once
#include<Windows.h>

// ����
bool OpenMciDevice(LPCWSTR _deviceType, LPCWSTR _name, UINT& _deviceid);

// �ݱ�
void CloseMciDevice(UINT& _deviceid);

// ���
void PlayMciDevice(UINT _deviceid, bool repeat = false);