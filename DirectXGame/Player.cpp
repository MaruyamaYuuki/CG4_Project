#include "Player.h"
#include <numbers>

using namespace KamataEngine;
using namespace KamataEngine::MathUtility;

void Player::Initialize(KamataEngine::Model* model, KamataEngine::Input* input) {
	assert(model);
	model_ = model;

	input_ = input;

	worldTransform_.Initialize();
	worldTransform_.rotation_.y += float(std::numbers::pi) / 2.0f;
	worldTransform_.translation_.z -= 30;
}

void Player::Update() {
	if (input_->PushKey(DIK_W)) {
		worldTransform_.translation_.y += velocity_.y;
	}
	if (input_->PushKey(DIK_S)) {
		worldTransform_.translation_.y -= velocity_.y;
	}
	if (input_->PushKey(DIK_A)) {
		worldTransform_.translation_.x -= velocity_.x;
	}
	if (input_->PushKey(DIK_D)) {
		worldTransform_.translation_.x += velocity_.x;
	}

	worldTransform_.UpdateMatrix();
}

void Player::Draw(KamataEngine::Camera &camera) { 
	model_->Draw(worldTransform_, camera); 
}
