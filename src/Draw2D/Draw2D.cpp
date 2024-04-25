#include "Draw2D.h"

Draw2D::Draw2D()
{
	m_handle = nullptr;

	m_pos = { 0 };
	m_isUse = 0;
	m_coliision_size = { 0 };
	m_coliision_size_r = 0;
}
Draw2D::~Draw2D()
{
	if (m_handle != nullptr)
		FinHandle();
}

void Draw2D::LoadHandle(char* handle_path,
	int ANum,
	int Xnum,
	int Ynum,
	int Xsize,
	int Ysize)
{
	m_handle = new int[ANum];

	LoadDivGraph(handle_path,
		ANum,
		Xnum,
		Ynum,
		Xsize,
		Ysize,
		m_handle,
		true);
}

void Draw2D::FinHandle()
{
	delete m_handle;
}