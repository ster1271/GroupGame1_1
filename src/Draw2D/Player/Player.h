#pragma once
#include "../Draw2D.h"
#include "../../Animation/Animation.h"

//ハンドルパス
constexpr char PLAYER_HANDLE_PATH[] = { "data/Player/Player.png" };
constexpr char PLAYER_ATTACK_HANDLE_PATH[]= { "data/Player/Player_Attack.png" };

//プレイヤーの初期座標
constexpr VECTOR PLAYER_DEFAULT_POS = { 300.0f,360.0f,0.0f };
//連続ジャンプの初期最大数
constexpr int MAX_JUMP_NUM = 1;

//ジャンプ時の力
constexpr float PLAYER_JUMP_POWER = GRAVITY_POWER * 30;
constexpr float PLAYER_ATTACK_JUMP_POWER = PLAYER_JUMP_POWER / 2;
//横移動の加速度
constexpr float PLAYER_MOVE_SPEED = 5.0f;
//横移動の最大速度
constexpr float PLAYER_MAX_SPEED = PLAYER_MOVE_SPEED + 5.0f;

//プレイヤーのサイズ
constexpr int PLAYER_SIZE_X = 60;
constexpr int PLAYER_SIZE_Y = 60;
//攻撃の当たり判定のサイズ(半径)
constexpr int PLAYER_ATTACK_COLLISION_R = 60;
//攻撃の持続時間（秒数 * フレーム数）
constexpr int PLAYER_ATTACK_TIME = (int)(0.1 * 60);

class Player :public Draw2D
{
private:
	bool m_stat_flag;

	int m_player_attack_handle[6];	//プレイヤーの攻撃の画像ハンドル

	int m_jump_count;		//ジャンプした回数
	int m_max_jump_num;		//ジャンプできる最大の数

	VECTOR m_move_power;	// 1フレームで移動する距離

	bool m_attack_flag;		//攻撃フラグ
	bool m_pre_attack_flag;		//攻撃フラグ
	int m_count_attack_time;

	Animation m_player_animation[2];

	enum AnimeType
	{
		Normal,
		Up,
		Down,
	};

public:
	Player();
	~Player();

	void Init();
	void Step();
	void Draw();
	void Fin();

	bool Jump(float jump_power = PLAYER_JUMP_POWER);
	void MoveX();

	void Attack();

	void SetJumpCount(int num) { m_jump_count = num; }
	void SetMaxJumpNum(int num) { m_max_jump_num = num; }

	bool GetStartFlag() { return m_stat_flag; }
	bool GetAttackFlag() { return m_attack_flag; }
};