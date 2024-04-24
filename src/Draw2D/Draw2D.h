#pragma once
#include "DxLib.h"

class Draw2D
{
protected:
	VECTOR m_pos;
	bool m_isUse;
	VECTOR m_coliision_size;
	float m_coliision_size_r;
public:

	VECTOR GetPos() { return m_pos; }
	void SetPos(VECTOR pos) { m_pos = pos; }

	bool GetIsUse() { return m_isUse; }
	void SetIsUse(bool flag) { m_isUse = flag; }

	VECTOR GetCollisionSize() { return m_coliision_size; }
	float GetCollisionSizeR() { return m_coliision_size_r; }

	void SetCollisionSize(VECTOR size) { m_coliision_size = size; }
	void SetCollisionSizeR(float size) { m_coliision_size_r = size; }
};