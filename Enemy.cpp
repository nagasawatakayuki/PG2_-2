#include "Enemy.h"
#include <cmath>
#include <cstdlib>

Enemy::Enemy(float startX, float startY, float speedX, float speedY)
    : x_(startX), y_(startY), speedX_(speedX), speedY_(speedY), health_(3), isActive_(true) {
}

void Enemy::Update(float playerX, float otherEnemyX) {
    // プレイヤーに向かう追従の調整
    float followSpeed = 0.05f; // 滑らかな追従用
    x_ += (playerX - x_) * followSpeed;

    // サイン波による蛇行運動
    static float time = 0.0f; // 全体で一つの時間を使う
    time += 0.1f;
    y_ += speedY_;
    x_ += std::sin(time) * 5.0f;

    // 敵同士の衝突回避（距離が近い場合、分離）
    float minDistance = 32.0f; // 衝突を避ける距離（半径の合計）
    float distX = x_ - otherEnemyX;
    if (std::abs(distX) < minDistance) {
        if (distX > 0) {
            x_ += (minDistance - std::abs(distX)) * 0.5f;
        } else {
            x_ -= (minDistance - std::abs(distX)) * 0.5f;
        }
    }

    // 画面端で速度を反転
    if (x_ < 16 || x_ > 1280 - 16) { // 敵の半径分を考慮
        speedX_ = -speedX_;
    }
}

void Enemy::Draw() {
    // 敵本体を描画
    Novice::DrawEllipse(static_cast<int>(x_), static_cast<int>(y_), 16, 16, 0.0f, RED, kFillModeSolid);
}

bool Enemy::TakeDamage() {
    health_--;
    if (health_ <= 0) {
        isActive_ = false;
        return true;
    }
    return false;
}
