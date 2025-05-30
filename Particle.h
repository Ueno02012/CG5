#pragma once
#include <KamataEngine.h>


class Particle {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="position">位置</param>
	/// <param name="velocity">移動量</param>
	void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 position, KamataEngine::Vector3 velocity);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="camera">カメラ</param>
	void Draw(KamataEngine::Camera& camera);
	bool IsFinished() { return isFinished_; }


private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model* model_ = nullptr;
	// 色変更
	KamataEngine::ObjectColor objectColor_;
	// 色の数値
	KamataEngine::Vector4 color_;
	// 移動量
	KamataEngine::Vector3 velocity_;

	// 終了フラグ
	bool isFinished_ = false;
	//　経過時間カウント
	float counter_ = 0.0f;
	// 存在時間
	const float kDuration = 1.0f;

};
