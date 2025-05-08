#pragma once
#include "KamataEngine.h"

// エフェクト
class Effect {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 scale, KamataEngine::Vector3 rotate);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(KamataEngine::Camera& camera);

private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_ ;

	// モデル
	KamataEngine::Model* model_ = nullptr;

	KamataEngine::Vector3 scale_;
	KamataEngine::Vector3 rotation_;
};