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
	ModelPrim::StaticFinalize();
	delete cubeModelPrim_;
	delete debugCamera_;
}


void GameScene::Initialize() {
	input = Input::GetInstance();

	worldTranform_.Initialize();

	modelParticle_ = Model::CreateSphere(4, 4); 
	modelEffect_ = Model::CreateFromOBJ("effect", true);
	camera_.Initialize();
	

	ModelPrim::StaticInitialize();

	UVCheckerTexture_ = TextureManager::Load("uvChecker.png");

	//cubeModelPrim_ = new ModelPrim();
	cubeModelPrim_ = ModelPrim::CreateRing(5);

	 
	debugCamera_ = new DebugCamera(1280, 720);
}

void GameScene::Update() {

	if (input->TriggerKey(DIK_D)) {
		if (!isDebugCameraActive_) {
			isDebugCameraActive_ = true;
		} else {
			isDebugCameraActive_ = false;
		}
	}

    if (isDebugCameraActive_) {
		// デバッグカメラの更新
		debugCamera_->Update();
		camera_.matView = debugCamera_->GetCamera().matView;
		camera_.matProjection = debugCamera_->GetCamera().matProjection;
		// ビュープロジェクション行列の転送
		camera_.TransferMatrix();
	} else {
		camera_.TransferMatrix();
	}
}

void GameScene::Draw() {
	// DirectXCommon インスタンスの取得
	KamataEngine::DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	ModelPrim::PreDraw(dxCommon->GetCommandList());

	cubeModelPrim_->Draw(worldTranform_, camera_, UVCheckerTexture_);

	// 3Dモデル描画後処理
	ModelPrim::PostDraw();
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
