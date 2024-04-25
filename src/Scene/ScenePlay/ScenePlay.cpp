#include "DxLib.h"
#include "ScenePlay.h"
#include "../../Screen/Screen.h"

void ScenePlay::Init()
{
	player_info.Init();
	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		enemy_info[i].InitEnemy(ENEMY_DEFAULT_POS[i]);
	}
	Screen::Init();
}

void ScenePlay::Step()
{
	player_info.Step();
	Screen::Step(player_info.GetPos());

	//画面外(左)に行ったら使用フラグを折る
	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		if (enemy_info[i].GetPos().x - Screen::m_screex_pos_x <= -ENEMY_COLLISION_SIZE) {
			enemy_info[i].SetIsUse(false);
			break;
		}
	}
	//一定距離進んだら敵をスポーンさせる
	if (Screen::m_screex_pos_x - Screen::m_reference_point >= 400) {
		Screen::m_reference_point += 400;
		for (int i = 0; i < ENEMY_MAX_NUM; i++) {
			if (enemy_info[i].GetPos().x <= -ENEMY_COLLISION_SIZE) {

			}

			if (!enemy_info[i].GetIsUse()) {
				enemy_info[i].SpawnEnemy();
				break;
			}
		}
	}
}

void ScenePlay::Draw()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		enemy_info[i].DrawEnemy();
	}
	player_info.Draw();
}