#include "Bullet.h"

Bullet::Bullet() {
    x_ = y_ = 0;
    speedY_ = -10;
    isActive_ = false;
}

void Bullet::Update() {
    if (isActive_) {
        y_ += speedY_;
        if (y_ < -5) {
            isActive_ = false;
        }
    }
}

void Bullet::Draw() {
    if (isActive_) {
        Novice::DrawEllipse(static_cast<int>(x_), static_cast<int>(y_), 5, 5, 0.0f, 0xFFFF00FF, kFillModeSolid);
    }
}

void Bullet::Fire(float startX, float startY) {
    if (!isActive_) {
        x_ = startX;
        y_ = startY;
        isActive_ = true;
    }
}
