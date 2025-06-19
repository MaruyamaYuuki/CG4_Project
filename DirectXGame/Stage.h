#pragma once
#include "KamataEngine.h"

class Stage {
public:
	Stage();

	~Stage();

	void Initialise();

	void Update();

	void Draw();


private:
	uint32_t iwayamaTexture_ = 0;
	uint32_t iwayamaRvTexture_ = 0;

	KamataEngine::Sprite* iwayamaSprite_ = nullptr;
	KamataEngine::Sprite* iwayamaRvSprite_ = nullptr;

	float moveSpeed_ = 0.05f;

	float xPos[2] = {{0.0f}, {1280.0f}};
};
