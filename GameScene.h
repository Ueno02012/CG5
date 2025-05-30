#pragma once
#include"KamataEngine.h"
#include "Particle.h"

class GameScene {
	
public:
	//コンストラクタ
	GameScene();

	//デストラクタ
	~GameScene();

	void Initialize();
	void Update();
	void Draw();
	/// <summary>
	/// パーティクル発生
	/// </summary>
	void ParticleBorn(KamataEngine::Vector3 position);

	// パーティクル
	std::list<Particle*> particles_;

private:
	//　パーティクルモデル
	KamataEngine::Model* modelParticle_ = nullptr;
	KamataEngine::WorldTransform worldTransform_;
	// カメラ
	KamataEngine::Camera camera_;

};
