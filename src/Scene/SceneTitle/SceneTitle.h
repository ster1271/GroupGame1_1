#pragma once
#include "../SceneBace/SceneBace.h"

constexpr char TITLE_HANDLE_PATH[] = { "data/Bg/Bg_Title.png" };

class SceneTitle :public SceneBace
{
private:
	int m_bg_handle;
	int TitleHandl;
	int SelectHandl;

	int SelectY;

public:
	void Init();
	void Step();
	void Draw();
};