#include "DxLib.h"   //2309405Å@âFâÍíÀígãI
#include"Enemy.h"
#include "../../Screen/Screen.h"

int EnemyInfo::m_enemy_index;

EnemyInfo::EnemyInfo()
{

}
EnemyInfo::~EnemyInfo()
{
	Draw2D::~Draw2D();
}

void EnemyInfo::InitEnemy() {
	//ìGèâä˙âª

	LoadHandle((char*)ENEMY_HANDLE_PATH, 1, 1, 1, 60, 60);

	m_pos = { 0.0f,0.0f,0.0f };

	m_enemy_index = 1;

	m_coliision_size = { (float)ENEMY_COLLISION_SIZE ,(float)ENEMY_COLLISION_SIZE ,0 };

	m_isUse = false;
}

void EnemyInfo::DrawEnemy()
{
	//ìGï`âÊ
	if (m_isUse)
		DrawGraph((int)(m_pos.x - Screen::m_screex_pos_x),
			(int)(m_pos.y),
			m_handle[0],
			true);
}

void EnemyInfo::SpawnEnemy()
{
	VECTOR pos;

	pos.x = (float)(ENEMY_INTERVAL_POS_X * m_enemy_index);
	pos.y = (float)(GetRand(100) + GetRand(400));
	pos.z = 0.0f;

	m_enemy_index++;

	m_pos = pos;
	m_isUse = true;
}