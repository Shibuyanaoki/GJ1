#include <Novice.h>
#include "Vector2.h"
#include "GameScene.h"
#include "Scene.h"
#include "GamePlay.h"
#include "Input.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Scene scene = Scene::TITLE;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Input* input = Input::GetInstance();

	GamePlay* gamePlay = new GamePlay;


	gamePlay->Initialize();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		input->Update();
		///
		/// ↓更新処理ここから
		///

		switch (scene)
		{
		case Scene::TITLE:


			break;

		case Scene::SELECT:

			break;

		case Scene::GAME:


			break;

		case Scene::GAMECLEAR:

			break;

		case Scene::GAMEOVER:

			break;


		}


		gamePlay->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		gamePlay->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
