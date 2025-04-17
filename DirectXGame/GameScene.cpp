#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() { 
	delete modelParticle_;
	delete particle_;
}

void GameScene::Initialize() {
	modelParticle_ = Model::CreateSphere(4, 4); 
	camera_.Initialize();

	// パーティクルの生成
	particle_ = new Particle();
	// パーティクルの初期化
	particle_->Initialize(modelParticle_);
}

void GameScene::Update() {
	// パーティクルの更新
	particle_->Update();
}

void GameScene::Draw() {
	// DirectXCommon インスタンスの取得
	KamataEngine::DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// パーティクルの描画
	particle_->Draw(camera_);

	// 3Dモデル描画後処理
	Model::PostDraw();
}
