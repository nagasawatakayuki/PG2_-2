#pragma once
#include "Novice.h"

class Enemy {
public:
    Enemy(float startX, float startY, float speedX, float speedY);

    void Update(float playerX, float otherEnemyX); // 他の敵の座標も渡す
    void Draw();
    bool TakeDamage();

    bool IsActive() const { return isActive_; }
    void SetActive(bool active) { isActive_ = active; }

    float GetPosX() const { return x_; }
    float GetPosY() const { return y_; }
    void SetPosX(float x) { x_ = x; }
    void SetPosY(float y) { y_ = y; }

    float GetSpeedX() const { return speedX_; }
    float GetSpeedY() const { return speedY_; }
    void SetSpeedX(float speedX) { speedX_ = speedX; }
    void SetSpeedY(float speedY) { speedY_ = speedY; }

    int GetRadius() const { return 16; }

private:
    float x_, y_;            // 現在の座標
    float speedX_, speedY_;  // 移動速度
    int health_;             // 体力
    bool isActive_;          // アクティブ状態
};
