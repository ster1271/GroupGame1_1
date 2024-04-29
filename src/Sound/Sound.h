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
	Jump_SE,
	Attack_SE,
	AttackEnpty_SE,

	SEtypeMaxNum
};

constexpr char BGM_HANDLE_PATH[ScenetypeMaxNum][64] = {
	{"data/BGM/������ ���[�v  ����33.wav"},
	{"data/BGM/������ ���[�v BGM �l�I���b�N73.wav"},
	{"data/BGM/MusMus-BGM-156.wav"},
};

constexpr char SE_HANDLE_PATH[SEtypeMaxNum][64] = {
	{"data/SE/�W�����v.mp3"},
	{"data/SE/�U��(��).mp3"},
	{"data/SE/�U��(��U��p).mp3"},
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
	static void StopSE(int index);
	static void PlayBGM(int index);
	static void StopBGM(int index);
	static void FinSound();
};

/*
DX_PLAYTYPE_NORMAL	�@:�@�m�[�}���Đ�
DX_PLAYTYPE_BACK	�@:�@�o�b�N�O���E���h�Đ�
DX_PLAYTYPE_LOOP	�@:�@���[�v�Đ�
*/