#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"

const char kWindowTitle[] = "PG2_評価課題2";

// シーン定義
enum Scene {
    TITLE,
    GAME,
    GAME_OVER
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Novice::Initialize(kWindowTitle, 1280, 720);

    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    Player player;
    Enemy enemyA(100.0f, 100.0f, 2.0f, 1.0f);
    Enemy enemyB(300.0f, 100.0f, -2.0f, 1.0f);

    Scene currentScene = TITLE; // 初期シーンはタイトル

    while (Novice::ProcessMessage() == 0) {
        Novice::BeginFrame();
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        // シーンごとの処理
        switch (currentScene) {
        case TITLE: {
            // タイトル画面の描画
            Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x000000FF, kFillModeSolid); // 背景
            Novice::ScreenPrintf(610, 350, "Title");
            Novice::ScreenPrintf(550,550,"Press Space to Start");
            if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
                currentScene = GAME; // Enterキーでゲーム開始
            }
            break;
        }
        case GAME: {
            // プレイヤーの更新
            player.Update(keys);
            player.Shoot(keys);

            // 敵の更新（お互いの位置を渡して衝突を回避）
            enemyA.Update(player.GetX(), enemyB.GetPosX());
            enemyB.Update(player.GetX(), enemyA.GetPosX());

            // 衝突判定
            Collision::CheckBulletEnemyCollision(player, enemyA);
            Collision::CheckBulletEnemyCollision(player, enemyB);
            Collision::CheckPlayerEnemyCollision(player, enemyA);
            Collision::CheckPlayerEnemyCollision(player, enemyB);

            // 敵が全滅したらゲームオーバーに
            if (!enemyA.IsActive() && !enemyB.IsActive()) {
                currentScene = GAME_OVER;
            }

            // 描画
            Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x000000FF, kFillModeSolid); // 背景
            player.Draw();
            enemyA.Draw();
            enemyB.Draw();
            break;
        }
        case GAME_OVER: {
            // ゲームオーバー画面の描画
            //Novice::Draw("GAME OVER", 580, 320, 0xFFFFFFFF);
            //Novice::DrawText("Press Enter to Restart", 540, 400, 0xFFFFFFFF);
            if (keys[DIK_R] && !preKeys[DIK_R]) {
                // 再スタート処理
                currentScene = GAME;
                enemyA = Enemy(100.0f, 100.0f, 2.0f, 1.0f); // 敵を再生成
                enemyB = Enemy(300.0f, 100.0f, -2.0f, 1.0f);
            }
            break;
        }
        }

        Novice::EndFrame();

        if (keys[DIK_ESCAPE] && !preKeys[DIK_ESCAPE]) {
            break;
        }
    }

    Novice::Finalize();
    return 0;
}
