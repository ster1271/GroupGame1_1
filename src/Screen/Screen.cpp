#include "DxLib.h"
#include "../Common.h"
#include "Screen.h"

float Screen::m_screex_pos_x;
float Screen::m_screex_pos_y;
float Screen::m_reference_point;

void Screen::Init()
{
	m_screex_pos_x = 0.0f;
	m_screex_pos_y = 0.0f;
	m_reference_point = 100.0f;
}
void Screen::Step(VECTOR pos)
{
	if (pos.x - m_screex_pos_x > SCREEN_SIZE_X / 2) {
		m_screex_pos_x += (pos.x - m_screex_pos_x) - (SCREEN_SIZE_X / 2);
	}
}