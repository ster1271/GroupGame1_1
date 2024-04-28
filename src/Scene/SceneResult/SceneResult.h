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

	int numberHundle[10];
	int MyScore;
	int BestScore;

public:
	void Init();
	void Step();
	void Draw();
};