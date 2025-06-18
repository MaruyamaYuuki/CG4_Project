#pragma once
#include "KamataEngine.h"

class Stage {
public:
	Stage();

	~Stage();

	void Initialise();

	void Update();

	void Draw();

	bool IsFinished() { return isFinished; }

private:
	KamataEngine::Input* input = nullptr;

	bool isFinished = false;
};
