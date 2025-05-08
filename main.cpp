#include <Windows.h>
#include "KamataEngine.h"
using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
KamataEngine::Initialize(L"LE3D_02_ウエノ_ユウキ");

// DirectXCommonのインスタンスの取得
DirectXCommon* dxcommon = DirectXCommon::GetInstance();

//メインループ
while (true) {
	//エンジンの更新
	if (KamataEngine::Update()) {
		break;
	}
	//描画開始
	dxcommon->PreDraw();

	dxcommon->PostDraw();
}
//エンジンの終了処理
KamataEngine::Finalize();

	return 0;
}

