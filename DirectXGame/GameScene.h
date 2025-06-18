#pragma once
#include "KamataEngine.h"
#include "Particle.h"
#include "Effect.h"
#include "ModelPrim.h"

// ゲームシーン
class GameScene {
public:
	GameScene();

	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

    /// <summary>
    /// パーティクル発生
    /// </summary>
	/// <param name="position">位置</param>
	void ParticleBorn(KamataEngine::Vector3 position);

    /// <summary>
    /// エフェクト発生
    /// </summary>
	/// <param name="position">位置</param>
	void EffectBorn(KamataEngine::Vector3 position);

	bool IsFinished() { return isFinished_; }

private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTranform_;

	// パーティクル3Dモデルデータ
	KamataEngine::Model* modelParticle_ = nullptr;
	// エフェクトの3Dモデルデータ
	KamataEngine::Model* modelEffect_ = nullptr;

	// カメラ
	KamataEngine::Camera camera_;

	// パーティクル
	std::list<Particle*> particles_;
	// エフェクト
	std::list<Effect*> effects_;

	// モデル
	KamataEngine::ModelPrim* cubeModelPrim_ = nullptr;
	// テクスチャハンドル
	uint32_t UVCheckerTexture_ = 0;

	KamataEngine::DebugCamera* debugCamera_ = nullptr;

	bool isDebugCameraActive_ = false;

	KamataEngine::Input* input = nullptr;

	bool isFinished_ = false;
};