#pragma once
#include "../SceneBace/SceneBace.h"

constexpr char TITLE_HANDLE_PATH01[] = { "data/Bg/Bg_Title01.png" };
constexpr char TITLE_HANDLE_PATH02[] = { "data/Bg/Bg_Title02.png" };

class SceneTitle :public SceneBace
{
private:
	int TitleHandl01;
	int TitleHandl02;

public:
	void Init();
	void Step();
	void Draw();
};