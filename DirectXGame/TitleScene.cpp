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

	titleSprite_ = Sprite::Create(titleTexture_, {300.0f, 200.0f});
	startGuideSprite_ = Sprite::Create(startGuideTexture_, {380.0f, 450.0f});
}

void TitleScene::Update() {
	if (input_->TriggerKey(DIK_SPACE)) {
		finished_ = true;
	}

	// タイトルを漂わせる
	waveTime_ += 0.05f;
	float offsetY = std::sin(waveTime_) * 10.0f; // 振幅10
	titleSprite_->SetPosition({300.0f, 200.0f + offsetY});

	// キーガイドをフェードイン・アウトさせる
	blinkTime_ += 0.05f;
	float alpha = (std::sin(blinkTime_) + 1.0f) / 2.0f;
	startGuideSprite_->SetColor({1.0f, 1.0f, 1.0f, alpha});
}

void TitleScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());
	titleSprite_->Draw();
	startGuideSprite_->Draw();
	Sprite::PostDraw();
}
