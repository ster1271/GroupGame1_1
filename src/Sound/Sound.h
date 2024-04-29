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
	{},
	{},
	{},
};

constexpr char SE_HANDLE_PATH[SEtypeMaxNum][64] = {
	{"data/SE/ジャンプ.wav"},
	{"data/SE/攻撃(手).wav"},
	{"data/SE/攻撃(空振り用).wav"},
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
DX_PLAYTYPE_NORMAL	　:　ノーマル再生
DX_PLAYTYPE_BACK	　:　バックグラウンド再生
DX_PLAYTYPE_LOOP	　:　ループ再生
*/