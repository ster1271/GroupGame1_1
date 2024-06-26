#pragma once
#include "../Draw2D.h"

constexpr char ENEMY_HANDLE_PATH[] = { "Data/Enemy/Enemy(人玉).png" };

constexpr int ENEMY_COLLISION_SIZE = 60;

constexpr float ENEMY_INTERVAL_POS_X = 500;

//敵情報構造体
class EnemyInfo:public Draw2D
{
private:
	static int m_enemy_index;	//左から数えて何体目の敵か

public:
	EnemyInfo();
	~EnemyInfo();

	void InitEnemy();

	void DrawEnemy();

	void SpawnEnemy();
	void DeathEnemy() { m_isUse = false; }
};