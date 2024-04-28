#include "DxLib.h"
#include "SceneResult.h"
#include "../../Input/Input.h"
#include "../../Common.h"

void SceneResult::Init()
{
	numberHundle[10] = { 0 };
	LoadDivGraph("data/Number/number16x32_03.png", 10, 10, 1, 16, 32, numberHundle);

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

	//ポイント描画
	MyScore = m_player_adv_dis;

	int count = 0;

	if (MyScore == 0) {
		DrawRotaGraph(640 - count * 35, 120, 2.0f, 0.0f, numberHundle[0], true);
	}
	while (MyScore > 0) {
		int num = MyScore % 10;	//数字の確定
		MyScore = MyScore / 10;
		DrawRotaGraph(640 - count * 35, 120, 2.0f, 0.0f, numberHundle[num], true);
		count++;	//表示座標の変更
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "リザルトシーンです。");
	DrawFormatString(0, 15, GetColor(255, 255, 255), "Enterで次のシーンへ");
	DrawFormatString(0, 45, GetColor(255, 255, 255), "今までの最大移動距離( %d )", m_player_max_adv_dis);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "今回の移動距離( %d )", m_player_adv_dis);
}