#include "DxLib.h"
#include "SceneResult.h"
#include "../../Input/Input.h"
#include "../../Common.h"

void SceneResult::Init()
{
	//�ő�ړ�������ۑ������t�@�C�����J��
	if (file_info.OpenFile(MAX_DISTANCE_SAVE_DATA, "r")) {

		int a = fscanf_s(file_info.fp, "%d", &m_player_max_adv_dis);

		file_info.CloseFile();
	}
	//����̈ړ�������ۑ������t�@�C�����J��
	if (file_info.OpenFile(DISTANCE_SAVE_DATA, "r")) {
		
		int a = fscanf_s(file_info.fp, "%d", &m_player_adv_dis);

		file_info.CloseFile();
	}
}
void SceneResult::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN))
	{
		g_current_scene_ID = Title;
	}
}
void SceneResult::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "���U���g�V�[���ł��B");
	DrawFormatString(0, 15, GetColor(255, 255, 255), "Enter�Ŏ��̃V�[����");
	DrawFormatString(0, 45, GetColor(255, 255, 255), "���܂ł̍ő�ړ�����( %d )", m_player_max_adv_dis);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "����̈ړ�����( %d )", m_player_adv_dis);
}