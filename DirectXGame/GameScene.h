#pragma once
#include "KamataEngine.h"
#include "Particle.h"

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

private:


	// パーティクル3Dモデルデータ
	KamataEngine::Model* modelParticle_ = nullptr;

	// カメラ
	KamataEngine::Camera camera_;

	// パーティクル
	std::list<Particle*> particles_;
};