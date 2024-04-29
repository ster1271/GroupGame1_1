#include "DxLib.h"
#include "SceneResult.h"
#include "../../Input/Input.h"
#include "../../Common.h"

void SceneResult::Init()
{
	IsNewRecord = false;
	SelectY = 580;

	MyScoreHundle[10] = { 0 };
	BestScoreHundle[10] = { 0 };
	LoadDivGraph("data/Number/number16x32_03.png", 10, 10, 1, 16, 32, MyScoreHundle);
	LoadDivGraph("data/Number/number16x32_03.png", 10, 10, 1, 16, 32, BestScoreHundle);

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
	NewR_Hundle = LoadGraph("data/Bg/New.png");
	Hundle_Title = LoadGraph("data/Bg/ReturnT.png");
	Hundle_Try = LoadGraph("data/Bg/TryAgein.png");
	SelectHundl = LoadGraph("data/Bg/Select.png");
}
void SceneResult::Step()
{
	//�x�X�g�X�R�A���z�����Ƃ�
	if (m_player_adv_dis >= m_player_max_adv_dis)
	{
		//�t���O��true�ɂ���
		IsNewRecord = true;
	}

	if (Input::IsKeyPush(KEY_INPUT_DOWN))
	{
		SelectY = 650;
	}
	else if (Input::IsKeyPush(KEY_INPUT_UP))
	{
		SelectY = 580;
	}

	if (Input::IsKeyPush(KEY_INPUT_RETURN))
	{
		if (SelectY == 580)
		{
			g_current_scene_ID = Play;
		}
		else
		{
			g_current_scene_ID = Title;
		}
	}
}
void SceneResult::Draw()
{
	DrawGraph(0, 0, m_bg_handle, true);

	//=============�|�C���g�`��=====================
	DrawNumber(MyScoreHundle, m_player_adv_dis, 750, 315);			//����̃X�R�A
	DrawNumber(BestScoreHundle, m_player_max_adv_dis, 750, 450 );		//�x�X�g�X�R�A
	//=============�|�C���g�`��=====================

	//�X�V�t���O��true�ɂȂ�����
	if (IsNewRecord == true)
	{
		DrawGraph(0, 80,NewR_Hundle, true);
	}

	DrawRotaGraph(640, 580, 1.0f, 0.0f, Hundle_Try, true, false, false);
	DrawRotaGraph(640, 650, 1.0f, 0.0f, Hundle_Title, true, false, false);
	DrawRotaGraph(420, SelectY, 0.3f, 0.0f, SelectHundl, true, false, false);
}

void SceneResult::DrawNumber(int Hndl[10], int Score, int X, int Y)//����(�����摜�i�[�n���h��, ���ꂽ���X�R�A, X���W, Y���W)
{
	//�|�C���g�`��
	int DrawScore = Score;

	int count = 0;

	if (DrawScore == 0) {
		DrawRotaGraph(X - count * 35, Y, 2.0f, 0.0f, Hndl[0], true);
	}
	while (DrawScore > 0) {
		int num = DrawScore % 10;	//�����̊m��
		DrawScore = DrawScore / 10;
		DrawRotaGraph(X - count * 35, Y, 2.0f, 0.0f, Hndl[num], true);
		count++;	//�\�����W�̕ύX
	}
}