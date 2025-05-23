#pragma once
#include"KamataEngine.h"
#include "Particle.h"
using namespace KamataEngine;
class GameScene {
	
public:
	//コンストラクタ
	GameScene();

	//デストラクタ
	~GameScene();

	void Initialize();
	void Update();
	void Draw();

	// パーティクル
	Particle* particle_ = nullptr;

private:
	//　パーティクルモデル
	Model* modelParticle_ = nullptr;
	WorldTransform worldTransform_;
	// カメラ
	Camera camera_;

};
