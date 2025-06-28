#include "Mci.h"
#include <mmsystem.h>
#include <Digitalv.h>
#include <vector>
#include <iostream>
#pragma comment(lib, "winmm.lib")

static std::vector<SoundEntry> SoundTable =
{
	{L"Sound\\Clear.wav", 100, 0},
	{L"Sound\\DdongHit.wav", 100, 0},
	{L"Sound\\Coin.wav", 100, 0},
	{L"Sound\\GameOver.wav", 100, 0},
	{L"Sound\\GameStart.wav", 100, 0},
	{L"Sound\\BGM.mp3", 70, 0},
};

bool OpenMciDevice(LPCWSTR _deviceType, LPCWSTR _elementName, UINT& _deviceId)
{
	MCI_OPEN_PARMS openParams = {};
	openParams.lpstrDeviceType = _deviceType; // ex. mpegvideo, waveaudio
	openParams.lpstrElementName = _elementName; // 파일 경로(이름)

	if (mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openParams) != 0)
	{
		return false;
	}

	_deviceId = openParams.wDeviceID; // 할당된 장치 ID 반환
	return true;
}

void CloseMciDevice(UINT& _deviceId)
{
	if (_deviceId != 0)
	{
		// RAII: 자원 해제
		mciSendCommand(_deviceId, MCI_CLOSE, 0, 0);
		_deviceId = 0; // 중복 닫기 방지
	}
}

void PlayMciDevice(UINT _deviceId, bool _repeat)
{
	MCI_PLAY_PARMS playParams = {};
	DWORD_PTR playFlags = _repeat ? MCI_DGV_PLAY_REPEAT : MCI_NOTIFY; // 0은 기본 

	if (_repeat == false && _deviceId != 0)
		mciSendCommand(_deviceId, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)&playParams);
	mciSendCommand(_deviceId, MCI_PLAY, playFlags, (DWORD_PTR)&playParams);
}

bool InitAllSounds()
{
	for (auto it = SoundTable.begin(); it != SoundTable.end(); ++it)
	{
		// 경로가 비어 있으면 로드하지 않음
		if (it->path.empty())
			continue;

		// 디바이스 종류 판단         // C스타일: wcs1에서 wcs2의 첫번째 표시를 찾는다.
		//LPCWSTR devType = (wcsstr(it->path.c_str(), L".mp3") != NULL) 
		bool isMpeg = it->path.ends_with(L".mp3");
		LPCWSTR devType = isMpeg // C++20: 주어진 부분 문자열로 끝나는지 검사
			? TEXT("mpegvideo")
			: TEXT("waveaudio");

		// 열기
		if (!OpenMciDevice(devType, it->path.c_str(), it->deviceId))
			return false;

		// 볼륨 설정 mp3만 가능
		if (isMpeg)
		{
			std::wstring volumeCommand = L"setaudio " + it->path +
				L" volume to " + std::to_wstring(it->volume);
			mciSendString(volumeCommand.c_str(), NULL, NULL, NULL);
		}
	}
	return true;
}

void PlaySoundID(SOUNDID _id, bool _repeat)
{
	// 확인 후 처리
	UINT devId = SoundTable[(int)_id].deviceId;
	if (devId == 0)
		return;
	// 정상 재생
	PlayMciDevice(devId, _repeat);
}

void ReleaseAllSounds()
{
	for (auto& sound : SoundTable)
	{
		CloseMciDevice(sound.deviceId);
	}
}
