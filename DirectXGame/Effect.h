#pragma once
#include "KamataEngine.h"

// エフェクト
class Effect {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 scale, KamataEngine::Vector3 rotate, KamataEngine::Vector3 position, KamataEngine::Vector4 color);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(KamataEngine::Camera& camera);

	// デスフラグのgetter
	bool IsFinished() { return isFinished_; }

private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_ ;

	// モデル
	KamataEngine::Model* model_ = nullptr;

	// 色変更オブジェクト
	KamataEngine::ObjectColor objectColor_;
	// 色の数値
	KamataEngine::Vector4 color_;

	// 終了フラグ
	bool isFinished_ = false;
	// 経過時間カウント
	float counter_ = false;
	// 存続時間（消滅までの時間）<秒>
	const float kDuration = 1.0f;
};