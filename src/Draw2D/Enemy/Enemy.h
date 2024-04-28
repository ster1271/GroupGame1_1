#pragma once
#include "../Draw2D.h"

constexpr char ENEMY_HANDLE_PATH[] = { "Data/Enemy/Enemy(‰¼).png" };

constexpr int ENEMY_COLLISION_SIZE = 60;

constexpr float ENEMY_INTERVAL_POS_X = 500;

//“Gî•ñ\‘¢‘Ì
class EnemyInfo:public Draw2D
{
private:
	static int m_enemy_index;	//¶‚©‚ç”‚¦‚Ä‰½‘Ì–Ú‚Ì“G‚©

public:
	EnemyInfo();
	~EnemyInfo();

	void InitEnemy();

	void DrawEnemy();

	void SpawnEnemy();
	void DeathEnemy() { m_isUse = false; }
};