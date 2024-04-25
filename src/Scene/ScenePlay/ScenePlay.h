#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../Draw2D/Player/Player.h"
#include "../../Draw2D/Enemy/Enemy.h"

constexpr VECTOR ENEMY_DEFAULT_POS[ENEMY_MAX_NUM] = {
	{100.0f,100.0f,100.0f},
};

class ScenePlay :public SceneBace
{
private:
	Player player_info;
	EnemyInfo enemy_info[ENEMY_MAX_NUM];

public:
	void Init();
	void Step();
	void Draw();
};