#pragma once
#include "../Draw2D/Player/Player.h"
#include "../Draw2D/Enemy/Enemy.h"

void CollisionPlayerAttackToEnemy(Player& player, EnemyInfo& enemy);

bool CollisionPlayerToWall(VECTOR player_pos, VECTOR wall_pos);