#pragma once
#include "Kamataengine.h"

class NumberCount {
public:
	~NumberCount();

	void Initialize();

	void Update();

	void Draw();

private:
	KamataEngine::Vector2 size = {32.0f, 64.0f};

	uint32_t numberTextureHandle_ = 0;

	KamataEngine::Sprite* numberSprite_[5];
};
