#include "DxLib.h"   //2309405@‰F‰ê’Ë’g‹I
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

void EnemyInfo::InitEnemy(VECTOR pos) {
	//“G‰Šú‰»

	LoadHandle((char*)ENEMY_HANDLE_PATH, 1, 1, 1, 60, 60);

	m_pos = pos;

	m_enemy_index = 5;
}

void EnemyInfo::DrawEnemy()
{
	//“G•`‰æ
	DrawGraph(m_pos.x - Screen::GetScreenPosX(), m_pos.y, m_handle[0], true);
}

void EnemyInfo::SpawnEnemy()
{
	VECTOR pos;

	pos.x = 400 * m_enemy_index;
	pos.y = GetRand(100) + 310;
	pos.z = 0;

	m_enemy_index++;

	m_pos = pos;
	m_isUse = true;
}