#include "Player.h"
#include "Novice.h"

Player::Player()
    : x_(640.0f), y_(560.0f), radius_(20.0f), speed_(5), shootInterval_(10), shootTimer_(0),
    initialX_(640.0f), initialY_(560.0f) { // 初期位置を設定
}

void Player::ResetPosition() {
    x_ = initialX_;
    y_ = initialY_;
}

void Player::Update(char* keys) {
    // 移動処理
    if (keys[DIK_W]) { y_ -= speed_; }
    if (keys[DIK_S]) { y_ += speed_; }
    if (keys[DIK_A]) { x_ -= speed_; }
    if (keys[DIK_D]) { x_ += speed_; }

    // タイマーを更新
    if (shootTimer_ > 0) {
        shootTimer_--;
    }

    // 弾丸の更新
    for (int i = 0; i < bulletCount_; i++) {
        bullets_[i].Update();
    }
}

void Player::Draw() {
    // プレイヤー本体を描画
    Novice::DrawEllipse(static_cast<int>(x_), static_cast<int>(y_), static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, 0xFFFFFFFF, kFillModeSolid);

    // 弾丸を描画
    for (int i = 0; i < bulletCount_; i++) {
        bullets_[i].Draw();
    }
}

void Player::Shoot(char* keys) {
    if (keys[DIK_SPACE] && shootTimer_ == 0) { // タイマーが0なら発射可能
        for (int i = 0; i < bulletCount_; i++) {
            if (!bullets_[i].IsActive()) {
                bullets_[i].Fire(x_, y_ - radius_); // 弾丸を発射
                shootTimer_ = shootInterval_;      // タイマーをリセット
                break;
            }
        }
    }
}
