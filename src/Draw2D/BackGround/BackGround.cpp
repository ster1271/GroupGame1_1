#include "DxLib.h"
#include "../../Common.h"
#include "BackGround.h"
#include "../../Screen/Screen.h"

BackGround::BackGround()
{
	m_pos[0] = { 0,0,0 };
	m_pos[1] = { 0,0,0 };
}
BackGround::~BackGround()
{
	FinHandle();
}

void BackGround::Init()
{
	LoadHandle((char*)BACKGROUND_HANDLE_PATH, 1, 1, 1, SCREEN_SIZE_X, SCREEN_SIZE_Y);

	m_pos[0] = { 0.0f,0.0f,0.0f };
	m_pos[1] = { (float)SCREEN_SIZE_X,0.0f,0.0f };
}
void BackGround::Step()
{
	for (int i = 0; i < 2; i++) {
		if (Screen::m_screex_pos_x - m_pos[i].x >= SCREEN_SIZE_X)
			m_pos[i].x += SCREEN_SIZE_X * 2;
	}
}
void BackGround::Draw()
{
	for (int i = 0; i < 2; i++) {
		DrawGraph((int)m_pos[i].x - Screen::m_screex_pos_x, (int)m_pos[i].y, m_handle[0], true);
	}

	//デバッグ用
	/*DrawBox((int)(m_pos[0].x - Screen::m_screex_pos_x), (int)m_pos[0].y,
		(int)(m_pos[0].x + SCREEN_SIZE_X - Screen::m_screex_pos_x), (int)(m_pos[0].y + SCREEN_SIZE_Y),
		GetColor(0, 200, 255), true);
	DrawBox((int)(m_pos[1].x - Screen::m_screex_pos_x), (int)m_pos[1].y,
		(int)(m_pos[1].x + SCREEN_SIZE_X - Screen::m_screex_pos_x), (int)(m_pos[1].y + SCREEN_SIZE_Y),
		GetColor(255, 0, 120), true);*/
}