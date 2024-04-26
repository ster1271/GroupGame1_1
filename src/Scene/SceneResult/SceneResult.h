#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../File/File.h"

class SceneResult :public SceneBace
{
private:
	File file_info;
	int m_player_adv_dis;
	int m_player_max_adv_dis;

public:
	void Init();
	void Step();
	void Draw();
};