#include "GraphDisplay.h"

using namespace KamataEngine;

GraphDisplay::~GraphDisplay() {
	delete redGraphSprite_;
	delete greenGraphSprite_;
}

void GraphDisplay::initialize(KamataEngine::Input* input) {
	input_ = input;

	redGraphTextureHandle_ = TextureManager::Load("graph_red.png");
	greenGraphTexturehandle_ = TextureManager::Load("graph_green.png");

	redGraphSprite_ = Sprite::Create(redGraphTextureHandle_, {100.0f, 100.0f});
	greenGraphSprite_ = Sprite::Create(greenGraphTexturehandle_, {100.0f, 100.0f});

	redGraphSprite_->SetSize({300.0f, 48.0f});
	redGraphSprite_->SetColor({1.0f, 1.0f, 1.0f, 0.8f});
	greenGraphSprite_->SetSize({300.0f, 48.0f});
	greenGraphSprite_->SetColor({1.0f, 1.0f, 1.0f, 0.8f});
}

void GraphDisplay::Update() {
	if (input_->TriggerKey(DIK_RETURN)) {
		if (!isStart_) {
			isStart_ = true;
		} else {
			isStart_ = false;
		}
	}
	if (maxXSize > 0 && isStart_){
		maxXSize -= 0.5f;
	}

	greenGraphSprite_->SetSize({maxXSize, 48.0f});
}

void GraphDisplay::Draw() {
	redGraphSprite_->Draw();
	greenGraphSprite_->Draw();
}
