#include "GameScene.h"
#include <random>
#include<numbers>

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);
std::uniform_real_distribution<float> scaleYDist(2.0f, 4.0f);
std::uniform_real_distribution<float> rotZDist(0.0f, 3.14f);
std::uniform_real_distribution<float> colorDist(0.0f, 1.0f);

using namespace KamataEngine;
using namespace MathUtility;

GameScene::GameScene() {}

GameScene::~GameScene() { 
	delete modelParticle_;
	delete modelEffect_;
	/*	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();*/
	for (Effect* effect : effects_) {
		delete effect;
	}
	effects_.clear();
}


void GameScene::Initialize() {
	modelParticle_ = Model::CreateSphere(4, 4); 
	modelEffect_ = Model::CreateFromOBJ("effect", true);
	camera_.Initialize();

	// 乱数の初期化
	srand((unsigned)time(NULL));


}

void GameScene::Update() {
	/*	// 確率で発生
	if (rand() % 20 == 0) {
       	// 発生位置は乱数
    	Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};

    	// パーティクル発生
    	ParticleBorn(position);
	}

	// パーティクルの更新
	for (Particle* particle : particles_) {
		particle->Update();
	}
	// 終了フラグの立ったパーティクルを削除
	particles_.remove_if([](Particle* particle) {
		if (particle->IsFinished()) {
			delete particle;
			return true;
		}
		return false;
	});*/

	// 確率で発生
	if (rand() % 5 == 0) {
		// 発生位置は乱数
		Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};
		// エフェクト発生
		EffectBorn(position);
	}

	// エフェクトの更新
	for (Effect* effect : effects_) {
		effect->Update();
	}
	// 終了フラグの立ったエフェクトを削除
	effects_.remove_if([](Effect* effect) {
		if (effect->IsFinished()) {
			delete effect;
			return true;
		}
		return false;
	});
}

void GameScene::Draw() {
	// DirectXCommon インスタンスの取得
	KamataEngine::DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// パーティクルの描画
	//for (Particle* particle : particles_) {
	//	particle->Draw(camera_);
	//}

	// エフェクトの描画
	for (Effect* effect : effects_) {
		effect->Draw(camera_);
	}

	// 3Dモデル描画後処理
	Model::PostDraw();
}

void GameScene::ParticleBorn(Vector3 position) {
	for (int i = 0; i < 150; i++) {
		// 生成
		Particle* particle = new Particle();

		// 移動量
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;

		// 初期化
		particle->Initialize(modelParticle_, position, velocity);

		// リストに追加
		particles_.push_back(particle);
	}
}

void GameScene::EffectBorn(Vector3 position) {
	int effectCount = 10;

		// 色
		Vector4 color = {colorDist(randomEngine), colorDist(randomEngine), colorDist(randomEngine), 1};

	for (int i = 0; i < effectCount; i++) {
		// 生成
		Effect* effect = new Effect();

		// 放射状の基準角度
		float baseAngle = (360.0f / effectCount) * i;

		// ランダムなオフセットを加える
		float finalAngle = baseAngle + rotZDist(randomEngine);

		// ラジアンに変換
		float angleRad = float(finalAngle * std::numbers::pi / 180.0f);

		// サイズ
		Vector3 scale = {0.3f, scaleYDist(randomEngine), 1.0f};
		// 角度
		Vector3 rotation = {0.0f, 0.0f, angleRad};

		// 初期化
		effect->Initialize(modelEffect_, scale, rotation, position, color);
		// リストに追加
		effects_.push_back(effect);
	}
}
