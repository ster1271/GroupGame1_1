#pragma once

#include "../Draw2D.h"

constexpr char WALL_HANDLE_PATH[] = { "data/Object/PlaySceneWall.png" };

constexpr int WALL_COLLISIN_SIZE_X = 200;
constexpr int WALL_COLLISIN_SIZE_Y = 720;

class Wall :public Draw2D
{
private:

public:
	Wall();
	~Wall();

	void Init();
	void Step(VECTOR player_pos);
	void Draw();
};