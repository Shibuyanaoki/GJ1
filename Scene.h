#pragma once
enum class Scene {
	TITLE,	//タイトル
	SELECT,	//ステージ選択
	GAME,	//ゲームシーン
	GAMECLEAR,	//クリア
	GAMEOVER,	//ゲームオーバー
};

enum class Phase {
	CHOOSE,	//弾の配置選択
	FIRE,	//敵の弾と自分の弾の処理
};