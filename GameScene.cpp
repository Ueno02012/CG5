#include "GameScene.h"

GameScene::GameScene() {}

GameScene::~GameScene() { 
	delete modelParticle_;
}

void GameScene::Initialize() { 
	
	modelParticle_ = Model::CreateSphere(4, 4);
	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	camera_.Initialize();

	for (int i = 0; i < 150; i++) {
		Particle* particle = new Particle();
		// 位置
		Vector3 position = {0.5f * i, 0.0f, 0.0f};
		// 初期化
		particle->Initialize(modelParticle_, position);
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
