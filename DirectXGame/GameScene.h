#pragma once
#include "KamataEngine.h"
#include "Particle.h"
#include "Effect.h"

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

private:

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
};