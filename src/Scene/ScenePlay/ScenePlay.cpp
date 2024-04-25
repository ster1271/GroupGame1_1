#include "DxLib.h"
#include "ScenePlay.h"

void ScenePlay::Init()
{
	player_info.Init();
	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		enemy_info[i].InitEnemy(ENEMY_DEFAULT_POS[i]);
	}
}
void ScenePlay::Step()
{
	player_info.Step();
}
void ScenePlay::Draw()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		enemy_info[i].DrawEnemy();
	}
	player_info.Draw();
}