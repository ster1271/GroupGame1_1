#pragma once

enum FontType
{
	HGP�n�p�p�߯�ߑ�,

	FontTypeMaxNum
};

constexpr char FONT_HANDLE_PAYH[FontTypeMaxNum][64] = {
	{"HGP�n�p�p�߯�ߑ�"},
};
constexpr int FONT_SIZE[FontTypeMaxNum] = { 40 };
constexpr int FONT_THICK[FontTypeMaxNum] = { 3 };

class Font
{
public:
	static int m_font_handle[FontTypeMaxNum];

	static void LoadFontHandle();
	static void DeleteFontHandle();

	static int GetFontHandle(int type_index) { return m_font_handle[type_index]; }
};

/*
DrawFormatStringToHandle
GetDrawFormatStringWidthToHandle
*/