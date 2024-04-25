#include "DxLib.h"
#include "ScenePlay.h"

void ScenePlay::Init()
{
	player_info.Init();
}
void ScenePlay::Step()
{
	player_info.Step();
}
void ScenePlay::Draw()
{
	player_info.Draw();
}