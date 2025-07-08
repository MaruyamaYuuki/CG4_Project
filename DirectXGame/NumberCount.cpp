#include "NumberCount.h"

using namespace KamataEngine;

NumberCount::~NumberCount() { 

}

void NumberCount::Initialize() {
	numberTextureHandle_ = TextureManager::Load("number.png");

	for (int i = 0; i < 5; i++) {
		numberSprite_[i] = Sprite::Create(numberTextureHandle_, {100.0f + size.x * i, 5});
		numberSprite_[i]->SetSize(size);
	}
}

void NumberCount::Update() {}

void NumberCount::Draw() {}
