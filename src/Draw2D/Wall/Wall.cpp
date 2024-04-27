#include "DxLib.h"
#include "Wall.h"
#include "../Player/Player.h"
#include "../../Screen/Screen.h"

Wall::Wall()
{

}
Wall::~Wall()
{
	FinHandle();
}

void Wall::Init()
{
	LoadHandle((char*)WALL_HANDLE_PATH, 1, 1, 1, WALL_COLLISIN_SIZE_X, WALL_COLLISIN_SIZE_Y);
	m_pos = { 0.0f,0.0f,0.0f };
}
void Wall::Step(VECTOR player_pos)
{
	m_pos.x += PLAYER_MAX_SPEED * 2 / 3;

	if (m_pos.x - Screen::m_screex_pos_x < 0) {
		m_pos.x = Screen::m_screex_pos_x;
	}
}
void Wall::Draw()
{
	DrawGraph((int)(m_pos.x - Screen::m_screex_pos_x), (int)m_pos.y, m_handle[0], true);
}