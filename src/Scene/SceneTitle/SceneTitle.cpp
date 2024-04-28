#include "DxLib.h"
#include "../../Input/Input.h"
#include "SceneTitle.h"
#include "../../Common.h"

void SceneTitle::Init()
{
	m_bg_handle = LoadGraph(TITLE_HANDLE_PATH);
}
void SceneTitle::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN))
	{
		g_current_scene_ID = Play;
	}

}
void SceneTitle::Draw()
{
	DrawGraph(0, 0, m_bg_handle, true);

	DrawString(0, 0, "タイトルシーンです。", GetColor(255, 255, 255), true);
	DrawString(0, 15, "Enterで次のシーンへ", GetColor(255, 255, 255), true);
}