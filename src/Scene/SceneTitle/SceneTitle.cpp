#include "DxLib.h"
#include "../../Input/Input.h"
#include "SceneTitle.h"
#include "../../Common.h"

void SceneTitle::Init()
{
	SelectY = 400;

	m_bg_handle = LoadGraph(TITLE_HANDLE_PATH);
	SelectHandl = LoadGraph("data/Bg/Select.png");

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

	DrawRotaGraph(420, SelectY, 0.3f, 0.0f, SelectHandl, true, false, false);
}