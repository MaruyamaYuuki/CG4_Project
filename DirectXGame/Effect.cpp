#include "Effect.h"

using namespace KamataEngine;

void Effect::Initialize(KamataEngine::Model* model, KamataEngine::Vector3 scale, KamataEngine::Vector3 rotate) {
	// NULLポインタチェック
	assert(model);
	model_ = model;

	scale_ = scale;
	rotation_ = rotate;

	worldTransform_.Initialize();
}

void Effect::Update() { 

	worldTransform_.scale_ = scale_;
	worldTransform_.rotation_ = rotation_;

	worldTransform_.UpdateMatrix(); 
}

void Effect::Draw(KamataEngine::Camera& camera) { 
	model_->Draw(worldTransform_, camera); 
}
