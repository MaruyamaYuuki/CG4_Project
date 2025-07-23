#include "NumberCount.h"

using namespace KamataEngine;

NumberCount::~NumberCount() {
	for (int i = 0; i < 5; i++) {
		delete sprite_[i];
	}
}

void NumberCount::Initialize(Input* input) {
	input_ = input;

	textureHandle_ = TextureManager::Load("number.png");

	for (int i = 0; i < 5; i++) {
		sprite_[i] = Sprite::Create(textureHandle_, {100.0f + size.x * i, 5});
		sprite_[i]->SetSize(size);
	}

	countStart_ = false;
}

void NumberCount::Update() {
	if (input_->TriggerKey(DIK_SPACE)) {
		if (!countStart_) {
            countStart_ = true;
		} else {
            countStart_ = false;
		}
		
	}

	if (number < 10000 && countStart_) {
		number++;
	}

	int32_t tempNumber = number; // オリジナルのnumberを壊さない

	int32_t digit = 10000; // 5桁表示なら10000

	for (int i = 0; i < 5; i++) {
		int nowNumber = tempNumber / digit;
		sprite_[i]->SetTextureRect({size.x * nowNumber, 0}, size);
		tempNumber %= digit;
		digit /= 10;
	}
}


void NumberCount::Draw() {
	for (int i = 0; i < 5; i++) {
		sprite_[i]->Draw();
	}
}
