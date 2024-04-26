#pragma once

class Screen
{
public:
	static float m_screex_pos_x;
	static float m_screex_pos_y;

	static float m_reference_point;

	static void Init();
	static void Step(VECTOR pos);
};