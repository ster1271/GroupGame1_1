#include "DxLib.h"
#include "../../Input/Input.h"
#include "SceneTitle.h"
#include "../../Common.h"

void SceneTitle::Init()
{
	TitleHandl01 = LoadGraph(TITLE_HANDLE_PATH01);
	TitleHandl02 = LoadGraph(TITLE_HANDLE_PATH02);
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
	//DrawGraph(0, 0, TitleHandl01, true);
	DrawGraph(0, 0, TitleHandl02, true);

}