#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../Draw2D/Player/Player.h"
#include "../../Draw2D/Enemy/Enemy.h"
#include "../../Draw2D/Wall/Wall.h"
#include "../../File/File.h"

constexpr int ENEMY_MAX_NUM = 4;                    //ìGÇÃêî
constexpr VECTOR ENEMY_DEFAULT_POS[ENEMY_MAX_NUM] = {
	{400.0f,310.0f,0.0f},
	{800.0f,410.0f,0.0f},
	{1200.0f,360.0f,0.0f},
	{1600.0f,330.0f,0.0f},
};

class ScenePlay :public SceneBace
{
private:
	Player player_info;
	EnemyInfo enemy_info[ENEMY_MAX_NUM];
	Wall wall_info;
	File file_info;

	bool m_gameover_flag;

public:
	void Init();
	void Step();
	void Draw();

	void Fin();
};