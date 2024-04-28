#pragma once

enum Scenetype
{
	Title_BGM,
	Play_BGM,
	Result_BGM,

	ScenetypeMaxNum
};

enum SEtype
{
	Jump,
	Attack,

	SEtypeMaxNum
};

constexpr char BGM_HANDLE_PATH[ScenetypeMaxNum][64] = {
	{},
	{},
	{},
};

constexpr char SE_HANDLE_PATH[SEtypeMaxNum][64] = {
	{},
	{},
};

class Sound
{
private:
	static int m_BGM_handle[ScenetypeMaxNum];
	static int m_SE_handle[SEtypeMaxNum];
public:
	Sound();
	~Sound();

	static void InitSound();
	static void PlaySE(int index);
	static void PlayBGM(int index);
	static void StopBGM(int index);
	static void FinSound();
};

/*
DX_PLAYTYPE_NORMAL	�@:�@�m�[�}���Đ�
DX_PLAYTYPE_BACK	�@:�@�o�b�N�O���E���h�Đ�
DX_PLAYTYPE_LOOP	�@:�@���[�v�Đ�
*/