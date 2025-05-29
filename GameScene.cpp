#include "GameScene.h"
#include <random>
std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

GameScene::GameScene() {}

GameScene::~GameScene() { 
	delete modelParticle_;
	// パーティクルの開放
	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();
}

void GameScene::Initialize() { 
	
	modelParticle_ = Model::CreateSphere(4, 4);
	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	camera_.Initialize();

	for (int i = 0; i < 150; i++) {
		Particle* particle = new Particle();
		// 位置
		Vector3 position = {0.0f, 0.0f, 0.0f};
		// 移動量
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};

		// 初期化
		particle->Initialize(modelParticle_, position,velocity);
		//　リストに追加
		particles_.push_back(particle);

	}

	
}

void GameScene::Update() { 
	for (Particle* particle : particles_) {
		particle->Update(); 

	}
}

void GameScene::Draw() { 
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	Model::PreDraw(dxCommon->GetCommandList());
	for (Particle* particle : particles_) {
		particle->Draw(camera_);
	}
	Model::PostDraw();


}
