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
	//�T�E���h�ǂݍ���
	for (int i = 0; i < ScenetypeMaxNum; i++) {
		m_BGM_handle[i] = LoadSoundMem(BGM_HANDLE_PATH[i]);
	}
	for (int i = 0; i < SEtypeMaxNum; i++) {
		m_SE_handle[i] = LoadSoundMem(SE_HANDLE_PATH[i]);
	}

	ChangeVolumeSoundMem(120, m_SE_handle[0]);
	ChangeVolumeSoundMem(200, m_SE_handle[1]);
	ChangeVolumeSoundMem(160, m_SE_handle[2]);
}

void Sound::PlaySE(int index)
{
	//�T�E���h�Đ�
	PlaySoundMem(m_SE_handle[index], DX_PLAYTYPE_BACK, true);
}

void Sound::StopSE(int index)
{
	// SE��~
	if (CheckSoundMem(m_SE_handle[index]) == 1)
	{
		StopSoundMem(m_SE_handle[index]);
	}
}

void Sound::PlayBGM(int index)
{
	// BGM�Đ�
	if (CheckSoundMem(m_BGM_handle[index]) == 0)
	{
		PlaySoundMem(m_BGM_handle[index], DX_PLAYTYPE_LOOP, true);
	}
}

void Sound::StopBGM(int index)
{
	// BGM��~
	if (CheckSoundMem(m_BGM_handle[index]) == 1)
	{
		StopSoundMem(m_BGM_handle[index]);
	}
}

void Sound::FinSound()
{
	//�T�E���h�j��
	for (int i = 0; i < ScenetypeMaxNum; i++)
		DeleteSoundMem(m_BGM_handle[i]);

	for (int i = 0; i < SEtypeMaxNum; i++)
		DeleteSoundMem(m_SE_handle[i]);
}