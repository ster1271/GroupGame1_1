#include "DxLib.h"
#include "SceneResult.h"
#include "../../Input/Input.h"
#include "../../Common.h"

void SceneResult::Init()
{
	numberHundle[10] = { 0 };
	LoadDivGraph("data/Number/number16x32_03.png", 10, 10, 1, 16, 32, numberHundle);

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

	m_bg_handle = LoadGraph(RESULT_HANDLE_PATH);
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

	DrawGraph(0, 0, m_bg_handle, true);

	//�|�C���g�`��
	MyScore = m_player_adv_dis;

	int count = 0;

	if (MyScore == 0) {
		DrawRotaGraph(640 - count * 35, 120, 2.0f, 0.0f, numberHundle[0], true);
	}
	while (MyScore > 0) {
		int num = MyScore % 10;	//�����̊m��
		MyScore = MyScore / 10;
		DrawRotaGraph(640 - count * 35, 120, 2.0f, 0.0f, numberHundle[num], true);
		count++;	//�\�����W�̕ύX
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "���U���g�V�[���ł��B");
	DrawFormatString(0, 15, GetColor(255, 255, 255), "Enter�Ŏ��̃V�[����");
	DrawFormatString(0, 45, GetColor(255, 255, 255), "���܂ł̍ő�ړ�����( %d )", m_player_max_adv_dis);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "����̈ړ�����( %d )", m_player_adv_dis);
}