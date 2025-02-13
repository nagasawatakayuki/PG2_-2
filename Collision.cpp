#include "Collision.h"
#include <cmath>

// 弾丸と敵の衝突判定
void Collision::CheckBulletEnemyCollision(Player& player, Enemy& enemy) {
    for (int i = 0; i < 10; i++) { // プレイヤーの弾丸を走査
        if (player.IsBulletActive(i)) { // 弾丸がアクティブなら
            float distX = player.GetBulletX(i) - enemy.GetPosX(); // X座標差
            float distY = player.GetBulletY(i) - enemy.GetPosY(); // Y座標差
            float distSq = distX * distX + distY * distY;         // 距離の二乗
            int combinedRadius = 5 + enemy.GetRadius();          // 弾と敵の半径合計

            if (distSq <= combinedRadius * combinedRadius) {     // 衝突判定
                player.SetBulletActive(i, false);                // 弾丸を非アクティブにする
                if (enemy.TakeDamage()) {                        // 敵が倒れた場合
                    enemy.SetPosX(static_cast<float>(rand() % 300 + 500)); // ランダムな位置にリスポーン
                    enemy.SetPosY(0.0f);                         // 上端に配置
                    enemy.SetActive(true);                       // 再びアクティブにする
                }
            }
        }
    }
}

// 自機と敵機の衝突判定
void Collision::CheckPlayerEnemyCollision(Player& player, Enemy& enemy) {
    // 自機と敵機の距離を計算
    float distX = player.GetX() - enemy.GetPosX();
    float distY = player.GetY() - enemy.GetPosY();
    float distSq = distX * distX + distY * distY;

    // 自機と敵機の半径の合計
    int combinedRadius = static_cast<int>(player.GetRadius()) + enemy.GetRadius();

    // 衝突判定
    if (distSq <= combinedRadius * combinedRadius) {
        // 自機を初期位置に戻す
        player.ResetPosition();
    }
}

// 敵同士の衝突判定
void Collision::CheckEnemyCollision(Enemy& enemyA, Enemy& enemyB) {
    // 敵同士の距離を計算
    float distX = enemyA.GetPosX() - enemyB.GetPosX();
    float distY = enemyA.GetPosY() - enemyB.GetPosY();
    float distSq = distX * distX + distY * distY;

    // 半径の合計を計算
    int radiusSum = enemyA.GetRadius() + enemyB.GetRadius();

    // 衝突している場合
    if (distSq <= radiusSum * radiusSum) {
        // 敵の速度を反転
        enemyA.SetSpeedX(-enemyA.GetSpeedX());
        enemyB.SetSpeedX(-enemyB.GetSpeedX());
    }
}