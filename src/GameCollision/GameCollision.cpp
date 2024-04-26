#include "DxLib.h"
#include "GameCollision.h"
#include "../Collision/Collision.h"

void CollisionPlayerAttackToEnemy(Player& player, EnemyInfo& enemy)
{
	if (!player.GetAttackFlag())
		return;

	if (Collision::IsHitCircleRect(player.GetPos().x,
									player.GetPos().y,
									PLAYER_ATTACK_COLLISION_R,
									enemy.GetPos().x,
									enemy.GetPos().y,
									enemy.GetCollisionSize().x,
									enemy.GetCollisionSize().y)) {
		player.SetJumpCount(0);
		player.SetMaxJumpNum(2);

		player.Jump(PLAYER_ATTACK_JUMP_POWER);
	}
}