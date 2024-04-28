#include "DxLib.h"
#include "../../Common.h"
#include "ScenePlay.h"
#include "../../Screen/Screen.h"
#include "../../GameCollision/GameCollision.h"

void ScenePlay::Init()
{
	player_info.Init();
	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		enemy_info[i].InitEnemy();
	}
	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		enemy_info[i].SpawnEnemy();
	}
	wall_info.Init();
	background_info.Init();

	Screen::Init();

	m_gameover_flag = false;
}

void ScenePlay::Step()
{
	if (!m_gameover_flag) {
		player_info.Step();

		if (player_info.GetStartFlag()) {
			wall_info.Step(player_info.GetPos());

			for (int i = 0; i < ENEMY_MAX_NUM; i++) {
				if (enemy_info[i].GetIsUse())
					CollisionPlayerAttackToEnemy(player_info, enemy_info[i]);
			}

			Screen::Step(player_info.GetPos());

			//画面外(左)に行ったら使用フラグを折る
			for (int i = 0; i < ENEMY_MAX_NUM; i++) {
				if (enemy_info[i].GetPos().x - Screen::m_screex_pos_x <= -ENEMY_COLLISION_SIZE) {
					enemy_info[i].SetIsUse(false);
					break;
				}
			}
			//一定距離進んだら敵をスポーンさせる
			if (Screen::m_screex_pos_x - Screen::m_reference_point >= ENEMY_INTERVAL_POS_X) {
				Screen::m_reference_point += ENEMY_INTERVAL_POS_X;
				for (int i = 0; i < ENEMY_MAX_NUM; i++) {

					if (!enemy_info[i].GetIsUse()) {
						enemy_info[i].SpawnEnemy();
						break;
					}
				}
			}

			if (player_info.GetPos().y > SCREEN_SIZE_Y||
				CollisionPlayerToWall(player_info.GetPos(), wall_info.GetPos())) {
				m_gameover_flag = true;
			}

			background_info.Step();
		}
	}
	else {
		Fin();
	}
}

void ScenePlay::Draw()
{
	background_info.Draw();

	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		enemy_info[i].DrawEnemy();
	}
	wall_info.Draw();
	player_info.Draw();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "(%d)", (int)((player_info.GetPos().x - PLAYER_DEFAULT_POS.x) / 100));
}

void ScenePlay::Fin()
{
	//最大移動距離を保存したファイルを開く
	if (file_info.OpenFile(MAX_DISTANCE_SAVE_DATA, "r")) {
		int distance;

		//最大移動距離を取得
		int a = fscanf_s(file_info.fp, "%d", &distance);
		file_info.CloseFile();

		//保存された数値より今回の距離の方が長かった時
		if (distance < ((player_info.GetPos().x - PLAYER_DEFAULT_POS.x) / 100)) {
			//今回の距離を最大移動距離を保存するファイルに保存する
			if (file_info.OpenFile(MAX_DISTANCE_SAVE_DATA, "w")) {
				fprintf(file_info.fp, "%d", (int)((player_info.GetPos().x - PLAYER_DEFAULT_POS.x) / 100));
				file_info.CloseFile();
			}
		}
		//今回の距離を保存する
		if (file_info.OpenFile(DISTANCE_SAVE_DATA, "w")) {
			fprintf(file_info.fp, "%d", (int)((player_info.GetPos().x - PLAYER_DEFAULT_POS.x) / 100));
			file_info.CloseFile();
		}
	}

	g_current_scene_ID = Result;
}