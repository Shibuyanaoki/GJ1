#pragma once
#include "Vector2.h"
#include <Novice.h>
#include<stdlib.h>
#include<time.h>
class Enemy {
public:
	void Inisialize();

	void Updata();

	void Draw();

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
		{320,540},
		{640,540},
		{960,540},
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

};