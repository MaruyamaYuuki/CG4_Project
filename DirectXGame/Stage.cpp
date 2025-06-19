#include "Stage.h"

using namespace KamataEngine;

Stage::Stage() {}

Stage::~Stage() {
	delete iwayamaSprite_;
	delete iwayamaRvSprite_;
}

void Stage::Initialise() {
	iwayamaTexture_ = TextureManager::Load("iwayama.png");
	iwayamaRvTexture_ = TextureManager::Load("iwayama_rv.png");

	iwayamaSprite_ = Sprite::Create(iwayamaTexture_, {xPos[0], 0.0f});
	iwayamaRvSprite_ = Sprite::Create(iwayamaRvTexture_, {xPos[1], 0.0f});
}

void Stage::Update() {
	for (int i = 0; i < 2; ++i) {
		xPos[i] += moveSpeed_;

		if (xPos[i] <= -1280.0f) {
			xPos[i] += 1280.0f;
		}
	}

	iwayamaSprite_->SetPosition({xPos[0], 0.0f});
	iwayamaRvSprite_->SetPosition({xPos[1], 0.0f});
}

void Stage::Draw() { 
	iwayamaSprite_->Draw(); 
	iwayamaRvSprite_->Draw();
}
