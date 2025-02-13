#pragma once
#include "Novice.h"

class Bullet {
public:
    Bullet();

    void Update();
    void Draw();
    void Fire(float startX, float startY);

    bool IsActive() const { return isActive_; }
    void SetActive(bool active) { isActive_ = active; }
    float GetX() const { return x_; }
    float GetY() const { return y_; }

private:
    float x_, y_;
    float speedY_;
    bool isActive_;
};
