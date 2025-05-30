#include "GameScene.h"
using namespace KamataEngine;

#include <random>


GameScene::GameScene() {}
GameScene::~GameScene() {


	// エフェクトの解放
	for (Effect* effect : effectes_) {
		delete effect;
		effect = nullptr;
	}

	delete modelEffect_;
	modelEffect_ = nullptr;
}

void GameScene::Initialize() {
	// DirectXCommonインスタンスの取得
	dxCommon_ = DirectXCommon::GetInstance();
	// Inputインスタンスの取得
	input_ = Input::GetInstance();
	// Audioインスタンスの取得
	audio_ = Audio::GetInstance();

	modelEffect_ = Model::CreateFromOBJ("Plane");

	// エフェクトの生成
	for (int i = 0; i < 10; i++) {
		// 生成
		Effect* effect = new Effect();
		// 位置
		Vector3 pos = Vector3(0.0f, 0.0f, 0.0f);
		// 初期化
		effect->Initialize(modelEffect_, pos);
		// リストに追加
		effectes_.push_back(effect);
	}

	// カメラの初期化
	camera_.Initialize();
}

void GameScene::Update() {

	for (Effect* effect : effectes_) {
		effect->Update();
	}
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	for (Effect* effect : effectes_) {
		effect->Draw(camera_);
	}

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}