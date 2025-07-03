#pragma once
#include "KamataEngine.h"

class Player {
public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Input* input);

	void Update();

	void Draw(KamataEngine::Camera &camera);

private:
	KamataEngine::Model* model_ = nullptr;

	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Input* input_ = nullptr;

	KamataEngine::Vector2 velocity_ = {0.5f, 0.5f};
};
