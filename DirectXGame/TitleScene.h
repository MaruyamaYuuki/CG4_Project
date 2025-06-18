#pragma once
#include "KamataEngine.h"

class TitleScene {
public:
	TitleScene();

	~TitleScene();

	void Initialize();

	void Update();

	void Draw();

	bool IsFinished() { return finished_; }

private:
	KamataEngine::Input* input_ = nullptr;

	KamataEngine::WorldTransform worldTrabsform_;

	KamataEngine::Sprite* titleSprite_ = nullptr;
	KamataEngine::Sprite* startGuideSprite_ = nullptr;

	uint32_t titleTexture_ = 0;
	uint32_t startGuideTexture_ = 0;

	bool finished_ = false;

	float waveTime_ = 0.0f;
	float blinkTime_ = 0.0f;
};
