#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../Draw2D/Player/Player.h"
#include "../../Draw2D/Enemy/Enemy.h"
#include "../../Draw2D/Wall/Wall.h"
#include "../../Draw2D/BackGround/BackGround.h"
#include "../../File/File.h"

constexpr int ENEMY_MAX_NUM = 4;                    //ìGÇÃêî

class ScenePlay :public SceneBace
{
private:
	Player player_info;
	EnemyInfo enemy_info[ENEMY_MAX_NUM];
	Wall wall_info;
	BackGround background_info;

	File file_info;

	bool m_gameover_flag;

public:
	void Init();
	void Step();
	void Draw();

	void Fin();
};