#pragma once
#include "../SceneBace/SceneBace.h"

constexpr char TITLE_HANDLE_PATH[] = { "data/Bg/Bg_Title.png" };

class SceneTitle :public SceneBace
{
private:
	int m_bg_handle;

public:
	void Init();
	void Step();
	void Draw();
};