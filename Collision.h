#pragma once
#include "Player.h"
#include "Enemy.h"

class Collision {
public:

    static void CheckBulletEnemyCollision(Player& player, Enemy& enemy);
    static void CheckEnemyCollision(Enemy& enemyA, Enemy& enemyB);
    static void CheckPlayerEnemyCollision(Player& player, Enemy& enemy); // プレイヤーと敵の衝突判定

};
