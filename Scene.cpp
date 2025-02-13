#include "Scene.h"
#include "Novice.h"

Scene::Scene() {
    currentScene_ = TITLE;
    isKeyPressed_ = false;
}

void Scene::Update(char* keys, char* preKeys) {
    switch (currentScene_) {
    case TITLE:
        if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
            isKeyPressed_ = true;
        }
        if (isKeyPressed_) {
            currentScene_ = GAME;
            isKeyPressed_ = false;
        }
        break;

    case GAME:
        if (!preKeys[DIK_T] && keys[DIK_T]) {
            isKeyPressed_ = true;
        }
        if (isKeyPressed_) {
            currentScene_ = TITLE;
            isKeyPressed_ = false;
        }
        break;
    }
}

void Scene::Draw() {
    switch (currentScene_) {
    case TITLE:
        break;
    case GAME:
        break;
    }
}
