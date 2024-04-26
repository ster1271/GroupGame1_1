#include "DxLib.h"
#include "../../Common.h"
#include "ScenePlay.h"
#include "../../Screen/Screen.h"
#include "../../GameCollision/GameCollision.h"

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

	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		CollisionPlayerAttackToEnemy(player_info, enemy_info[i]);
	}

	Screen::Step(player_info.GetPos());

	//��ʊO(��)�ɍs������g�p�t���O��܂�
	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		if (enemy_info[i].GetPos().x - Screen::m_screex_pos_x <= -ENEMY_COLLISION_SIZE) {
			enemy_info[i].SetIsUse(false);
			break;
		}
	}
	//��苗���i�񂾂�G���X�|�[��������
	if (Screen::m_screex_pos_x - Screen::m_reference_point >= 400) {
		Screen::m_reference_point += 400;
		for (int i = 0; i < ENEMY_MAX_NUM; i++) {

			if (!enemy_info[i].GetIsUse()) {
				enemy_info[i].SpawnEnemy();
				break;
			}
		}
	}

	if (player_info.GetPos().y > SCREEN_SIZE_Y) {
		Fin();
	}
}

void ScenePlay::Draw()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		enemy_info[i].DrawEnemy();
	}
	player_info.Draw();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "(%d)", (int)((player_info.GetPos().x - PLAYER_DEFAULT_POS.x) / 100));
}

void ScenePlay::Fin()
{
	//�ő�ړ�������ۑ������t�@�C�����J��
	if (file_info.OpenFile(MAX_DISTANCE_SAVE_DATA, "r")) {
		int distance;

		//�ő�ړ��������擾
		int a = fscanf_s(file_info.fp, "%d", &distance);
		file_info.CloseFile();

		//�ۑ����ꂽ���l��荡��̋����̕�������������
		if (distance < ((player_info.GetPos().x - PLAYER_DEFAULT_POS.x) / 100)) {
			//����̋������ő�ړ�������ۑ�����t�@�C���ɕۑ�����
			if (file_info.OpenFile(MAX_DISTANCE_SAVE_DATA, "w")) {
				fprintf(file_info.fp, "%d", (int)((player_info.GetPos().x - PLAYER_DEFAULT_POS.x) / 100));
				file_info.CloseFile();
			}
		}
		//����̋�����ۑ�����
		if (file_info.OpenFile(DISTANCE_SAVE_DATA, "w")) {
			fprintf(file_info.fp, "%d", (int)((player_info.GetPos().x - PLAYER_DEFAULT_POS.x) / 100));
			file_info.CloseFile();
		}
	}

	g_current_scene_ID = Result;
}