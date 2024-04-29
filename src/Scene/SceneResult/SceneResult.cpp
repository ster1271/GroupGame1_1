#include "DxLib.h"
#include "SceneResult.h"
#include "../../Input/Input.h"
#include "../../Common.h"

void SceneResult::Init()
{
	IsNewRecord = false;

	MyScoreHundle[10] = { 0 };
	BestScoreHundle[10] = { 0 };
	LoadDivGraph("data/Number/number16x32_03.png", 10, 10, 1, 16, 32, MyScoreHundle);
	LoadDivGraph("data/Number/number16x32_03.png", 10, 10, 1, 16, 32, BestScoreHundle);

	//最大移動距離を保存したファイルを開く
	if (file_info.OpenFile(MAX_DISTANCE_SAVE_DATA, "r")) {

		int a = fscanf_s(file_info.fp, "%d", &m_player_max_adv_dis);

		file_info.CloseFile();


	}
	//今回の移動距離を保存したファイルを開く
	if (file_info.OpenFile(DISTANCE_SAVE_DATA, "r")) {
		
		int a = fscanf_s(file_info.fp, "%d", &m_player_adv_dis);

		file_info.CloseFile();
	}

	m_bg_handle = LoadGraph(RESULT_HANDLE_PATH);
	NewR_Hundle = LoadGraph("data/Bg/New.png");
}
void SceneResult::Step()
{
	//ベストスコアを越したとき
	if (m_player_adv_dis >= m_player_max_adv_dis)
	{
		//フラグをtrueにする
		IsNewRecord = true;
	}

	if (Input::IsKeyPush(KEY_INPUT_RETURN))
	{
		g_current_scene_ID = Title;
	}
}
void SceneResult::Draw()
{

	DrawGraph(0, 0, m_bg_handle, true);

	//=============ポイント描画=====================
	Test(MyScoreHundle, m_player_adv_dis, 750, 315);			//今回のスコア
	Test(BestScoreHundle, m_player_max_adv_dis, 750, 450 );		//ベストスコア
	//=============ポイント描画=====================

	//更新フラグがtrueになったら
	if (IsNewRecord == true)
	{
		DrawGraph(0, 80,NewR_Hundle, true);
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "Enterで次のシーンへ");
}

void SceneResult::Test(int Hndl[10], int Score, int X, int Y)//引数(数字画像格納ハンドル, 入れたいスコア, X座標, Y座標)
{
	//ポイント描画
	int DrawScore = Score;

	int count = 0;

	if (DrawScore == 0) {
		DrawRotaGraph(X - count * 35, Y, 2.0f, 0.0f, Hndl[0], true);
	}
	while (DrawScore > 0) {
		int num = DrawScore % 10;	//数字の確定
		DrawScore = DrawScore / 10;
		DrawRotaGraph(X - count * 35, Y, 2.0f, 0.0f, Hndl[num], true);
		count++;	//表示座標の変更
	}
}