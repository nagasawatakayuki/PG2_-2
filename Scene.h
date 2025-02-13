#pragma once

enum SceneType {
    TITLE,
    GAME
};

class Scene {
public:
    Scene();

    void Update(char* keys, char* preKeys);
    void Draw();

    SceneType GetCurrentScene() const { return currentScene_; }
    void SetCurrentScene(SceneType scene) { currentScene_ = scene; }

private:
    SceneType currentScene_;
    bool isKeyPressed_;
};
