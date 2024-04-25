#pragma once
#include "../Draw2D.h"

constexpr char ENEMY_HANDLE_PATH[] = { "Data/Enemy/Enemy(��).png" };
constexpr int ENEMY_MAX_NUM = 1;                    //�G�̐�

//�G���\����
class EnemyInfo:public Draw2D
{
private:

public:
	EnemyInfo();
	~EnemyInfo();

	void InitEnemy(VECTOR pos);

	void DrawEnemy();

	void SpawnEnemy(VECTOR pos);
	void DeathEnemy() { m_isUse = false; }
};