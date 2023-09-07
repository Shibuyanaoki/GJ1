#include <Novice.h>
#include "Vector2.h"
#include<stdlib.h>
#include<time.h>


const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector2 player[3] = {
		{0,0},
		{0,0},
		{0,0},
	};

	Vector2 enemy[3] = {
		{320,50},
		{640,50},
		{960,50},
	};

	Vector2 bullet[3] = {
		{0,0},
		{0,0},
		{0,0},
	};

	Vector2 location[3] = {
		{320,540},
		{640,540},
		{960,540},
	};

	enum Phase {
		CHOOSE,
		FIRE,
	};

	int phase = CHOOSE;

	int locationCount[3] = {};
	int enemyLocationCount[3] = {};

	//int timer = 60;

	int selectFlag = 0;
	int selectCount = 0;

	int count[3] = {};
	int countTrue = 0;

	int enemyCount = 0;

	int damageCount = 0;
	int damageFlag = 0;

	int sceneCount = 0;

	// シード値設定、用はrand関数から出てくる値を固定にしないようにする処理
	//int currenTime = time(nullptr);
	srand((int)time(NULL));

	int temp = 0;	// 値を入れ替えるための一時的な変数

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (phase) {
		case CHOOSE:

			if (enemyCount == 0) {
				while (countTrue < 3) {
					if (countTrue == 0) {
						count[0] = rand() % 3;
						countTrue += 1;
					}

					if (countTrue == 1) {
						temp = rand() % 3;
						if (temp != count[0]) {
							count[1] = temp;
							countTrue += 1;
						}
					}

					if (countTrue == 2) {
						temp = rand() % 3;
						if (temp != count[0] && temp != count[1]) {
							count[2] = temp;
							countTrue += 1;
						}

					}

				}

				if (countTrue == 3) {
					for (int i = 0; i < 3; i++) {

						enemy[i].x = location[count[i]].x;

						enemyLocationCount[i] = count[i];
					}

					enemyCount = 1;
				}
			}

			if (enemyCount == 1) {

				if (keys[DIK_R] && preKeys[DIK_R] == 0) {
					selectCount = 0;
					for (int i = 0; i < 3; i++) {
						locationCount[i] = 0;
						player[i].x = 0;
					}

				}

				if (selectCount == 0 && selectFlag == 0) {

					if (keys[DIK_1] && preKeys[DIK_1] == 0 && selectFlag == 0) {
						player[0].x = location[0].x;
						locationCount[0] = 0;
						selectFlag = 1;
					}

					if (keys[DIK_2] && preKeys[DIK_2] == 0 && selectFlag == 0) {
						player[0].x = location[1].x;
						locationCount[0] = 1;
						selectFlag = 1;
					}

					if (keys[DIK_3] && preKeys[DIK_3] == 0 && selectFlag == 0) {
						player[0].x = location[2].x;
						locationCount[0] = 2;
						selectFlag = 1;
					}

				}

				if (selectCount == 1 && selectFlag == 0) {

					if (keys[DIK_1] && preKeys[DIK_1] == 0 && locationCount[0] != 0) {
						player[1].x = location[0].x;
						locationCount[1] = 0;
						selectFlag = 1;
					}

					if (keys[DIK_2] && preKeys[DIK_2] == 0 && locationCount[0] != 1) {
						player[1].x = location[1].x;
						locationCount[1] = 1;
						selectFlag = 1;
					}

					if (keys[DIK_3] && preKeys[DIK_3] == 0 && locationCount[0] != 2) {
						player[1].x = location[2].x;
						locationCount[1] = 2;
						selectFlag = 1;
					}

				}

				if (selectCount == 2 && selectFlag == 0) {

					if (keys[DIK_1] && preKeys[DIK_1] == 0 && locationCount[0] != 0 && locationCount[1] != 0) {
						player[2].x = location[0].x;
						locationCount[2] = 0;
						selectFlag = 1;
					}

					if (keys[DIK_2] && preKeys[DIK_2] == 0 && locationCount[0] != 1 && locationCount[1] != 1) {
						player[2].x = location[1].x;
						locationCount[2] = 1;
						selectFlag = 1;
					}

					if (keys[DIK_3] && preKeys[DIK_3] == 0 && locationCount[0] != 2 && locationCount[1] != 2) {
						player[2].x = location[2].x;
						locationCount[2] = 2;
						selectFlag = 1;
					}

				}

				if (selectFlag == 1) {
					selectCount += 1;
					selectFlag = 0;
				}

			}
			if (selectCount == 3) {



				phase = FIRE;
			}

			break;

		case FIRE:

			for (int i = 0; i < 3; i++) {

				if (i != 3) {

					if (locationCount[0] == enemyLocationCount[0] && i == 0) {
						damageFlag = 1;
					}

					if (locationCount[1] == enemyLocationCount[1] && i == 1) {
						damageFlag = 1;
					}

					if (locationCount[2] == enemyLocationCount[2] && i == 2) {
						damageFlag = 1;
					}

					if (damageFlag == 1 ) {
						damageCount += 1;
						sceneCount += 1;
						damageFlag = 0;
					}



				}
			}


			if (sceneCount == 3) {
				selectCount = 0;
				countTrue = 0;
				enemyCount = 0;
				for (int i = 0; i < 3; i++) {
					locationCount[i] = 0;
					player[i].x = 0;
				}

				phase = CHOOSE;

			}


			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///


		for (int i = 0; i < 3; i++) {
			Novice::DrawEllipse((int)player[0].x, (int)player[0].y, 32, 32, 0.0f, WHITE, kFillModeSolid);
			Novice::DrawEllipse((int)player[1].x, (int)player[1].y, 32, 32, 0.0f, RED, kFillModeSolid);
			Novice::DrawEllipse((int)player[2].x, (int)player[2].y, 32, 32, 0.0f, GREEN, kFillModeSolid);
		}


		if (enemyCount == 1) {
			for (int i = 0; i < 3; i++) {
				Novice::DrawEllipse((int)enemy[0].x, (int)enemy[0].y, 32, 32, 0.0f, WHITE, kFillModeSolid);
				Novice::DrawEllipse((int)enemy[1].x, (int)enemy[1].y, 32, 32, 0.0f, RED, kFillModeSolid);
				Novice::DrawEllipse((int)enemy[2].x, (int)enemy[2].y, 32, 32, 0.0f, GREEN, kFillModeSolid);
			}
		}

		Novice::ScreenPrintf(0, 20 * 0, "player[0]%f", player[0].x);
		Novice::ScreenPrintf(0, 20 * 1, "player[1]%f", player[1].x);
		Novice::ScreenPrintf(0, 20 * 2, "player[2]%f", player[2].x);
		Novice::ScreenPrintf(0, 20 * 3, "enemy[0]%f", enemy[0].x);
		Novice::ScreenPrintf(0, 20 * 4, "enemy[1]%f", enemy[1].x);
		Novice::ScreenPrintf(0, 20 * 5, "enemy[2]%f", enemy[2].x);
		Novice::ScreenPrintf(0, 20 * 6, "%d", selectCount);
		Novice::ScreenPrintf(0, 20 * 7, "%d", selectFlag);
		Novice::ScreenPrintf(0, 20 * 8, "%d", count[0]);
		Novice::ScreenPrintf(0, 20 * 9, "%d", count[1]);
		Novice::ScreenPrintf(0, 20 * 10, "%d", count[2]);
		Novice::ScreenPrintf(0, 20 * 11, "countTrue%d", countTrue);
		Novice::ScreenPrintf(0, 20 * 12, "%d", enemyCount);
		Novice::ScreenPrintf(0, 20 * 13, "damage%d", damageCount);
		Novice::ScreenPrintf(0, 20 * 14, "phase%d", sceneCount);



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
