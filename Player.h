#pragma once
#include "Bullet.h"

class Player {
public:
    Player();

    void Update(char* keys);
    void Draw();
    void Shoot(char* keys);

    bool IsBulletActive(int index) const { return bullets_[index].IsActive(); }
    void SetBulletActive(int index, bool active) { bullets_[index].SetActive(active); }
    float GetBulletX(int index) const { return bullets_[index].GetX(); }
    float GetBulletY(int index) const { return bullets_[index].GetY(); }

    float GetX() const { return x_; }
    float GetY() const { return y_; }
    float GetRadius() const { return radius_; }
    void ResetPosition(); // 初期位置に戻す関数

private:
    float x_, y_;             // 自機の座標
    float radius_;            // 自機の半径
    int speed_;               // 自機の移動速度
    static const int bulletCount_ = 30; // 弾丸の最大数
    Bullet bullets_[bulletCount_];
    int shootInterval_;       // 発射間隔（フレーム数）
    int shootTimer_;          // 発射までのタイマー

    float initialX_;          // 初期位置X
    float initialY_;          // 初期位置Y
};
