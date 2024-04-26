#pragma once
#include "../Draw2D.h"

//�n���h���p�X
constexpr char PLAYER_HANDLE_PATH[64] = { "data/Player/Player.png" };
//�v���C���[�̏������W
constexpr VECTOR PLAYER_DEFAULT_POS = { 100.0f,360.0f,0.0f };
//�A���W�����v�̏����ő吔
constexpr int MAX_JUMP_NUM = 1;

//�W�����v���̗�
constexpr float PLAYER_JUMP_POWER = GRAVITY_POWER * 30;
constexpr float PLAYER_ATTACK_JUMP_POWER = PLAYER_JUMP_POWER / 2;
//���ړ��̉����x
constexpr float PLAYER_MOVE_SPEED = 5.0f;
//���ړ��̍ő呬�x
constexpr float PLAYER_MAX_SPEED = PLAYER_MOVE_SPEED + 5.0f;

//�v���C���[�̃T�C�Y
constexpr int PLAYER_SIZE_X = 60;
constexpr int PLAYER_SIZE_Y = 60;
//�U���̓����蔻��̃T�C�Y(���a)
constexpr int PLAYER_ATTACK_COLLISION_R = 60;
//�U���̎������ԁi�b�� * �t���[�����j
constexpr int PLAYER_ATTACK_TIME = (int)(0.5 * 60);

class Player :public Draw2D
{
private:
	bool m_stat_flag;

	int m_jump_count;		//�W�����v������
	int m_max_jump_num;		//�W�����v�ł���ő�̐�

	VECTOR m_move_power;	// 1�t���[���ňړ����鋗��

	bool m_attack_flag;		//�U���t���O
	int m_count_attack_time;

public:
	Player();
	~Player();

	void Init();
	void Step();
	void Draw();
	void Fin();

	void Jump(float jump_power = PLAYER_JUMP_POWER);
	void MoveX();

	void Attack();

	void SetJumpCount(int num) { m_jump_count = num; }
	void SetMaxJumpNum(int num) { m_max_jump_num = num; }

	bool GetAttackFlag() { return m_attack_flag; }
};