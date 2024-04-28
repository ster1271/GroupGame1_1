#pragma once
#include "../Draw2D.h"

constexpr char BACKGROUND_HANDLE_PATH[] = { "data/Object/BackGround.png" };

class BackGround :public Draw2D
{
private:
	VECTOR m_pos[2];

public:
	BackGround();
	~BackGround();

	void Init();
	void Step();
	void Draw();
};