#include "Mci.h"
#include<mmsystem.h>
#include<Digitalv.h>
#include "Console.h"
// winmm.lib
#pragma comment(lib, "winmm.lib")
bool OpenMciDevice(LPCWSTR _deviceType, LPCWSTR _name, UINT& _deviceid)
{
	MCI_OPEN_PARMS openParams = {};
	openParams.lpstrDeviceType = _deviceType; // ex. mpegvideo, waveaudio
	openParams.lpstrElementName = _name; // ���� ���(�̸�)

	if (mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openParams) != 0)
	{
		// ���� �߻� �� false ��ȯ
		return false;
	}

	_deviceid = openParams.wDeviceID; // �Ҵ�� ��ġ ID ��ȯ
	return true;


	////PlaySound();
	//// �Լ�
	//mciSendCommand();
	//// 1. ����̽� ���̵�
	//// 2. ����̽� ���� �޽���
	//// -> open, pause, seek, close, play
	//// 3. �޽����� ���� �÷���
	//// -> repeat, notipy
	//// 4. �߰� �ּ�
	//// -> ������ ����ü ����.

	//// ����ü
	//// ����: ������ (   )����̹��� �÷��� �� �޸𸮸� �о���� ����
	//// ���̵� �߱޹޴� ��
	//MCI_OPEN_PARMS;

	//// �÷���
	//MCI_PLAY_PARMS;

	//return false;
}

void CloseMciDevice(UINT& _deviceid)
{
}

void PlayMciDevice(UINT _deviceid, bool repeat)
{
}
