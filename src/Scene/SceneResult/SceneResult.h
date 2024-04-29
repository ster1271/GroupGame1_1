#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../File/File.h"

constexpr char RESULT_HANDLE_PATH[] = { "data/Bg/Bg_Result.png" };

class SceneResult :public SceneBace
{
private:
	File file_info;
	int m_player_adv_dis;
	int m_player_max_adv_dis;

	int m_bg_handle;
	int MyScoreHundle[10];
	int BestScoreHundle[10]; 
	int NewR_Hundle;

	bool IsNewRecord;

public:
	void Init();
	void Step();
	void Draw();

	void Test(int Hndl[10], int Score, int X, int Y);
};