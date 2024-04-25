#include "Player.h"
#include "../../Input/Input.h"

Player::Player()
{
	m_jump_count = 0;
	m_max_jump_num = 0;

	m_move_power = { 0 };
}
Player::~Player()
{
	Draw2D::~Draw2D();
}

void Player::Init()
{
	LoadHandle((char*)PLAYER_HANDLE_PATH,
		1, 1, 1, 60, 60);
	m_pos = PLAYER_DEFAULT_POS;

	m_jump_count = 0;		//ジャンプした回数
	m_max_jump_num = MAX_JUMP_NUM;	//ジャンプできる最大の数
}
void Player::Step()
{
	Jump();
	MoveX();

	m_move_power.y += GRAVITY_POWER;
	if (m_move_power.y >= MAX_FILLING_SPEED)
		m_move_power.y = MAX_FILLING_SPEED;

	m_pos.y += m_move_power.y;
}
void Player::Draw()
{
	DrawGraph((int)m_pos.x, (int)m_pos.y, m_handle[0], true);
}
void Player::Fin()
{
	FinHandle();
}

void Player::MoveX()
{
	if (Input::IsKeyDown(KEY_INPUT_A)) {
		m_move_power.x -= PLAYER_MOVE_SPEED;
	}
	if (Input::IsKeyDown(KEY_INPUT_D)){
		m_move_power.x += PLAYER_MOVE_SPEED;
	}

	m_pos.x += m_move_power.x;
	if (m_move_power.x < 0) {
		m_move_power.x += PLAYER_MOVE_SPEED - 3.0f;
		if (m_move_power.x < -PLAYER_MAX_SPEED)
			m_move_power.x = -PLAYER_MAX_SPEED;
		if (m_move_power.x > 0)
			m_move_power.x = 0;
	}
	else if (m_move_power.x > 0) {
		m_move_power.x -= PLAYER_MOVE_SPEED - 3.0f;
		if (m_move_power.x > PLAYER_MAX_SPEED)
			m_move_power.x = PLAYER_MAX_SPEED;
		if (m_move_power.x < 0)
			m_move_power.x = 0;
	}
}

void Player::Jump()
{
	//最大連続ジャンプ数分既にジャンプしている場合は処理を行わない
	/*if (m_jump_count >= m_max_jump_num)
		return;*/

	if (Input::IsKeyPush(KEY_INPUT_SPACE)) {
		m_jump_count++;
		m_move_power.y = -PLAYER_JUMP_POWER;
	}
}