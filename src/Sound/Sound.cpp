#include "DxLib.h"
#include "Sound.h"

int Sound::m_BGM_handle[ScenetypeMaxNum];
int Sound::m_SE_handle[SEtypeMaxNum];

Sound::Sound()
{
	for (int i = 0; i < ScenetypeMaxNum; i++)
		m_BGM_handle[i] = 0;
	for (int i = 0; i < SEtypeMaxNum; i++)
		m_SE_handle[i] = 0;
}

Sound::~Sound()
{
	FinSound();
}

void Sound::InitSound()
{
	//サウンド読み込み
	for (int i = 0; i < ScenetypeMaxNum; i++) {
		m_BGM_handle[i] = LoadSoundMem(BGM_HANDLE_PATH[i]);
	}
	for (int i = 0; i < SEtypeMaxNum; i++) {
		m_BGM_handle[i] = LoadSoundMem(SE_HANDLE_PATH[i]);
	}
}

void Sound::PlaySE(int index)
{
	//サウンド再生
	PlaySoundMem(m_SE_handle[index], DX_PLAYTYPE_BACK, true);
}

void Sound::PlayBGM(int index)
{
	// BGM再生
	if (CheckSoundMem(m_BGM_handle[index]) == 0)
	{
		PlaySoundMem(m_BGM_handle[index], DX_PLAYTYPE_LOOP, true);
	}
}

void Sound::StopBGM(int index)
{
	// BGM停止
	if (CheckSoundMem(m_BGM_handle[index]) == 1)
	{
		StopSoundMem(m_BGM_handle[index]);
	}
}

void Sound::FinSound()
{
	//サウンド破棄
	for (int i = 0; i < ScenetypeMaxNum; i++)
		DeleteSoundMem(m_BGM_handle[i]);

	for (int i = 0; i < SEtypeMaxNum; i++)
		DeleteSoundMem(m_SE_handle[i]);
}