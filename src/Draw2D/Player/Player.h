#pragma once
#include "../Draw2D.h"

//ハンドルパス
constexpr char PLAYER_HANDLE_PATH[64] = { "data/Player/Player.png" };
//プレイヤーの初期座標
constexpr VECTOR PLAYER_DEFAULT_POS = { 300.0f,0.0f,0.0f };
//連続ジャンプの初期最大数
constexpr int MAX_JUMP_NUM = 1;

constexpr float PLAYER_JUMP_POWER = 27.0f;

constexpr float PLAYER_MOVE_SPEED = 5.0f;
constexpr float PLAYER_MAX_SPEED = PLAYER_MOVE_SPEED + 5.0f;

class Player :public Draw2D
{
private:
	int m_jump_count;		//ジャンプした回数
	int m_max_jump_num;	//ジャンプできる最大の数

	VECTOR m_move_power;

public:
	Player();
	~Player();

	void Init();
	void Step();
	void Draw();
	void Fin();

	void Jump();
	void MoveX();
};