#pragma once
#include <KamataEngine.h>
using namespace KamataEngine;


class Particle {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model* model);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="camera">カメラ</param>
	void Draw(Camera& camera);

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// 色変更
	ObjectColor objectColor_;
	// 色の数値
	Vector4 color_;

};
