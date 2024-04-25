#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../Draw2D/Player/Player.h"
#include "../../Draw2D/Enemy/Enemy.h"

class ScenePlay :public SceneBace
{
private:
	Player player_info;

public:
	void Init();
	void Step();
	void Draw();
};