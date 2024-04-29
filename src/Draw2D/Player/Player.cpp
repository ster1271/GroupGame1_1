#include "Player.h"
#include "../../Input/Input.h"
#include "../../Screen/Screen.h"
#include "../../Sound/Sound.h"

Player::Player()
{
	for (int i = 0; i < 6; i++)
		m_player_attack_handle[i] = 0;

	m_jump_count = 0;
	m_max_jump_num = 0;

	m_move_power = { 0 };

	m_attack_flag = 0;
	m_pre_attack_flag = 0;
	m_count_attack_time = 0;

	m_stat_flag = 0;

	m_player_animation[0].Init();
	m_player_animation[1].Init();
}
Player::~Player()
{
	Draw2D::~Draw2D();
}

void Player::Init()
{
	LoadHandle((char*)PLAYER_HANDLE_PATH,
					5, 3, 2, 60, 60);

	for (int i = 0; i < 6; i++)
		LoadDivGraph(PLAYER_ATTACK_HANDLE_PATH, 6, 3, 2, 120, 120, m_player_attack_handle);

	m_pos = PLAYER_DEFAULT_POS;

	m_jump_count = 0;		//ジャンプした回数
	m_max_jump_num = MAX_JUMP_NUM;	//ジャンプできる最大の数

	m_attack_flag = false;
	m_pre_attack_flag = m_attack_flag;
	m_count_attack_time = 0;

	m_stat_flag = false;

	m_player_animation[0].Init();
	m_player_animation[1].Init();
}
void Player::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_SPACE)) {
		m_stat_flag = true;
		if (Jump())
			Sound::PlaySE(Jump_SE);
	}
	if (m_stat_flag) {
		MoveX();
		Attack();

		m_move_power.y += GRAVITY_POWER;
		if (m_move_power.y >= MAX_FILLING_SPEED)
			m_move_power.y = MAX_FILLING_SPEED;

		m_pos.y += m_move_power.y;

		//アニメーション
		if (m_move_power.y > 0) {
			m_player_animation[0].SetCurrentAnimationIndex(Up);
		}
		else if (m_move_power.y < 0) {
			m_player_animation[0].SetCurrentAnimationIndex(Down);
		}
		else {
			m_player_animation[0].SetCurrentAnimationIndex(Normal);
		}
	}
}
void Player::Draw()
{
	if (m_attack_flag) {
		DrawGraph((int)(m_pos.x - Screen::m_screex_pos_x), (int)(m_pos.y - PLAYER_ATTACK_COLLISION_R / 2),
			m_player_attack_handle[m_player_animation[1].GetCurrentAnimeIndex()], true);

		/*DrawCircle((int)(m_pos.x - Screen::m_screex_pos_x + PLAYER_SIZE_X),
					(int)(m_pos.y + PLAYER_SIZE_Y / 2),
					PLAYER_ATTACK_COLLISION_R,
					GetColor(255, 255, 255), true);*/
	}
	DrawGraph((int)(m_pos.x - Screen::m_screex_pos_x), (int)m_pos.y, m_handle[m_player_animation[0].GetCurrentAnimeIndex()], true);
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

	if (m_pos.x < Screen::m_screex_pos_x)
		m_pos.x = Screen::m_screex_pos_x;
}

bool Player::Jump(float jump_power)
{
	//最大連続ジャンプ数分既にジャンプしている場合は処理を行わない
	if (m_jump_count >= m_max_jump_num)
		return false;

	m_jump_count++;
	m_move_power.y = -jump_power;

	return true;
}

void Player::Attack()
{
	m_pre_attack_flag = m_attack_flag;

	if (Input::IsKeyPush(KEY_INPUT_J) && !m_pre_attack_flag) {
		m_attack_flag = true;
		m_player_animation[1].SetCurrentAnimationIndex(0);
		Sound::PlaySE(AttackEnpty_SE);
	}

	if (m_attack_flag) {

		m_player_animation[1].SetCurrentAnimationIndex(m_player_animation[1].GetCurrentAnimeIndex() + 1);

		if (m_count_attack_time >= PLAYER_ATTACK_TIME) {
			m_count_attack_time = 0;
			m_attack_flag = false;
			return;
		}

		m_count_attack_time++;
	}
}