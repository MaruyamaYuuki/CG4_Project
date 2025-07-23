#pragma once
#include "KamataEngine.h"

class GraphDisplay {
public:
	~GraphDisplay();

	void initialize(KamataEngine::Input* input);

	void Update();

	void Draw();

private:
	KamataEngine::Input* input_ = nullptr;

	// テクスチャハンドル
	uint32_t redGraphTextureHandle_ = 0;
	uint32_t greenGraphTexturehandle_ = 0;

	// スプライト
	KamataEngine::Sprite* redGraphSprite_ = nullptr;
	KamataEngine::Sprite* greenGraphSprite_ = nullptr;

	float maxXSize = 300.0f;

	bool isStart_ = false;
};
