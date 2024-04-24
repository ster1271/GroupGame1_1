#include "DxLib.h"   //2309405@‰F‰ê’Ë’g‹I
#include"Enemy.h"

#define ENEMY_PATH "Data/Enemy/Enemy(‰¼).png"
#define ENEMY_MAX_NUM   (1)                      //“G‚Ì”

EnemyInfo enemyInfo[ENEMY_MAX_NUM] = { 0 };

void InitEnemy() {
	//“G‰Šú‰»
	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		//“G1
		enemyInfo[i].handle = LoadGraph(ENEMY_PATH);
		enemyInfo[i].x = { 0 };
		enemyInfo[i].y = { 0 };
	}
}

void DrawEnemy()
{
	//“G•`‰æ
	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		DrawRotaGraph(enemyInfo[i].x, enemyInfo[i].y, 1.0f, 0.0, enemyInfo[i].handle, true);
	}
}