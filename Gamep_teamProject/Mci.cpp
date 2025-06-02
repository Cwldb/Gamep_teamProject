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
	openParams.lpstrElementName = _name; // 파일 경로(이름)

	if (mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openParams) != 0)
	{
		// 오류 발생 시 false 반환
		return false;
	}

	_deviceid = openParams.wDeviceID; // 할당된 장치 ID 반환
	return true;


	////PlaySound();
	//// 함수
	//mciSendCommand();
	//// 1. 디바이스 아이디
	//// 2. 디바이스 보낼 메시지
	//// -> open, pause, seek, close, play
	//// 3. 메시지에 대한 플래그
	//// -> repeat, notipy
	//// 4. 추가 주소
	//// -> 정해진 구조체 전달.

	//// 구조체
	//// 오픈: 파일을 (   )드라이버에 올려서 그 메모리를 읽어오기 위해
	//// 아이디를 발급받는 것
	//MCI_OPEN_PARMS;

	//// 플레이
	//MCI_PLAY_PARMS;

	//return false;
}

void CloseMciDevice(UINT& _deviceid)
{
}

void PlayMciDevice(UINT _deviceid, bool repeat)
{
}
