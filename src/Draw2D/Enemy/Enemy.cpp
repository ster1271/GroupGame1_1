#include "DxLib.h"   //2309405@‰F‰ê’Ë’g‹I
#include"Enemy.h"

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
}

void EnemyInfo::DrawEnemy()
{
	//“G•`‰æ
	DrawGraph(m_pos.x, m_pos.y, m_handle[0], true);
}

void EnemyInfo::SpawnEnemy(VECTOR pos)
{
	m_pos = pos;
	m_isUse = true;
}