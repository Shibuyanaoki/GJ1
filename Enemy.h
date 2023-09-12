#pragma once
#include "Vector2.h"
#include <Novice.h>
#include<stdlib.h>
#include<time.h>
class Enemy {
public:
	void Initialize();

	void Update();

	void Draw();

	void Flag();

	int GetLocationCount(int index) {
		return locationCount[index];
	}

	void Damage();

	void Reset();

private:
	//敵がどこに設置されたか確認する変数
	int locationCount[3] = {};

	int HP = 6;

	Vector2 enemy[3] = {
		{320,50},
		{640,50},
		{960,50},

	};
	Vector2 location[3] = {
		{285,90},
		{590,50},
		{915,100},
	};

	enum Phase {
		CHOOSE,
		FIRE,
	};

	int phase = CHOOSE;
	//敵の配置場所を決める変数
	int count[3] = {};
	//場所がかぶっていないかの確認用変数
	int enemyCount = 0;
	// 値を入れ替えるための一時的な変数
	int temp = 0;
	int flag = 0;
	int timer = 0;

	int ika = Novice::LoadTexture("./ika.png");
	int ika2 = Novice::LoadTexture("./ika2.png");

	int rock = Novice::LoadTexture("./bulletG.png");
	int paper = Novice::LoadTexture("./bulletP.png");
	int scissors = Novice::LoadTexture("./bulletC.png");

};