#include "DxLib.h"
#include "SceneResult.h"
#include "../../Input/Input.h"
#include "../../Common.h"

void SceneResult::Init()
{
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
	DrawFormatString(0, 0, GetColor(255, 255, 255), "リザルトシーンです。");
	DrawFormatString(0, 15, GetColor(255, 255, 255), "Enterで次のシーンへ");
	DrawFormatString(0, 45, GetColor(255, 255, 255), "今までの最大移動距離( %d )", m_player_max_adv_dis);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "今回の移動距離( %d )", m_player_adv_dis);
}