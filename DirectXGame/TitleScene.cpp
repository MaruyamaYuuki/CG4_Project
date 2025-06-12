#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::TitleScene() {}
TitleScene::~TitleScene() {
	delete titleSprite_;
	delete startGuideSprite_;
}

void TitleScene::Initialize() {
	input_ = Input::GetInstance(); 

	worldTrabsform_.Initialize();

	titleTexture_ = TextureManager::Load("title.png");
	startGuideTexture_ = TextureManager::Load("start.png");

	titleSprite_ = Sprite::Create(titleTexture_, {0.0f, 0.0f});
	startGuideSprite_ = Sprite::Create(startGuideTexture_, {0.0f, 10.0f});
}

void TitleScene::Update() {
	if (input_->TriggerKey(DIK_SPACE)) {
		finished_ = true;
	}
}

void TitleScene::Draw() {
	titleSprite_->Draw();
	startGuideSprite_->Draw();
}
