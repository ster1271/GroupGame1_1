#include "DxLib.h"
#include "GameCollision.h"
#include "../Collision/Collision.h"
#include "../Draw2D/Wall/Wall.h"

void CollisionPlayerAttackToEnemy(Player& player, EnemyInfo& enemy)
{
	if (!player.GetAttackFlag())
		return;

	if (Collision::IsHitCircleRect(player.GetPos().x + PLAYER_ATTACK_COLLISION_R,
									player.GetPos().y,
									PLAYER_ATTACK_COLLISION_R,
									enemy.GetPos().x,
									enemy.GetPos().y,
									enemy.GetCollisionSize().x,
									enemy.GetCollisionSize().y)) {
		player.SetJumpCount(0);
		player.SetMaxJumpNum(2);

		player.Jump(PLAYER_ATTACK_JUMP_POWER);

		enemy.DeathEnemy();
	}
}

bool CollisionPlayerToWall(VECTOR player_pos, VECTOR wall_pos)
{
	if (Collision::IsHitRect(player_pos.x, player_pos.y, PLAYER_SIZE_X, PLAYER_SIZE_Y,
							wall_pos.x, wall_pos.y, WALL_COLLISIN_SIZE_X, WALL_COLLISIN_SIZE_Y)) {
		return true;
	}
	return false;
}