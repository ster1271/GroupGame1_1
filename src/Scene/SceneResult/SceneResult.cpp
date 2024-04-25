#include "DxLib.h"
#include "SceneResult.h"
#include "../../Input/Input.h"
#include "../../Common.h"

void SceneResult::Init()
{

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
	DrawString(0, 0, "リザルトシーンです。", GetColor(255, 255, 255), true);
	DrawString(0, 15, "Enterで次のシーンへ", GetColor(255, 255, 255), true);
}