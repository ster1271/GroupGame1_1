#include "DxLib.h"
#include "../../Input/Input.h"
#include "SceneTitle.h"
#include "../../Common.h"

void SceneTitle::Init()
{

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
	DrawString(0, 0, "�^�C�g���V�[���ł��B", GetColor(255, 255, 255), true);
	DrawString(0, 15, "Enter�Ŏ��̃V�[����", GetColor(255, 255, 255), true);
}